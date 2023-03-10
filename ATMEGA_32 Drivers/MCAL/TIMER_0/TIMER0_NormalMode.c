/*
 * main.c
 *
 *  Created on: Feb 26, 2023
 *      Author: moham
 */

#define F_CPU 8000000
#include "util/delay.h"
#include "std_types.h"
#include "dio.h"
#include "led.h"
#include "TIMR0_int.h"

u8 x=0;
void task_1()
{
	x++;
	if(x==4)
	{
		led_toggle(LED_RED);
		x=0;
	}
}
int main(void)

{

	SET_BIT(SREG,7);

	 TIMER0_void_Init();
     TIMER0_void_EnableOVInt();
	 TIMER0_void_SetOVCallBack (task_1);





  while(1)
  {

  }

}

 

