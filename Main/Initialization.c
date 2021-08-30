//------------------------------------------------------------------------
// File    : Initialization.c
// Author  : ChangYoon Lee
// Written : 5 May 2019
// 
// Set init function to short length of the main function.
//
// Copyright (C) 2019 Dankook.Univ
//------------------------------------------------------------------------


#include "Global.h"
#include "Sound.h"

void init() 
{
	DDRB = 0b10101100; 		/*  PB7 --> Left motor enable bit
								PB3 --> Left motor forward bit
								PB2 --> Left motor backward bit

								PB5 --> Buzzer enable bit */

	DDRD = 0b01000111;		/* 	PD0 --> Right motor enable bit
								PD2 --> Right motor forward bit
								PD1 --> Right motor backward bit

								PD6 --> LED bit */

	DDRF = 0b00000000;		/*  PF1 --> Left button
								PF0 --> Right button */
	PORTF = 0b00000011;

	TCCR0A = 0b11110001;    // PWM, Phase and Frequency Correct
	TCCR0B = 0b00000100;    // Prescaler 256

	TCCR1A = 0b10000000; 	// PWM, OC1A On, Phase and Frequency Correct 
	TCCR1B = 0b00010010; 	//prescaler 8

	TCCR3A = 0b00000000;    // Normal
	TCCR3B = 0b00000101;    // Prescaler 1024

	TIMSK3 = 0b00000001;	// Time interrupt enable
	TCNT3 = 0xffff-60535;   // Every 0.1 second
	
	blink_led = 0;			// LED enable signal
	EN = 0;					// Enable signal

	sei();					// Allows interrupt
}	


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
void error_handling(char* message);

int main(int argc, char* argv[]) {
	int serv_sock;
	int clnt_sock;

	struct sockaddr_in serv_addr;
	struct sockaddr_in clnt_addr;
	socklen_t clnt_addr_size;

	serv_sock = socket(PF_INET, SOCK_STREAM, 0);
	if (serv_sock == -1)
		error_handling("socket error");
		
	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_addr.sin_port = htons(atoi(argv[1]));

	if (bind(serv_sock, (struct sockaddr*) & serv_addr, sizeof(serv_addr)) == -1)
		error_handling("bind error");

	if (listen(serv_sock, 5) == -1)
		error_handling("listen error");

	clnt_addr_size = sizeof(clnt_addr);
	clnt_sock = accept(serv_sock, (struct sockaddr*) & clnt_addr, &clnt_addr_size);
	if (clnt_sock == -1)
		error_handling("accept error");

	char msg[] = "Hello, this is server!\n";
	write(clnt_sock, msg, sizeof(msg));

	close(clnt_sock);
	close(serv_sock);

	return 0;
}

void error_handling(char* message) {
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}
