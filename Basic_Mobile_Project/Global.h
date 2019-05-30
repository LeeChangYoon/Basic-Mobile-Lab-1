#define F_CPU 16000000

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

void Start();
void Stop();
void Forward(uint8_t speed);
void Backward(uint8_t speed);
void Left(uint8_t speed);
void Right(uint8_t speed);

int EN;
uint8_t blink_led;
