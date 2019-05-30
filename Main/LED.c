#include "Global.h"

uint8_t blink_led;

void LED() {

	DDRD = 0b01000000; // PD6 OUT for LED
	TCCR3A = 0b00000000; // Normal
	TCCR3B = 0b00000101; //prescaler 1024
	TIMSK3 = 0b00000001;
	TCNT3 = 0xffff-7812; // Every 1 second
	sei(); //Interrupt Enable
	
	}
