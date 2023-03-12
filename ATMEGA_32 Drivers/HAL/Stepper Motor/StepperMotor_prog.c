/*
 * StepperMotor_prog.c
 *
 * Created: 02/03/2023 10:47:02 م
 
/****************************************************************/
/*********************** Component DIRECTIVES *******************/
/****************************************************************/

#include "StepperMotor_int.h"
#include <util/delay.h>

/****************************************************************/
/*********************** Function Implementation  ***************/
/****************************************************************/

/****************************************************************/
/* Description    : his function used to initialize Stepper  	*/
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/

void StepperMotor_voidInit (u8 motorNumber)
{
	/***************************************************************/
	/*         Configure all pins as output and low                */
	/***************************************************************/
	for (u8 i = 0 ; i <motorNumber ; i++ )
	{
		
		/*************configure all wires pins as an output pins**********************/
		
		dio_vidConfigChannel(arrayOfMotors[i].blue_port,arrayOfMotors[i].blue_pin, OUTPUT);
		
		dio_vidConfigChannel(arrayOfMotors[i].pink_port,arrayOfMotors[i].pink_pin, OUTPUT);
		
		dio_vidConfigChannel(arrayOfMotors[i].yellow_port,arrayOfMotors[i].yellow_pin, OUTPUT);
		
		dio_vidConfigChannel(arrayOfMotors[i].orange_port,arrayOfMotors[i].orange_pin, OUTPUT);
		
		/*****************turn off all wires**********************************/
		
		dio_vidWriteChannel(arrayOfMotors[i].blue_port,arrayOfMotors[i].blue_pin,STD_LOW);
		
		dio_vidWriteChannel(arrayOfMotors[i].pink_port,arrayOfMotors[i].pink_pin,STD_LOW);
		
		dio_vidWriteChannel(arrayOfMotors[i].yellow_port,arrayOfMotors[i].yellow_pin,STD_LOW);
		
		dio_vidWriteChannel(arrayOfMotors[i].orange_port,arrayOfMotors[i].orange_pin,STD_LOW);
		
		_delay_ms(MAXIMUM_SPEED);
	}
	
}

/****************************************************************/
/* Description    : This function used for stepper motor to  	*/
/*                   the direction of the rotation and angle    */
/*					  of rotation and motor speed & steps       */
/*																*/
/*					Inputs : motorNumber , direction , speed    */
/*                            type_steps , NumberOfSteps        */
/*					Return : void		 					    */
/****************************************************************/

