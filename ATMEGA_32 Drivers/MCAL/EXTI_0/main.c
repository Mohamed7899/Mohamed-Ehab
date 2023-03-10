/*
 * main.c
 *
 *  Created on: Feb 24, 2023
 *      Author: moham
 */

#include "GIE_int.h"
#include "led.h"
#include "button.h"
#include "EXTI0_int.h"
#include <util/delay.h>

void EXTI0_ISR(void);


void EXTI0_ISR(void)

   {
	dio_vidConfigChannel(DIO_PORTA,DIO_PIN0,OUTPUT); // buzzer
   	dio_vidWriteChannel(DIO_PORTA,DIO_PIN0,STD_HIGH);
   	_delay_ms(1000);
   	dio_vidWriteChannel(DIO_PORTA,DIO_PIN0,STD_LOW);
   	  _delay_ms(1000);
   }


int main (void)
{
	
      GIE_vidEnable();
	dio_vidConfigChannel(DIO_PORTD,DIO_PIN2,INPUT);
	//button_vidInit();
	led_init();
    EXTI0_voidInit();
    EXTI0_voidCallBack(EXTI0_ISR);
    EXTI0_voidEnable();



    while(1)
    {
    	led_on(LED_RED);
    	_delay_ms(500);
    	led_off(LED_RED);
    	 _delay_ms(500);


    }







}


