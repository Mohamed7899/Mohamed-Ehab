/*****************************************************************/
/* 	Author 	 	 : Mohamed Ehab                            */
/* 	Version 	 : 1V 								          */
/* 	Description	 : prog.c for ADC                            */
/************************************************************/

/****************************************************************/
/*********************** STD LIB DIRECTIVES *********************/
/****************************************************************/

#include "std_types.h"
#include "bit_math.h"

/****************************************************************/
/*********************** Component DIRECTIVES *******************/
/****************************************************************/

#include "ADC_int.h"
#include "ADC_config.h"
#include "ADC_private.h"

/****************************************************************/
/*********************** Function Implementation  ***************/
/****************************************************************/


/****************************************************************/
/* Description    :  This function used to initialize ADC 	    */
/*					 Inputs : void 								*/
/*					 return : void		 						*/
/****************************************************************/

void ADC_voidInit (void)
{

		/* Set the Prescaler value according to
		   the selected option inside the configuration file */

		#if   ADC_PRESCALLER_VALUE == ADC_PRESCALLER_128
			SET_BIT(ADCSRA,2);
			SET_BIT(ADCSRA,1);
			SET_BIT(ADCSRA,0);
		#elif ADC_PRESCALLER_VALUE == ADC_PRESCALLER_64
			SET_BIT(ADCSRA,2);
			SET_BIT(ADCSRA,1);
			CLEAR_BIT(ADCSRA,0);
		#elif ADC_PRESCALLER_VALUE == ADC_PRESCALLER_32
			SET_BIT(ADCSRA,2);
			CLEAR_BIT(ADCSRA,1);
			SET_BIT(ADCSRA,0);
		#elif ADC_PRESCALLER_VALUE == ADC_PRESCALLER_16
			SET_BIT(ADCSRA,2);
			CLEAR_BIT(ADCSRA,1);
			CLEAR_BIT(ADCSRA,0);
		#elif ADC_PRESCALLER_VALUE == ADC_PRESCALLER_8
			CLEAR_BIT(ADCSRA,2);
			SET_BIT(ADCSRA,1);
			SET_BIT(ADCSRA,0);
		#elif ADC_PRESCALLER_VALUE == ADC_PRESCALLER_4
			CLEAR_BIT(ADCSRA,2);
			SET_BIT(ADCSRA,1);
			CLEAR_BIT(ADCSRA,0);
		#elif ADC_PRESCALLER_VALUE == ADC_PRESCALLER_2
			CLEAR_BIT(ADCSRA,2);
			CLEAR_BIT(ADCSRA,1);
			CLEAR_BIT(ADCSRA,0);
		#endif


	/* Select reference voltage*/
    #if(VOLTAGE_REFERENCE==AVCC)
	SET_BIT(ADMUX,6);
	CLEAR_BIT(ADMUX,7);
	

    #elif(VOLTAGE_REFERENCE==AREF)
	CLEAR_BIT(ADMUX,6);
	CLEAR_BIT(ADMUX,7);
	

    #elif(VOLTAGE_REFERENCE==INTERNAL)
	SET_BIT(ADMUX,6);
	SET_BIT(ADMUX,7);
	
     #endif

	/*SELECT ADJUST*/

     #if(ADJUSTMENT==RIGHT_ADJUSTMENT)
	 CLEAR_BIT(ADMUX,5);
     #endif


     #if(ADJUSTMENT==LEFT_ADJUSTMENT)
	 SET_BIT(ADMUX,5);

     #endif
	 
	 
	 /* Enable Interrupt*/
	 SET_BIT(ADCSRA,3);




}


/****************************************************************/
/* Description    : This function used to Enable ADC			*/ 
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after ADC		*/
/*     				 initialized 							    */
/****************************************************************/

void ADC_voidEnable()
{
	
	SET_BIT(ADCSRA , 7 );
	
}

/****************************************************************/
/* Description    : This function used to Enable ADC Interrput	*/ 
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after ADC		*/
/*     				 initialized 							    */
/****************************************************************/

void ADC_voidInterrputEnable()
{

	
	SET_BIT( ADCSRA , 3 );
	
}


/****************************************************************/
/* Description    : This function used to Disable ADC			*/ 
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after ADC 		*/
/*     				 initialized 							    */
/****************************************************************/

void ADC_voidDisable()
{
	
	CLEAR_BIT( ADCSRA , 7 );
	
}


