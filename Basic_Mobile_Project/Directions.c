//------------------------------------------------------------------------
// File    : Directions.c
// Author  : Randy Lee
// Written : 27 May 2019
// 
// Code that includes functions related to directions
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

void Start()
{
	PORTB = 0b10000000; // Turn on the left motor.
	PORTD = 0b00000001; // Turn on the right motor.
}

void Stop()
{
	PORTB = 0b10001100; // Stop left motor.
	PORTD = 0b00000111; // Stop right motor.
}

void Forward(uint8_t speed) //Function for moving forward. Speed : 0 ~ 255.
{
	PORTB |= (1 << PB2); PORTB &= ~(1 << PB3); // Motor Direction.
	PORTD |= (1 << PD1); PORTD &= ~(1 << PD2); // Motor Direction.
	OCR0A = speed;
	OCR0B = speed;
}

void Backward(uint8_t speed) //Function for moving backward. Speed : 0 ~ 255.
{
	PORTB &= ~(1 << PB2); PORTB |= (1 << PB3); // Motor Direction.
	PORTD &= ~(1 << PD1); PORTD |= (1 << PD2); // Motor Direction.
	OCR0A = speed;
	OCR0B = speed;
}

void Left(uint8_t speed) // Function for turning left. Speed : 0 ~ 255.
{
	PORTB &= ~(1 << PB2); PORTB |= (1 << PB3); // Motor Direction.
	PORTD |= (1 << PD1); PORTD &= ~(1 << PD2); // Motor Direction.
	OCR0A = speed;
	OCR0B = speed;	
}

void Right(uint8_t speed) // Function for turninng right. Speed : 0 ~ 255.
{
	PORTB |= (1 << PB2); PORTB &= ~(1 << PB3); // Motor Direction.
	PORTD &= ~(1 << PD1); PORTD |= (1 << PD2); // Motor Direction.
	OCR0A = speed;
	OCR0B = speed;
}
