#define F_CPU 16000000

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

void Start();
void Stop();
void Turn_left();
void Turn_right();
void Forward(uint8_t speed);
void Backward(uint8_t speed);
void Left(uint8_t speed);
void Right(uint8_t speed);
