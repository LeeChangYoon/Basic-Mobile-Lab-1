//------------------------------------------------------------------------
// File    : Main.c
// Author  : Randy Lee
// Written : 27 May 2019
// 
// Main code that includes main funcion
//
// Copyright (C) 2019 Randy Lee
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of 
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU 
// General Public License for more details.
//
// You should have received a copy of the GNU General Public License 
// along with this program; if not, write to the Free Software Foundation
// Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
//------------------------------------------------------------------------

#include "Global.h"
#include "Sound.h"

unit8_t blink_led; // For time/counter interrup testing.

ISR(TIMER_OVF_vect) 		// Test for time/counter interrupt.
{
	TCNT3 = 0ffff - 60535;  // Every 0.1 second

	if (blink_led == 0)
	{
		PORTD = 0b00000000;
	}
	else
	{
		PORTD = 0b01000000;
		_delay_ms(1000);
		blink_led = 0;
	}
}

int main()
{
	DDRB = 0b10101100; 		// PB7, PB3, PB2, PB5 : OUTPUT
	DDRD = 0b00000111; 		// PD2, PD1, PD0 	 : OUTPUT
	DDRF = 0x00;       		// PF0, PF1	         : Interrupt (switches)
	DDRD = 0b01000000; 		// PD6 OUT for LED

	TCCR0A = 0b11110001;    // PWM, Phase and Frequency Correct
	TCCR0B = 0b00000100;    // Prescaler 256
	
	TCCR3A = 0b00000000;    // Normal
	TCCR3B = 0b00000101;    // Prescaler 1024
	TIMSK3 = 0b00000001;
	TCNT3 = 0xffff - 60535; // Every 0.1 second
	
	blink_led = 0;
	int count = 0;

	Start();	
	
	sei();
	while(1)
	{	
		PINF = 0b00000011;

		///////////////////////// When both buttons are pushed. /////////////////////////
		if (((~PINF & 0b00000001) == 0b00000000) && ((~PINF & 0b00000010) == 0b00000000)) 
		{
			if (count == 0)
			{
				count++; // When both buttons are pushed at the first time, while statement starts.
			}
			
			else
			{
				Backward(100);
				_delay_ms(1000); 
	  		    Right(100);   
				_delay_ms(1000); 
				blink_led++;
			}
		}
		
		///////////////////////// When left button is pushed. ////////////////////////////////
		else if (((~PINF & 0b00000001) == 0b00000001) && ((~PINF & 0b00000010) == 0b00000000)) 
		{ 
		 	Backward(100);
			_delay_ms(1000); 
  		    Right(100);   
			_delay_ms(500);  
			blink_led++;

		}  
		
		////////////////////////// When right button is pushed. //////////////////////////////
		else if (((~PINF & 0b00000001) == 0b00000000) && ((~PINF & 0b00000010) == 0b00000010)) 
		{ 
			Backward(100);       
			_delay_ms(1000); 
			Left(100);          
			_delay_ms(500);  
			blink_led++;
		}
		
		////////////////////////// When buttons are not pushed. ////////////////////////////////
		else
		{
			if (count == 0) 
			{
				Stop(); // Before both buttons are pushed, it does no run the while statement.
			}

			else
			{
				Forward(50);
			}
		}
	}
	return 0;
}