void StepperMotor_voidMove (u8 MotorNumber , u8 Direction , u16 Speed ,u16 NumberOfSteps)
{
	
	#if (STEPPER_MOTOR_ROTATION == FULL_STEP )
	switch (Direction)
	{
			
		case CLOCKWISE :
		for (u8 i = 0 ; i<NumberOfSteps ; i++ )
		{
			
			/******************************** C 1 ********************************/
			
			dio_vidWriteChannel(arrayOfMotors[MotorNumber].blue_port,arrayOfMotors[MotorNumber].blue_pin,STD_LOW);
			dio_vidWriteChannel(arrayOfMotors[MotorNumber].pink_port,arrayOfMotors[MotorNumber].pink_pin,STD_LOW);
			dio_vidWriteChannel(arrayOfMotors[MotorNumber].yellow_port,arrayOfMotors[MotorNumber].yellow_pin,STD_LOW);
			dio_vidWriteChannel(arrayOfMotors[MotorNumber].orange_port,arrayOfMotors[MotorNumber].orange_pin,STD_HIGH);
			
			_delay_ms(Speed);
			
			/******************************** C 2 ********************************/
			
			dio_vidWriteChannel(arrayOfMotors[MotorNumber].blue_port,arrayOfMotors[MotorNumber].blue_pin,STD_LOW);
			dio_vidWriteChannel(arrayOfMotors[MotorNumber].pink_port,arrayOfMotors[MotorNumber].pink_pin,STD_LOW);
			dio_vidWriteChannel(arrayOfMotors[MotorNumber].yellow_port,arrayOfMotors[MotorNumber].yellow_pin,STD_HIGH);
			dio_vidWriteChannel(arrayOfMotors[MotorNumber].orange_port,arrayOfMotors[MotorNumber].orange_pin,STD_LOW);
			
			_delay_ms(Speed);
			
			/******************************** C 3 ********************************/
			
			dio_vidWriteChannel(arrayOfMotors[MotorNumber].blue_port,arrayOfMotors[MotorNumber].blue_pin,STD_LOW);
			dio_vidWriteChannel(arrayOfMotors[MotorNumber].pink_port,arrayOfMotors[MotorNumber].pink_pin,STD_HIGH);
			dio_vidWriteChannel(arrayOfMotors[MotorNumber].yellow_port,arrayOfMotors[MotorNumber].yellow_pin,STD_LOW);
			dio_vidWriteChannel(arrayOfMotors[MotorNumber].orange_port,arrayOfMotors[MotorNumber].orange_pin,STD_LOW);
			
			_delay_ms(Speed);
			
			/******************************** C 4 ********************************/
			
			dio_vidWriteChannel(arrayOfMotors[MotorNumber].blue_port,arrayOfMotors[MotorNumber].blue_pin,STD_HIGH);
			dio_vidWriteChannel(arrayOfMotors[MotorNumber].pink_port,arrayOfMotors[MotorNumber].pink_pin,STD_LOW);
			dio_vidWriteChannel(arrayOfMotors[MotorNumber].yellow_port,arrayOfMotors[MotorNumber].yellow_pin,STD_LOW);
			dio_vidWriteChannel(arrayOfMotors[MotorNumber].orange_port,arrayOfMotors[MotorNumber].orange_pin,STD_LOW);
			
			_delay_ms(Speed);
			
		}
		
		break;
		
		case COUNTER_CLOCKWISE :
		
		for (u8 i = 0 ; i<NumberOfSteps ; i++ )
		{
			
			
			/******************************** C 1 ********************************/
			
			dio_vidWriteChannel(arrayOfMotors[MotorNumber].blue_port,arrayOfMotors[MotorNumber].blue_pin,STD_HIGH);
			dio_vidWriteChannel(arrayOfMotors[MotorNumber].pink_port,arrayOfMotors[MotorNumber].pink_pin,STD_LOW);
			dio_vidWriteChannel(arrayOfMotors[MotorNumber].yellow_port,arrayOfMotors[MotorNumber].yellow_pin,STD_LOW);
			dio_vidWriteChannel(arrayOfMotors[MotorNumber].orange_port,arrayOfMotors[MotorNumber].orange_pin,STD_LOW);
			
			_delay_ms(Speed);
			
			/******************************** C 2 ********************************/
			
			dio_vidWriteChannel(arrayOfMotors[MotorNumber].blue_port,arrayOfMotors[MotorNumber].blue_pin,STD_LOW);
			dio_vidWriteChannel(arrayOfMotors[MotorNumber].pink_port,arrayOfMotors[MotorNumber].pink_pin,STD_HIGH);
			dio_vidWriteChannel(arrayOfMotors[MotorNumber].yellow_port,arrayOfMotors[MotorNumber].yellow_pin,STD_LOW);
			dio_vidWriteChannel(arrayOfMotors[MotorNumber].orange_port,arrayOfMotors[MotorNumber].orange_pin,STD_LOW);
			
			_delay_ms(Speed);
			
			/******************************** C 3 ********************************/
			
			dio_vidWriteChannel(arrayOfMotors[MotorNumber].blue_port,arrayOfMotors[MotorNumber].blue_pin,STD_LOW);
			dio_vidWriteChannel(arrayOfMotors[MotorNumber].pink_port,arrayOfMotors[MotorNumber].pink_pin,STD_LOW);
			dio_vidWriteChannel(arrayOfMotors[MotorNumber].yellow_port,arrayOfMotors[MotorNumber].yellow_pin,STD_HIGH);
			dio_vidWriteChannel(arrayOfMotors[MotorNumber].orange_port,arrayOfMotors[MotorNumber].orange_pin,STD_LOW);
			
			_delay_ms(Speed);
			
			/******************************** C 4 ********************************/
			
			dio_vidWriteChannel(arrayOfMotors[MotorNumber].blue_port,arrayOfMotors[MotorNumber].blue_pin,STD_LOW);
			dio_vidWriteChannel(arrayOfMotors[MotorNumber].pink_port,arrayOfMotors[MotorNumber].pink_pin,STD_LOW);
			dio_vidWriteChannel(arrayOfMotors[MotorNumber].yellow_port,arrayOfMotors[MotorNumber].yellow_pin,STD_LOW);
			dio_vidWriteChannel(arrayOfMotors[MotorNumber].orange_port,arrayOfMotors[MotorNumber].orange_pin,STD_HIGH);
			
			_delay_ms(Speed);
			
		}
		break;
		
		case STOP :         /*****************************STOP******************************/
		for (u8 i = 0 ; i<NumberOfSteps ; i++ )
		{
			dio_vidWriteChannel(arrayOfMotors[MotorNumber].blue_port,arrayOfMotors[MotorNumber].blue_pin,STD_LOW);
			dio_vidWriteChannel(arrayOfMotors[MotorNumber].pink_port,arrayOfMotors[MotorNumber].pink_pin,STD_LOW);
			dio_vidWriteChannel(arrayOfMotors[MotorNumber].yellow_port,arrayOfMotors[MotorNumber].yellow_pin,STD_LOW);
			dio_vidWriteChannel(arrayOfMotors[MotorNumber].orange_port,arrayOfMotors[MotorNumber].orange_pin,STD_LOW);
		}
		_delay_ms(MAXIMUM_SPEED);
		
		break;
		
		default:        /*****************************default******************************/
		dio_vidWriteChannel(arrayOfMotors[MotorNumber].blue_port,arrayOfMotors[MotorNumber].blue_pin,STD_LOW);
		dio_vidWriteChannel(arrayOfMotors[MotorNumber].pink_port,arrayOfMotors[MotorNumber].pink_pin,STD_LOW);
		dio_vidWriteChannel(arrayOfMotors[MotorNumber].yellow_port,arrayOfMotors[MotorNumber].yellow_pin,STD_LOW);
		dio_vidWriteChannel(arrayOfMotors[MotorNumber].orange_port,arrayOfMotors[MotorNumber].orange_pin,STD_LOW);
		
		_delay_ms(MAXIMUM_SPEED);
		
		break;
	}
	
	#endif

	/*********************************************************************************************/
	/*                                               HALF STEP                                   */
	/*********************************************************************************************/

	#if (ST_MOTOR_ROTATION == HALF_STEP )

	switch (Direction)
	{
		
		case CLOCKWISE :            /********************* CLOCKWISE********************/
		
		for (u8 i = 0 ; i<NumberOfSteps ; i++ )
		{
			
			
			/******************************** C 1 ********************************/
			
			dio_vidWriteChannel(arrayOfMotors[MotorNumber].blue_port,arrayOfMotors[MotorNumber].blue_pin,STD_HIGH);
			dio_vidWriteChannel(arrayOfMotors[MotorNumber].pink_port,arrayOfMotors[MotorNumber].pink_pin,STD_LOW);
			dio_vidWriteChannel(arrayOfMotors[MotorNumber].yellow_port,arrayOfMotors[MotorNumber].yellow_pin,STD_LOW);
			dio_vidWriteChannel(arrayOfMotors[MotorNumber].orange_port,arrayOfMotors[MotorNumber].orange_pin,STD_HIGH);
			
			_delay_ms(Speed);
			
			/******************************** C 2 ********************************/
			
			dio_vidWriteChannel(arrayOfMotors[MotorNumber].blue_port,arrayOfMotors[MotorNumber].blue_pin,STD_LOW);
			dio_vidWriteChannel(arrayOfMotors[MotorNumber].pink_port,arrayOfMotors[MotorNumber].pink_pin,STD_LOW);
			dio_vidWriteChannel(arrayOfMotors[MotorNumber].yellow_port,arrayOfMotors[MotorNumber].yellow_pin,STD_LOW);
			dio_vidWriteChannel(arrayOfMotors[MotorNumber].orange_port,arrayOfMotors[MotorNumber].orange_pin,STD_HIGH);
			
			_delay_ms(Speed);
			
			/******************************** C 3 ********************************/
			
			dio_vidWriteChannel(arrayOfMotors[MotorNumber].blue_port,arrayOfMotors[MotorNumber].blue_pin,STD_LOW);
			dio_vidWriteChannel(arrayOfMotors[MotorNumber].pink_port,arrayOfMotors[MotorNumber].pink_pin,STD_LOW);
			dio_vidWriteChannel(arrayOfMotors[MotorNumber].yellow_port,arrayOfMotors[MotorNumber].yellow_pin,STD_HIGH);
			dio_vidWriteChannel(arrayOfMotors[MotorNumber].orange_port,arrayOfMotors[MotorNumber].orange_pin,STD_HIGH);
			
			_delay_ms(Speed);
			
			/******************************** C 4 ********************************/
			
			dio_vidWriteChannel(arrayOfMotors[MotorNumber].blue_port,arrayOfMotors[MotorNumber].blue_pin,STD_LOW);
			dio_vidWriteChannel(arrayOfMotors[MotorNumber].pink_port,arrayOfMotors[MotorNumber].pink_pin,STD_LOW);
			dio_vidWriteChannel(arrayOfMotors[MotorNumber].yellow_port,arrayOfMotors[MotorNumber].yellow_pin,STD_HIGH);
			dio_vidWriteChannel(arrayOfMotors[MotorNumber].orange_port,arrayOfMotors[MotorNumber].orange_pin,STD_LOW);
			
			_delay_ms(Speed);
			
			/******************************** C 5 ********************************/
			
			dio_vidWriteChannel(arrayOfMotors[MotorNumber].blue_port,arrayOfMotors[MotorNumber].blue_pin,STD_LOW);
			dio_vidWriteChannel(arrayOfMotors[MotorNumber].pink_port,arrayOfMotors[MotorNumber].pink_pin,STD_HIGH);
			dio_vidWriteChannel(arrayOfMotors[MotorNumber].yellow_port,arrayOfMotors[MotorNumber].yellow_pin,STD_HIGH);
			dio_vidWriteChannel(arrayOfMotors[MotorNumber].orange_port,arrayOfMotors[MotorNumber].orange_pin,STD_LOW);
			
			_delay_ms(Speed);
			
			/******************************** C 6 ********************************/
			
			dio_vidWriteChannel(arrayOfMotors[MotorNumber].blue_port,arrayOfMotors[MotorNumber].blue_pin,STD_LOW);
			dio_vidWriteChannel(arrayOfMotors[MotorNumber].pink_port,arrayOfMotors[MotorNumber].pink_pin,STD_HIGH);
			dio_vidWriteChannel(arrayOfMotors[MotorNumber].yellow_port,arrayOfMotors[MotorNumber].yellow_pin,STD_LOW);
			dio_vidWriteChannel(arrayOfMotors[MotorNumber].orange_port,arrayOfMotors[MotorNumber].orange_pin,STD_LOW);
			
			_delay_ms(Speed);
			
			/******************************** C 7 ********************************/
			
			dio_vidWriteChannel(arrayOfMotors[MotorNumber].blue_port,arrayOfMotors[MotorNumber].blue_pin,STD_HIGH);
			dio_vidWriteChannel(arrayOfMotors[MotorNumber].pink_port,arrayOfMotors[MotorNumber].pink_pin,STD_HIGH);
			dio_vidWriteChannel(arrayOfMotors[MotorNumber].yellow_port,arrayOfMotors[MotorNumber].yellow_pin,STD_LOW);
			dio_vidWriteChannel(arrayOfMotors[MotorNumber].orange_port,arrayOfMotors[MotorNumber].orange_pin,STD_LOW);
			
			_delay_ms(Speed);
			
			/******************************** C 8 ********************************/
			
			dio_vidWriteChannel(arrayOfMotors[MotorNumber].blue_port,arrayOfMotors[MotorNumber].blue_pin,STD_HIGH);
			dio_vidWriteChannel(arrayOfMotors[MotorNumber].pink_port,arrayOfMotors[MotorNumber].pink_pin,STD_LOW);
			dio_vidWriteChannel(arrayOfMotors[MotorNumber].yellow_port,arrayOfMotors[MotorNumber].yellow_pin,STD_LOW);
			dio_vidWriteChannel(arrayOfMotors[MotorNumber].orange_port,arrayOfMotors[MotorNumber].orange_pin,STD_LOW);
			
			_delay_ms(Speed);
			
		}
		break;

		
		case COUNTER_CLOCKWISE :     /**************************COUNTER_CLOCKWISE*****************************/
		
		for (u8 i = 0 ; i<NumberOfSteps ; i++ )
		{
			
			
			/******************************** C 1 ********************************/
			
			dio_vidWriteChannel(arrayOfMotors[MotorNumber].blue_port,arrayOfMotors[MotorNumber].blue_pin,STD_HIGH);
			dio_vidWriteChannel(arrayOfMotors[MotorNumber].pink_port,arrayOfMotors[MotorNumber].pink_pin,STD_LOW);
			dio_vidWriteChannel(arrayOfMotors[MotorNumber].yellow_port,arrayOfMotors[MotorNumber].yellow_pin,STD_LOW);
			dio_vidWriteChannel(arrayOfMotors[MotorNumber].orange_port,arrayOfMotors[MotorNumber].orange_pin,STD_HIGH);
			
			_delay_ms(Speed);
			
			/******************************** C 2 ********************************/
			
			dio_vidWriteChannel(arrayOfMotors[MotorNumber].blue_port,arrayOfMotors[MotorNumber].blue_pin,STD_HIGH);
			dio_vidWriteChannel(arrayOfMotors[MotorNumber].pink_port,arrayOfMotors[MotorNumber].pink_pin,STD_LOW);
			dio_vidWriteChannel(arrayOfMotors[MotorNumber].yellow_port,arrayOfMotors[MotorNumber].yellow_pin,STD_LOW);
			dio_vidWriteChannel(arrayOfMotors[MotorNumber].orange_port,arrayOfMotors[MotorNumber].orange_pin,STD_LOW);
			
			_delay_ms(Speed);
			
			/******************************** C 3 ********************************/
			
			dio_vidWriteChannel(arrayOfMotors[MotorNumber].blue_port,arrayOfMotors[MotorNumber].blue_pin,STD_HIGH);
			dio_vidWriteChannel(arrayOfMotors[MotorNumber].pink_port,arrayOfMotors[MotorNumber].pink_pin,STD_HIGH);
			dio_vidWriteChannel(arrayOfMotors[MotorNumber].yellow_port,arrayOfMotors[MotorNumber].yellow_pin,STD_LOW);
			dio_vidWriteChannel(arrayOfMotors[MotorNumber].orange_port,arrayOfMotors[MotorNumber].orange_pin,STD_LOW);
			
			_delay_ms(Speed);
			
			/******************************** C 4 ********************************/
			
			dio_vidWriteChannel(arrayOfMotors[MotorNumber].blue_port,arrayOfMotors[MotorNumber].blue_pin,STD_LOW);
			dio_vidWriteChannel(arrayOfMotors[MotorNumber].pink_port,arrayOfMotors[MotorNumber].pink_pin,STD_HIGH);
			dio_vidWriteChannel(arrayOfMotors[MotorNumber].yellow_port,arrayOfMotors[MotorNumber].yellow_pin,STD_LOW);
			dio_vidWriteChannel(arrayOfMotors[MotorNumber].orange_port,arrayOfMotors[MotorNumber].orange_pin,STD_LOW);
			
			_delay_ms(Speed);
			
			/******************************** C 5 ********************************/
			
			dio_vidWriteChannel(arrayOfMotors[MotorNumber].blue_port,arrayOfMotors[MotorNumber].blue_pin,STD_LOW);
			dio_vidWriteChannel(arrayOfMotors[MotorNumber].pink_port,arrayOfMotors[MotorNumber].pink_pin,STD_HIGH);
			dio_vidWriteChannel(arrayOfMotors[MotorNumber].yellow_port,arrayOfMotors[MotorNumber].yellow_pin,STD_HIGH);
			dio_vidWriteChannel(arrayOfMotors[MotorNumber].orange_port,arrayOfMotors[MotorNumber].orange_pin,STD_LOW);
			
			_delay_ms(Speed);
			
			/******************************** C 6 ********************************/
			
			dio_vidWriteChannel(arrayOfMotors[MotorNumber].blue_port,arrayOfMotors[MotorNumber].blue_pin,STD_LOW);
			dio_vidWriteChannel(arrayOfMotors[MotorNumber].pink_port,arrayOfMotors[MotorNumber].pink_pin,STD_LOW);
			dio_vidWriteChannel(arrayOfMotors[MotorNumber].yellow_port,arrayOfMotors[MotorNumber].yellow_pin,STD_HIGH);
			dio_vidWriteChannel(arrayOfMotors[MotorNumber].orange_port,arrayOfMotors[MotorNumber].orange_pin,STD_LOW);
			
			_delay_ms(Speed);
			
			/******************************** C 7 ********************************/
			
			dio_vidWriteChannel(arrayOfMotors[MotorNumber].blue_port,arrayOfMotors[MotorNumber].blue_pin,STD_LOW);
			dio_vidWriteChannel(arrayOfMotors[MotorNumber].pink_port,arrayOfMotors[MotorNumber].pink_pin,STD_LOW);
			dio_vidWriteChannel(arrayOfMotors[MotorNumber].yellow_port,arrayOfMotors[MotorNumber].yellow_pin,STD_HIGH);
			dio_vidWriteChannel(arrayOfMotors[MotorNumber].orange_port,arrayOfMotors[MotorNumber].orange_pin,STD_HIGH);
			
			_delay_ms(Speed);
			
			/******************************** C 8 ********************************/
			
			dio_vidWriteChannel(arrayOfMotors[MotorNumber].blue_port,arrayOfMotors[MotorNumber].blue_pin,STD_LOW);
			dio_vidWriteChannel(arrayOfMotors[MotorNumber].pink_port,arrayOfMotors[MotorNumber].pink_pin,STD_LOW);
			dio_vidWriteChannel(arrayOfMotors[MotorNumber].yellow_port,arrayOfMotors[MotorNumber].yellow_pin,STD_LOW);
			dio_vidWriteChannel(arrayOfMotors[MotorNumber].orange_port,arrayOfMotors[MotorNumber].orange_pin,STD_HIGH);
			
			_delay_ms(Speed);
			
		}
		break;
		
		
		
		case STOP :          /*****************************STOP******************************/
		for (u8 i = 0 ; i<NumberOfSteps ; i++ )
		{
			dio_vidWriteChannel(arrayOfMotors[MotorNumber].blue_port,arrayOfMotors[MotorNumber].blue_pin,STD_LOW);
			dio_vidWriteChannel(arrayOfMotors[MotorNumber].pink_port,arrayOfMotors[MotorNumber].pink_pin,STD_LOW);
			dio_vidWriteChannel(arrayOfMotors[MotorNumber].yellow_port,arrayOfMotors[MotorNumber].yellow_pin,STD_LOW);
			dio_vidWriteChannel(arrayOfMotors[MotorNumber].orange_port,arrayOfMotors[MotorNumber].orange_pin,STD_LOW);
		}
		_delay_ms(MAXIMUM_SPEED);
		
		break;
		
		
		default:        /*****************************default******************************/
		dio_vidWriteChannel(arrayOfMotors[MotorNumber].blue_port,arrayOfMotors[MotorNumber].blue_pin,STD_LOW);
		dio_vidWriteChannel(arrayOfMotors[MotorNumber].pink_port,arrayOfMotors[MotorNumber].pink_pin,STD_LOW);
		dio_vidWriteChannel(arrayOfMotors[MotorNumber].yellow_port,arrayOfMotors[MotorNumber].yellow_pin,STD_LOW);
		dio_vidWriteChannel(arrayOfMotors[MotorNumber].orange_port,arrayOfMotors[MotorNumber].orange_pin,STD_LOW);
		
		_delay_ms(MAXIMUM_SPEED);
		
		break;
	}

	#endif
}

/***********************************************************************************************/
/************************************* END OF PROGRAM ******************************************/
/***********************************************************************************************/