#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

uint8_t blink_led;

ISR(TIMER3_OVF_vect) {

	TCNT3 = 0xffff-7812; // Every 1 second
	blink_led = !blink_led;

	if(blink_led == 0) {
			PORTD = 0b01000000;
		}

else {PORTD = 0b00000000;
		}
	}

int main() {

	DDRD = 0b01000000; // PD6 OUT for LED
	TCCR3A = 0b00000000; // Normal
	TCCR3B = 0b00000101; //prescaler 1024
	TIMSK3 = 0b00000001;
	TCNT3 = 0xffff-7812; // Every 1 second
	sei(); //Interrupt Enable
	while(1) {}
	return 0;
	
	}
