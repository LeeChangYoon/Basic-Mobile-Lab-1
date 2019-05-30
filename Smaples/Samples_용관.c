#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
void Forward(uint8_t speed);
void Backward(uint8_t speed);

//forward function
int main()
	{
	DDRB = 0b10001100; //PB7, PB3 : OUTPUT	
	DDRD = 0b00000111; //PD2, PD0 : OUTPUT
	TCCR0A = 0b11110001; // PWM, Phase and Frequency Correct
	TCCR0B = 0b00000100; // Prescaler : 256

	while(1)
	{
Forward(0);
_delay_ms(100);
Backward(0);
}
return 0;
}

void Forward(uint8_t speed) //Function for moving robot. Speed : 0 ~ 255
{
PORTB |= (1 << 3); // Motor Direction

PORTD |= (1 << 1); // Motor Direction
OCR0A = speed;
OCR0B = speed;
}


/*
void Backward(uint8_t speed) //Function for moving robot. Speed : 0 ~ 255
{

PORTB = 0x00;
PORTD = 0x00;

PORTB |= (0 << 2); // Motor Direction

PORTD |= (0 << 1); // Motor Direction
OCR0A = speed;
OCR0B = speed;
}

*/
