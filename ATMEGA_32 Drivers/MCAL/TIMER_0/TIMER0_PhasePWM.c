/*
 * main.c
 *
 *  Created on: Feb 26, 2023
 *      Author: moham
 */

#define F_CPU 8000000
#include "util/delay.h"
#include "std_types.h"
#include "std_types.h"
#include "dio.h"
#include "led.h"
#include "TIMR0_int.h"


u8 i=0;
int main(void)
{


	TIMER0_void_Init();




	while(1)
	{

		dio_vidConfigChannel(DIO_PORTB, DIO_PIN3, OUTPUT);

		for (i=0;i<255;i++)
		{
			TIMER0_void_SetCompareVal(i);
			_delay_ms(20);
		}
	}
}
