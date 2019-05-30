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
	PORTB |= (1 << PB3); PORTB &= ~(1 << PB2); // Motor Direction.
	PORTD |= (1 << PD2); PORTD &= ~(1 << PD1); // Motor Direction.
	OCR0A = speed;
	OCR0B = speed;
}

void Backward(uint8_t speed) //Function for moving backward. Speed : 0 ~ 255.
{
	PORTB |= (1 << PB2); PORTB &= ~(1 << PB3); // Motor Direction.
	PORTD |= (1 << PD1); PORTD &= ~(1 << PD2); // Motor Direction.
	OCR0A = speed;
	OCR0B = speed;
}

void Left(uint8_t speed) // Function for turning left. Speed : 0 ~ 255.
{
	PORTB |= (1 << PB3); PORTB &= ~(1 << PB2); // Motor Direction.
	PORTD |= (1 << PD1); PORTD &= ~(1 << PD2); // Motor Direction.
	OCR0A = speed;
	OCR0B = speed;	
}

void Right(uint8_t speed) // Function for turninng right. Speed : 0 ~ 255.
{
	PORTB |= (1 << PB2); PORTB &= ~(1 << PB3); // Motor Direction.
	PORTD |= (1 << PD2); PORTD &= ~(1 << PD1); // Motor Direction.
	OCR0A = speed;
	OCR0B = speed;
}
