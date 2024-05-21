/********************************************************************/
/****************    SWC : DIO Driver      **************************/
/****************    By  : AlaaSaeed       **************************/
/****************    Date: 27Aug           **************************/
/****************    Version : v1.0        **************************/
/********************************************************************/
#include "STD_Types2.h"
#include "STD_TYPES.h"
#include "BIT_Math.h"
#include "DIO_int.h"
#include "DIO_private.h"



/*Setting pin Direction*/
void DIO_Vid_SetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Direction){
	
	if(Copy_u8Direction == input){
		switch (Copy_u8Port){
			case Port_A : CLR_BIT(DDRA , Copy_u8Pin); break;
			case Port_B : CLR_BIT(DDRB , Copy_u8Pin); break;
			case Port_C : CLR_BIT(DDRC , Copy_u8Pin); break;
			case Port_D : CLR_BIT(DDRD , Copy_u8Pin); break;

		}
	}
	else if(Copy_u8Direction == output){
		switch (Copy_u8Port){
			case Port_A : SET_BIT(DDRA , Copy_u8Pin); break;
			case Port_B : SET_BIT(DDRB , Copy_u8Pin); break;
			case Port_C : SET_BIT(DDRC , Copy_u8Pin); break;
			case Port_D : SET_BIT(DDRD , Copy_u8Pin); break;

		}
	}
	
}

/*Setting pin Value*/
void DIO_Vid_SetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value){
	
	if(Copy_u8Value == PinLow){
		switch (Copy_u8Port){
			case Port_A : CLR_BIT(PORTA , Copy_u8Pin); break;
			case Port_B : CLR_BIT(PORTB , Copy_u8Pin); break;
			case Port_C : CLR_BIT(PORTC , Copy_u8Pin); break;
			case Port_D : CLR_BIT(PORTD , Copy_u8Pin); break;

		}
	}
	else if(Copy_u8Value == PinHigh){
		switch (Copy_u8Port){
			case Port_A : SET_BIT(PORTA , Copy_u8Pin); break;
			case Port_B : SET_BIT(PORTB , Copy_u8Pin); break;
			case Port_C : SET_BIT(PORTC , Copy_u8Pin); break;
			case Port_D : SET_BIT(PORTD , Copy_u8Pin); break;

		}
	}
}

/*Getting pin Value*/
void DIO_Vid_GetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 *pu8Data){
	
	switch(Copy_u8Port){
		
		case Port_A : *pu8Data = GET_BIT(PINA , Copy_u8Pin); break;
		case Port_B : *pu8Data = GET_BIT(PINB , Copy_u8Pin); break;
		case Port_C : *pu8Data = GET_BIT(PINC , Copy_u8Pin); break;
		case Port_D : *pu8Data = GET_BIT(PIND , Copy_u8Pin); break;
	}
}



/*Setting port Direction*/
void DIO_Vid_SetPortDirection(u8 Copy_u8Port, u8 Copy_u8Direction){
	
	if(Copy_u8Direction == output){
			switch (Copy_u8Port){
				case Port_A : DDRA = 0b11111111; break;
				case Port_B : DDRB = 0b11111111; break;
				case Port_C : DDRC = 0b11111111; break;
				case Port_D : DDRD = 0b11111111; break;

			}
		}
		else if(Copy_u8Direction == input){
			switch (Copy_u8Port){
				case Port_A : DDRA = 0b00000000; break;
				case Port_B : DDRB = 0b00000000; break;
				case Port_C : DDRC = 0b00000000; break;
				case Port_D : DDRD = 0b00000000; break;

			}
		}
}


/*Setting port(port register) value*/
void DIO_Vid_SetPortValue(u8 Copy_u8Port, u8 Copy_u8Value){
	switch(Copy_u8Port){

			case Port_A :   PORTA = Copy_u8Value; break;
			case Port_B :   PORTB = Copy_u8Value; break;
			case Port_C :   PORTC = Copy_u8Value; break;
			case Port_D :   PORTD = Copy_u8Value; break;
		}
}


/*Getting port(PIN register) value*/
void DIO_Vid_GetPportValue(u8 Copy_u8Port, u8 *pu8Data){
	/*switch(Copy_u8Port){

			case Port_A : *pu8Data = ; break;
			case Port_B : *pu8Data = ; break;
			case Port_C : *pu8Data = ; break;
			case Port_D : *pu8Data = ; break;
		}
	*/
}



