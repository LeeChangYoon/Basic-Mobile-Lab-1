//------------------------------------------------------------------------
// File    : Sound.c
// Author  : Yongkwan Park
// Written : 5 May 2019
// 
// Contains funtions related to sound.
//
// Copyright (C) 2019 Dankook.Univ
//------------------------------------------------------------------------


#include "Global.h"
#include "Sound.h"

uint16_t tone_array[9] = { 0,261,293,329,349,391,440,493,523 }; //Do, Rae ...

void StartSound()
{
	tone(Ra, 1);	tone(0,  1);
	tone(Pa, 1);	tone(0,  1);
	tone(Pa, 0);    tone(0,  0);
	tone(Pa, 0);    tone(0,  0);
	tone(Pa, 0);	tone(0,  1);
	tone(Pa, 1);	tone(0,  0);
	tone(Sol,0);	tone(0,  0);
	tone(Pa, 0);	tone(0,  0);
	tone(Do, 0);	tone(0,  0);
	tone(Pa, 0);	tone(0,  0);
}

void LeftSound()
{

	tone(Ra, 0); 	tone(0,  0);
	tone(Si, 0); 	tone(0,  0);
	tone(Ra, 0);  	tone(0,  0);
	tone(Ra, 0); 	tone(0,  0);
	tone(Si, 0); 	tone(0,  0);
	tone(Ra, 0);  	tone(0,  0);
}

void RightSound()
{
	tone(Do_5, 0); 	tone(0,  0);
	tone(Sol,  0); 	tone(0,  0);
	tone(Pa,   0);  tone(0,  1);
	tone(Ra,   0); 	tone(0,  0);
	tone(Sol,  0); 	tone(0,  0);
	tone(Pa,   0);  tone(0,  1);
}

void BothSound()
{
	tone(Do, 0); 	tone(0,  0);
	tone(Mi, 0); 	tone(0,  0);
	tone(Sol,0);    tone(0,  0);
	tone(Do, 0); 	tone(0,  0);
	tone(Mi, 0); 	tone(0,  0);
	tone(Sol,0);    tone(0,  0);	
}

uint16_t frequency_return(uint16_t fre) 
{
	int8_t period_1 = 2; // period 2us
	int set_period = 0;
	int16_t return_fre = 0;

	set_period = 1000000 / fre;
	return_fre = set_period / period_1;

	return return_fre;
}

void tone(uint8_t scale, int ch)
{
	OC1_PERIOD = frequency_return(tone_array[scale]); 		//period 
	OC1A_WIDTH = frequency_return(tone_array[scale]) / 20;  //width

	switch (ch) // Change delay time by ch variable
	{
		case 1:
			_delay_ms(50);
			break;
		
		case 0:
			_delay_ms(100);
			break;
	}
}
