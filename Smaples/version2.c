#define F_CPU 16000000  //-> CPU Clock 설정
#include<avr/io.h>   // -> input/output을 가지고 있는 헤더파일
#include<util/delay.h> // -> delay를 가지고 있는 헤더파일

/*
DDRx = Ob00001111

x-> pin 알파벳 값
00001111-> x의0~7까지의 핀 값중 출력할꺼면 1 출력하지 않을꺼면 0
PORTx ->  출력을 주는 코드
PINx -> if 문을 사용해 input의 역할을 함
*/


//모터 변환 코드
/*
int main(){

	DDRB = 0b10001100;  //우리가 사용할 pin을 1로 설정한다.(input 줄 값을 1로 설정) 

	while(1)
		{
		PORTB = 0b10001000;  //output을 주고 싶은 값을 1로 설정한다.
		_delay_ms(100);
		PORTB = 0b10000100;   //output을 주고 싶은 값을 1로 설정한다.
		_delay_ms(100);
		}
		return 0;
	}
*/
