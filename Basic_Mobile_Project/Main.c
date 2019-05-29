#include "Global.h"
#include "Sound.h"

int main()
{
	DDRB = 0b10001100; // PB7, PB3, PB2, PB5 : OUTPUT
	DDRD = 0b00000111; // PD2, PD1, PD0 	 : OUTPUT
	DDRF = 0x00;       // PF0, PF1	         : Interrupt (switches)

	TCCR0A = 0b11110001; // PWM, Phase and Frequency Correct
	TCCR0B = 0b00000100; // prescaler 256

	int count = 0;

	Start();	

	while(1)
	{	
		PINF = 0b00000011;

		if (((~PINF & 0b00000001) == 0b00000000) && ((~PINF & 0b00000010) == 0b00000000)) 
		{
			if (count == 0)
			{
				count++;
			}
			
			else
			{
				Backward(100);
				_delay_ms(1000); 
	  		    Right(100);   
				_delay_ms(1000); 
			}
		}

		else if (((~PINF & 0b00000001) == 0b00000001) && ((~PINF & 0b00000010) == 0b00000000)) 
		{ 
		 	Backward(100);
			_delay_ms(1000); 
  		    Right(100);   
			_delay_ms(500); 
		}  
		
		else if (((~PINF & 0b00000001) == 0b00000000) && ((~PINF & 0b00000010) == 0b00000010)) 
		{ 
			Backward(100);       
			_delay_ms(1000); 
			Left(100);          
			_delay_ms(500); 
		}

		else
		{
			if (count == 0) 
			{
				Stop();
			}

			else
			{
				Forward(50);
			}
		}
	}
	return 0;
}
