<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#include "Global.h"

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
					_delay_ms(100);
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
					Backward(100);       
					_delay_ms(1000); 
					Right(100);          
					_delay_ms(500);  
					blink_led++;
				}
				else {
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

=======
=======
>>>>>>> parent of 8962eb5... Add files via upload
#include "Global.h"
#include "Sound.h"

int main()
{
	DDRB = 0b10001100; // PB7, PB3, PB2, PB5 : OUTPUT
	DDRD = 0b00000111; // PD2, PD1, PD0 	 : OUTPUT
	DDRF = 0x00;       // PF0, PF1	         : Interrupt (switches)

	TCCR0A = 0b11110001; // PWM, Phase and Frequency Correct
	TCCR0B = 0b00000100; // prescaler 256

	int count = 0;

	Start();	

	while(1)
	{	
		PINF = 0b00000011;

		if (((~PINF & 0b00000001) == 0b00000000) && ((~PINF & 0b00000010) == 0b00000000)) 
		{
			if (count == 0)
			{
				count++;
			}
			
			else
			{
				Backward(100);
				_delay_ms(1000); 
	  		    Right(100);   
				_delay_ms(1000); 
			}
		}

		else if (((~PINF & 0b00000001) == 0b00000001) && ((~PINF & 0b00000010) == 0b00000000)) 
		{ 
		 	Backward(100);
			_delay_ms(1000); 
  		    Right(100);   
			_delay_ms(500); 
		}  
		
		else if (((~PINF & 0b00000001) == 0b00000000) && ((~PINF & 0b00000010) == 0b00000010)) 
		{ 
			Backward(100);       
			_delay_ms(1000); 
			Left(100);          
			_delay_ms(500); 
		}

		else
		{
			if (count == 0) 
			{
				Stop();
			}

			else
			{
				Forward(50);
=======
#include "Global.h"

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
					_delay_ms(100);
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
					Backward(100);       
					_delay_ms(1000); 
					Right(100);          
					_delay_ms(500);  
					blink_led++;
				}
				else {
					Backward(100);       
					_delay_ms(1000); 
					Right(100);          
					_delay_ms(1000);  
					blink_led++;
				}
>>>>>>> a2c9528c2ca7c84b671a9f8a5cc03cc70a6085b1
			}
		}
	}
	return 0;
}
<<<<<<< HEAD
>>>>>>> parent of e8a17b0... Add files via upload
=======

>>>>>>> a2c9528c2ca7c84b671a9f8a5cc03cc70a6085b1
