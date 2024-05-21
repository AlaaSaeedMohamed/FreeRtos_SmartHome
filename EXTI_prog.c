#include "STD_Types.h"
#include "BIT_Math.h"
#include "EXTI_private.h"
#include "EXTI_config.h"




void EXTI_Vid_Enable(void){
	#if INT_SRC == INT0

		#if SENSE_CTRL == FALLING

			SET_BIT(EXTI_MCUCR, MCUCR_ISC01);
			CLR_BIT(EXTI_MCUCR, MCUCR_ISC00);



		#elif SENSE_CTRL == RISING

			Set(EXTI_MCUCR, MCUCR_ISC01);
			Set(EXTI_MCUCR, MCUCR_ISC00);



		#elif SENSE_CTRL == ONCHANGE

			Clr(EXTI_MCUCR, MCUCR_ISC01);
			Set(EXTI_MCUCR, MCUCR_ISC00);



		#endif

		SET_BIT(EXTI_GICR, GICR_INT0);



	#endif
}

void EXTI_Vid_Disable(void){
	#if INT_SRC == INT0

		#if SENSE_CTRL == FALLING

			SET_BIT(EXTI_MCUCR, MCUCR_ISC01);
			CLR_BIT(EXTI_MCUCR, MCUCR_ISC00);



		#elif SENSE_CTRL == RISING

			Set(EXTI_MCUCR, MCUCR_ISC01);
			Set(EXTI_MCUCR, MCUCR_ISC00);



		#elif SENSE_CTRL == ONCHANGE

			Clr(EXTI_MCUCR, MCUCR_ISC01);
			Set(EXTI_MCUCR, MCUCR_ISC00);



		#endif

		CLR_BIT(EXTI_GICR, GICR_INT0);



	#endif
}


