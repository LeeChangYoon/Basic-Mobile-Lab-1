//------------------------------------------------------------------------
// File    : Initialization.c
// Author  : ChangYoon Lee
// Written : 5 May 2019
// 
// Set init function to short length of the main function.
//
// Copyright (C) 2019 Dankook.Univ
//------------------------------------------------------------------------


#include "Global.h"
#include "Sound.h"

void init() 
{
	DDRB = 0b10101100; 		/*  PB7 --> Left motor enable bit
								PB3 --> Left motor forward bit
								PB2 --> Left motor backward bit

								PB5 --> Buzzer enable bit */

	DDRD = 0b01000111;		/* 	PD0 --> Right motor enable bit
								PD2 --> Right motor forward bit
								PD1 --> Right motor backward bit

								PD6 --> LED bit */

	DDRF = 0b00000000;		/*  PF1 --> Left button
								PF0 --> Right button */
	PORTF = 0b00000011;

	TCCR0A = 0b11110001;    // PWM, Phase and Frequency Correct
	TCCR0B = 0b00000100;    // Prescaler 256

	TCCR1A = 0b10000000; 	// PWM, OC1A On, Phase and Frequency Correct 
	TCCR1B = 0b00010010; 	//prescaler 8

	TCCR3A = 0b00000000;    // Normal
	TCCR3B = 0b00000101;    // Prescaler 1024

	TIMSK3 = 0b00000001;	// Time interrupt enable
	TCNT3 = 0xffff-60535;   // Every 0.1 second
	
	blink_led = 0;			// LED enable signal
	EN = 0;					// Enable signal

	sei();					// Allows interrupt
}	
