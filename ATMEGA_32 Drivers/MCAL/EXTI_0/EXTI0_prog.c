

/****************************************************************/
/*********************** STD LIB DIRECTIVES *********************/
/****************************************************************/

#include "std_types.h"
#include "bit_math.h"


/****************************************************************/
/*********************** Component DIRECTIVES *******************/
/****************************************************************/

#include "EXTI0_int.h"
#include "EXTI0_Config.h"
#include "EXTI0_private.h"



/***********************************************************/
/**!comment   :  pointer to function for callback	       */
/***********************************************************/

 void (*CallBackPtr)(void)= NULL;




/****************************************************************/
/*********************** Function Implementation  ***************/
/****************************************************************/


/****************************************************************/
/* Description    :  This function used to initialize EXT0      */
/*					 Inputs : void 								*/
/*					 return : void		 						*/
/****************************************************************/



void EXTI0_voidInit (void)
{
	/* Enable the external interrupt */

		SET_BIT( GICR, 6);

	/*  Interrupt 0 sense control  */

	#if EXT0_SENSE_MODE == IOC
	SET_BIT(MCUCR , 0);
	CLEAR_BIT(MCUCR , 1);

	#elif EXT0_SENSE_MODE == RISING
	SET_BIT(MCUCR , 0);
	SET_BIT(MCUCR , 1);

	#elif EXT0_SENSE_MODE == FALLING
	CLEAR_BIT(MCUCR , 0);
	SET_BIT(MCUCR , 1);

	#elif EXT0_SENSE_MODE == LOW_LEVEL
	CLEAR_BIT(MCUCR , 0);
	CLEAR_BIT(MCUCR , 1);

	#endif

	/* End ( if ) condition for Macros */


/** disable EXT0 in initialization function  **/
/** like : void EXT0_voidDisable(); 		  */
	CLEAR_BIT( GICR , 6 );
	SET_BIT(GIFR , 6 ) ;


}


/****************************************************************/
/* Description    : This function used to Enable EXT0			*/
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after Interrupt */
/*     				 initialized 							    */
/****************************************************************/

void EXTI0_voidEnable()
{

	SET_BIT( GICR , 6 );

}


/****************************************************************/
/* Description    : This function used to Disable EXT0			*/
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after Interrupt */
/*     				 initialized 							    */
/****************************************************************/

void EXTI0_voidDisable()
{

	CLEAR_BIT( GICR , 6 );

}


/****************************************************************/
/* Description    : This function used to communicate with the	*/
/*					function in App Layer(The Callback function)*/
/*						[ Layer Architecture Problem Solved ]	*/
/*																*/
/*					Inputs : Pointer to function that points to	*/
/*							 the first line of the function(ISR)*/
/*					Return : void								*/
/****************************************************************/
/* Pre_condition  :  this function must be used after Interrupt */
/*     				 initialized 							    */
/****************************************************************/


void EXTI0_voidCallBack(void(*CopyFuncPtr)(void))
{


		CallBackPtr=CopyFuncPtr;
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
void EXTI0_voidSetSignalch(u8 SenseCpy)
{




}

/****************************************************************/
/* Description    : This function used to Check if interrupt is */
/*					Executed or Not.							*/
/*																*/
/*					Inputs : void					  			*/
/*					Return : flag Status [ LBTY_OK , LBTY_NOK ]	*/
/****************************************************************/
/* Pre_condition  :  this function must be used after Interrupt */
/*     				 initialized 							    */
/****************************************************************/
/*
flagStatus EXT0_enuIsExecuted( void )
{
	flagStatus ErrorStatus ;

	if( (GET_BIT(GIFR, 6)) == 1 )
	{

		ErrorStatus = LBTY_NOK ;
	}
	else if ( (GET_BIT(GIFR, 6)) == 0 )
	{

		ErrorStatus = LBTY_OK ;
	}

	return ErrorStatus ;
}
*/
/** Linker Problem solved */
void __vector_1(void) __attribute__(( signal , used ));


void __vector_1(void)
{
	if (CallBackPtr != NULL)
	{
		CallBackPtr();
	}




}

/***********************************************************************************************/
/************************************* END OF PROGRAM ******************************************/
/***********************************************************************************************/
