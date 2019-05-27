#include "Global.h"
#include "Sound.h"

uint16_t tone_array[9] = {0,261,293,329,349,391,440,493, 523}; //Do, Rae ...

uint16_t frequency_return(uint16_t fre) // PWM Period to Frequency
{
	int8_t period_1 = 2; // period 2us
	int set_period = 0;
	int16_t return_fre = 0;

	set_period = 1000000 / fre;
	return_fre = set_period /period_1;

	return return_fre;
}

void tone(uint8_t scale, uint16_t delay) 
{
	OC1_PERIOD = frequency_return(tone_array[scale]); //period 
	OC1A_WIDTH = frequency_return(tone_array[scale])/20; //width
	// _delay_ms(delay);
}
