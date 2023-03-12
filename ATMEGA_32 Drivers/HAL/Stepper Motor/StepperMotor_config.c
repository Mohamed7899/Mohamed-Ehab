/*
 * StepperMotor_config.c
 *
 * Created: 03/03/2023 03:16:01 م
 *  
 */ 
/****************************************************************/
/*********************** STD LIB DIRECTIVES *********************/
/****************************************************************/

#include "std_types.h"
#include "bit_math.h"

/****************************************************************/
/*********************** Component DIRECTIVES *******************/
/****************************************************************/

#include "dio.h"
#include "StepperMotor_priv.h"
#include "StepperMotor_config.h"

/************************************************/
/*      Array of struct [ Stepper Motors ]      */
/************************************************/

StepperMotor arrayOfMotors [NUMBER_OF_MOTORS] =
{
	{DIO_PORTA,DIO_PIN0,DIO_PORTA,DIO_PIN1,DIO_PORTA,DIO_PIN2,DIO_PORTA,DIO_PIN3},
	{DIO_PORTA,DIO_PIN4,DIO_PORTA,DIO_PIN5,DIO_PORTA,DIO_PIN6,DIO_PORTA,DIO_PIN7},
	{DIO_PORTB,DIO_PIN0,DIO_PORTB,DIO_PIN1,DIO_PORTB,DIO_PIN2,DIO_PORTB,DIO_PIN3}
};