/****************************************************************/
/* Description    : This function used to Start converting		*/ 
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after ADC 		*/
/*     				 initialized 							    */
/****************************************************************/

void ADC_voidStartConversion()
{
	
	SET_BIT( ADCSRA , 6 );
	
}


/****************************************************************/
/* Description    : This function used to Set lach Interrupt	*/
/*									 happens.					*/ 
/*																*/
/*					Inputs : Sense Mode				  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after Interrupt */
/*     				 initialized 							    */
/****************************************************************/

void ADC_voidAutoTrigger()
{
/****************************************************************/	
/** !comment : From Data Sheet : Starting conversion on positive*/
/*			   edge when ADATE = 1						    	*/
/****************************************************************/

	
	/** Enable ADC Auto Trigger	 							   **/
	/** ADATE = 1 =====> 	SET_BIT( ADATE , 5 ); 			   **/

    SET_BIT( ADCSRA , 5 );
	
		/*  ( if / else if ) condition for Macros */
	#if ADC_AUTO_TRIGGER_SOURCE == FREE_RUNNING_MODE 
	CLEAR_BIT( SFIOR , 5 );
	CLEAR_BIT( SFIOR , 6 );
	CLEAR_BIT( SFIOR , 7 );
	
	#elif ADC_AUTO_TRIGGER_SOURCE == ANALOG_COMPARATOR
	SET_BIT( SFIOR , 5 );
	CLEAR_BIT( SFIOR , 6 );
	CLEAR_BIT( SFIOR , 7 );
	
	#elif ADC_AUTO_TRIGGER_SOURCE == EXTERNAL_INTERRPUT_REQUEST_0
	CLEAR_BIT( SFIOR , 5 );
	SET_BIT( SFIOR , 6 );
	CLEAR_BIT( SFIOR , 7 );
	
	
	#elif ADC_AUTO_TRIGGER_SOURCE == TIMER_COUNTER_0_COMPARE_MATCH
	SET_BIT( SFIOR , 5 );
	SET_BIT( SFIOR , 6 );
	CLEAR_BIT( SFIOR , 7 );

	#elif ADC_AUTO_TRIGGER_SOURCE == TIMER_COUNTER_0_OVERFLOW
	CLEAR_BIT( SFIOR , 5 );
	CLEAR_BIT( SFIOR , 6 );
	SET_BIT( SFIOR , 7);
	
	#elif ADC_AUTO_TRIGGER_SOURCE == TIMER_COUNTER_COMPARE_MATCH_B
	SET_BIT( SFIOR , 5 );
	CLEAR_BIT( SFIOR , 6 );
	SET_BIT( SFIOR , 7 );

	#elif ADC_AUTO_TRIGGER_SOURCE == TIMER_COUNTER_1_OVERFLOW
	CLEAR_BIT( SFIOR , 5 );
	SET_BIT( SFIOR , 6 );
	SET_BIT( SFIOR , 7 );

	#elif ADC_AUTO_TRIGGER_SOURCE == TIMER_COUNTER_1_CAPTURE_EVENT
	SET_BIT( SFIOR , 5 );
	SET_BIT( SFIOR , 6 );
	SET_BIT( SFIOR , 7 );
	
	#endif
	/* End ( if ) condition for Macros */
	
}


/****************************************************************/
/* Description    : This function used to Read ADC and 			*/ 
/*																*/
/*					Inputs : void					  			*/
/*					Return : u16 Digital Converting melli Volt	*/
/****************************************************************/
/* Pre_condition  :  this function must be used after ADC 		*/
/*     				 initialized 							    */
/****************************************************************/

u16 ADC_u16ReadADCInMV(u8 ChannelID)
{

	/* Select the specified Channel */
	ADMUX = ( (ADMUX & 0b11100000) |ChannelID);
	
	/* Start the Conversion */
	SET_BIT(ADCSRA, 6);

	/* Busy-Wait Polling till conversion complete */
	while ( (GET_BIT(ADCSRA,4)) != 1 )
	{
		/* Only cheeking on the flag result */
	}

	/* Clear the ADC complete conversion flag */
	SET_BIT(ADCSRA,4);

	u16 mv_result=ADCL;
	
	return mv_result;
	
}


/***********************************************************************************************/
/************************************* END OF PROGRAM ******************************************/
/***********************************************************************************************/
