/*
 * StepperMotor_config.h
 *
 * Created: 03/03/2023 02:57:49 م
 */ 


#ifndef STEPPERMOTOR_CONFIG_H_
#define STEPPERMOTOR_CONFIG_H_

/*************************************************/
/*      choosing number of used motors          */
/*************************************************/

#define NUMBER_OF_MOTORS  3

extern StepperMotor arrayOfMotors [NUMBER_OF_MOTORS] ;

/**************************************/
/*        a mode of motors rotate     */
/*                                    */
/*       [FULL STEP , HALF STEP]      */
/**************************************/

#define  FULL_STEP          1
#define  HALF_STEP          2

#define STEPPER_MOTOR_ROTATION  FULL_STEP

/*****************************************************/
/*               Stepper Motor Directions            */
/*        [ Clockwise or Anticlockwise or Stop ]     */
/*****************************************************/

#define  CLOCKWISE                1
#define  COUNTER_CLOCKWISE        2
#define  STOP                     3

/**************************************/
/*        THE SPEED OF MOTORS         */
/**************************************/

#define  MINIMUM_SPEED     20
#define  MAXIMUM_SPEED     300




#endif /* STEPPERMOTOR_CONFIG_H_ */