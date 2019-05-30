#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define OC1A_WIDTH OCR1A
#define OC1_PERIOD ICR1

enum tone_scale
{
	No, Do, Rae, Mi, Pa, Sol, Ra, Si, Do_5
};

uint16_t frequency_return(uint16_t fre);

void tone(uint8_t scale, uint16_t delay);

uint16_t tone_array[9] = { 0,261,293,329,349,391,440,493,523 }; //Do, Rae ...




																/////////////////////////////////////////////////       Start sound function   ///////////////////////////////////////////////////////////////////////////////////////////////////


int StartSound()
{
	DDRB = 0b00100000; // PB5 OUTPUT for Buzzer
	TCCR1A = 0b10000000; // PWM, OC1A On, Phase and Frequency Correct 
	TCCR1B = 0b00010010; //prescaler 8	

	sei(); //Interrupt Enable
	while (1)
	{
		int dulation = 100;

		tone1(Ra, dulation);    //Ra Sound
		tone1(0, 50);
		tone1(Pa, dulation);	//Pa Sound
		tone1(0, 50);
		tone(Pa, dulation);		//Pa Sound
		tone(0, 50);
		tone(Pa, dulation);		//Pa Sound
		tone(0, 50);
		tone(Pa, dulation);		//Pa Sound
		tone1(0, 50);
		tone1(Pa, dulation);	//Pa Sound
		tone(0, 50);
		tone(Sol, dulation);	//Sol Sound
		tone(0, 50);
		tone(Pa, dulation);		//Pa Sound
		tone(0, 50);
		tone(Do, dulation);		//Do Sound
		tone(0, 50);
		tone(Pa, dulation);		//Pa Sound
		tone(0, 50);




	}
	return 0;
}

uint16_t frequency_return(uint16_t fre) // PWM Period to Frequency
{
	int8_t period_1 = 2; // period 2us
	int set_period = 0;
	int16_t return_fre = 0;

	set_period = 1000000 / fre;
	return_fre = set_period / period_1;

	return return_fre;
}


//////////////////////////////////////////////////// 1/2-Pitch Negative Output //////////////////////////////////////////////////////////////////////////////////////////////////


void tone(uint8_t scale, uint16_t delay)
{
	OC1_PERIOD = frequency_return(tone_array[scale]); //period 
	OC1A_WIDTH = frequency_return(tone_array[scale]) / 20; //width
	_delay_ms(50);
}

//////////////////////////////////////////////////// One-Pitch Negative Output //////////////////////////////////////////////////////////////////////////////////////////////////

void tone1(uint8_t scale, uint16_t delay)
{
	OC1_PERIOD = frequency_return(tone_array[scale]); //period 
	OC1A_WIDTH = frequency_return(tone_array[scale]) / 20; //width
	_delay_ms(100);
}


///////////////////////////////////////////////// external signal detection, sound function   ////////////////////////////////////////////////////////////////////////////////////


* /

int SignalSound()
{
	DDRB = 0b00100000; // PB5 OUTPUT for Buzzer
	TCCR1A = 0b10000000; // PWM, OC1A On, Phase and Frequency Correct 
	TCCR1B = 0b00010010; //prescaler 8	

	sei(); //Interrupt Enable
	while (1)
	{
		int dulation = 100;

		tone(Ra, dulation); 	//Ra Sound
		tone(0, 50);
		tone(Sol, dulation); 	//Sol Sound
		tone(0, 50);
		tone(Pa, dulation);  	//Pa Sound
		tone1(0, 50);




	}
	return 0;
}

uint16_t frequency_return(uint16_t fre) // PWM Period to Frequency
{
	int8_t period_1 = 2; // period 2us
	int set_period = 0;
	int16_t return_fre = 0;

	set_period = 1000000 / fre;
	return_fre = set_period / period_1;

	return return_fre;
}


//////////////////////////////////////////////////// 1/2-pitch Negative Output //////////////////////////////////////////////////////////////////////////////////////////////////

void tone(uint8_t scale, uint16_t delay)
{
	OC1_PERIOD = frequency_return(tone_array[scale]); //period 
	OC1A_WIDTH = frequency_return(tone_array[scale]) / 20; //width
	_delay_ms(50);
}




//////////////////////////////////////////////////// One-pitch Negative Output //////////////////////////////////////////////////////////////////////////////////////////////////

void tone1(uint8_t scale, uint16_t delay)
{
	OC1_PERIOD = frequency_return(tone_array[scale]); //period 
	OC1A_WIDTH = frequency_return(tone_array[scale]) / 20; //width
	_delay_ms(100);
}
