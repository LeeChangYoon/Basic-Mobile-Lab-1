//------------------------------------------------------------------------
// File    : Main.c
// Author  : ChangYoon Lee, Yongkwan Park
// Written : 5 May 2019
// 
// Main.c which contains main function.
//
// Copyright (C) 2019 Dankook.Univ
//------------------------------------------------------------------------


#include "Global.h"
#include "Sound.h"


ISR(TIMER3_OVF_vect) // Timer/Counter interrupt which turn led on for 1sec.
{	
	TCNT3 = 0xffff-7812; 		// Every 1 second
	blink_led = !blink_led;

	if(blink_led == 0)
		PORTD |= (1 << PD6);

	else
		PORTD &= ~(1 << PD6);
		
}


int main() 
{

	init();	// Initialize the values of PINs.
	
	while(1) {
		while (EN == 0)	// Before both buttons are clicked.
		{
			if (PINF & (1 << 1))  
			{
				if (PINF & (1 << 0))  // Both buttons are not clicked.
					Stop();
				
				else 
					Stop();			  // Right button is clicked.
			}

			else 
			{
				if (PINF & (1 << 0))  // Left button is clicked.
					Stop();

				else 				  // Both buttons are clicked.
				{
					StartSound();
					Start();
					EN++;
				}
			}
		}


		while (EN != 0) 
		{
			_delay_ms(100);

			if (PINF & (1 << 1)) 
			{
				if (PINF & (1 << 0))  // Both buttons are not clicked.
					Forward(50);

				else 				  // Right button is clicked.
				{
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

			else 
			{
				_delay_ms(100);

				if (PINF & (1 << 0))   // Left button is clicked.
				{
					Stop();
					RightSound(); 
					Backward(100);  
					_delay_ms(1000); 
					Right(100);          
					_delay_ms(500);  
					blink_led++;
				
				}

				else 				  // Both buttons are clicked.
				{
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

