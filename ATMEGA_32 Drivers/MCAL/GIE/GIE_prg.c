/*
 * Inclusions 
 */
/* Library Files */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/* Module Files */
#include "GIE_int.h"
#include "GIE_reg.h"

/*
 * Public Function Definition 
 */
void GIE_vidEnable(void) {
	SET_BIT(SREG,I);
}
void GIE_vidDisable(void) {
	CLEAR_BIT(SREG,I);
}