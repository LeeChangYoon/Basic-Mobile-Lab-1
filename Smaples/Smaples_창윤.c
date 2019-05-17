#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>

int main() {
	DDRB = 0b10001100;
	DDRD = 0b00000111;
	DDRF = 0x00; // 1 --> input_pullup. Now it is 0b00001111;

	while(1) {
			PORTF = 0x01;

			if (PINF & (1 << 0)) { 
				PORTB = 0b10001000;
			} // (1 << 0) means that it will check the 0th number of binarys
			
			else {
				PORTB = 0b10000100;
			}
			
			if (PINF & (1 << 1)) {
				PORTD = 0b00000101;
			} // Same in here
			
			else {
				PORTD = 0b00000011;
			}		
		}
		return 0;
}
