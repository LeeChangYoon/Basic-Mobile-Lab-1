#define OC1A_WIDTH OCR1A
#define OC1_PERIOD ICR1

enum tone_scale
{
	No, Do, Rae, Mi, Pa, Sol, Ra, Si, Do_5
};

uint16_t frequency_return(uint16_t fre);
void tone(uint8_t scale, uint16_t delay);
void delay_ms(int ms);

