#include "Global.h"

ISR(TIMER3_OVF_vect) {

	TCNT3 = 0xffff-7812; // Every 1 second
	blink_led = !blink_led;

	if(blink_led == 0) {
			PORTD |= (1 << PD6);
		}

else{
		PORTD &= ~(1 << PD6);
		}
	}


int main() {

	DDRB = 0b10101100; 	/*  PB7 --> Left motor enable bit
							PB3 --> Left motor forward bit
							PB2 --> Left motor backward bit

							PB5 --> Buzzer enable bit */

	DDRD = 0b01000111;	/* 	PD0 --> Right motor enable bit
							PD2 --> Right motor forward bit
							PD1 --> Right motor backward bit

							PD6 --> LED bit */

	DDRF = 0b00000000;	/*  PF1 --> Left button
							PF0 --> Right button */
	PORTF = 0b00000011;

	TCCR0A = 0b11110001;    // PWM, Phase and Frequency Correct
	TCCR0B = 0b00000100;    // Prescaler 256

	TCCR3A = 0b00000000;    // Normal
	TCCR3B = 0b00000101;    // Prescaler 1024

	TIMSK3 = 0b00000001;	// Time interrupt enable
	TCNT3 = 0xffff - 60535; // Every 0.1 second
	
	blink_led = 0;
	EN = 0;
	
	while(1) {
		while (EN == 0) {
			if (PINF & (1 << 1)) {
				if (PINF & (1 << 0)) {
					Stop();
				}
				else {
					Stop();
				}
			}
			else {
				if (PINF & (1 << 0)) {
					Stop();
				}
				else {
					StartSound();  /// output start sound();
					Start();
					EN++;
				}
			}
		}

		while (EN != 0) {
			_delay_ms(100);
			if (PINF & (1 << 1)) {
				if (PINF & (1 << 0)) {
					Forward(50);
				}
				else {
					Stop();
					_delay_ms(100);
					LeftSound();
					Backward(100);       
					_delay_ms(1000); 
					Left(100);          
					_delay_ms(500);  
					blink_led++;
				}
			}
			else {
				_delay_ms(100);
				if (PINF & (1 << 0)) {
					Stop();
					RightSound(); 
					Backward(100);  
					_delay_ms(1000); 
					Right(100);          
					_delay_ms(500);  
					blink_led++;
				
				}
				else {
					Stop();
					BothSound();
					Backward(100);       
					_delay_ms(1000); 
					Right(100);          
					_delay_ms(1000);  
					blink_led++;
				}
			}
		}
	}
	return 0;
}

