#include "BIT_Math.h"
#include "STD_Types2.h"
#include "STD_TYPES.h"
#include "DIO_int.h"
#include "LCD_config.h"
#include "LCD_int.h"
#include "LCD_private.h"

#include <util/delay.h>




void LCD_vid_SendData(uint8 Copy_u8Data){

	DIO_Vid_SetPinValue(CONTROL_PORT, RS_PIN,PinHigh);
	DIO_Vid_SetPinValue(CONTROL_PORT, RW_PIN,PinLow);
	DIO_Vid_SetPortValue(DATA_PORT, Copy_u8Data);
	DIO_Vid_SetPinValue(CONTROL_PORT, E_PIN,PinHigh);
	_delay_ms(3);
	DIO_Vid_SetPinValue(CONTROL_PORT, E_PIN,PinLow);

}

void LCD_vid_SendCmd(uint8 Copy_u8Cmd){

	DIO_Vid_SetPinValue(CONTROL_PORT, RS_PIN,PinLow);
	DIO_Vid_SetPinValue(CONTROL_PORT, RW_PIN,PinLow);
	DIO_Vid_SetPortValue(DATA_PORT, Copy_u8Cmd);
	DIO_Vid_SetPinValue(CONTROL_PORT, E_PIN,PinHigh);
	_delay_ms(3);
	DIO_Vid_SetPinValue(CONTROL_PORT, E_PIN,PinLow);

}

void LCD2_vid_SendData(uint8 Copy_u8Data){

	DIO_Vid_SetPinValue(CONTROL_PORT2, RS_PIN,PinHigh);
	DIO_Vid_SetPinValue(CONTROL_PORT2, RW_PIN,PinLow);
	DIO_Vid_SetPortValue(DATA_PORT2, Copy_u8Data);
	DIO_Vid_SetPinValue(CONTROL_PORT2, E_PIN,PinHigh);
	_delay_ms(3);
	DIO_Vid_SetPinValue(CONTROL_PORT2, E_PIN,PinLow);

}

void LCD2_vid_SendCmd(uint8 Copy_u8Cmd){

	DIO_Vid_SetPinValue(CONTROL_PORT2, RS_PIN,PinLow);
	DIO_Vid_SetPinValue(CONTROL_PORT2, RW_PIN,PinLow);
	DIO_Vid_SetPortValue(DATA_PORT2, Copy_u8Cmd);
	DIO_Vid_SetPinValue(CONTROL_PORT2, E_PIN,PinHigh);
	_delay_ms(3);
	DIO_Vid_SetPinValue(CONTROL_PORT2, E_PIN,PinLow);

}

void LCD_Vid_Init(void){

	_delay_ms(40);
	LCD_vid_SendCmd(0b00111100);
	_delay_ms(1);

	LCD_vid_SendCmd(0b00001100);

	LCD_vid_SendCmd(1);

}

void LCD2_Vid_Init(void){

	_delay_ms(40);
	LCD2_vid_SendCmd(0b00111100);
	_delay_ms(1);

	LCD2_vid_SendCmd(0b00001100);

	LCD2_vid_SendCmd(1);

}

void LCD_vid_DisplayClear(){
	LCD_vid_SendCmd(1);
}

void LCD2_vid_DisplayClear(){
	LCD2_vid_SendCmd(1);
}


void LCD_vid_GoToX(uint8 Copy_u8X, uint8 Copy_u8Y){

	if(Copy_u8X==1){
		Copy_u8Y += 0x40;
	}

	LCD_vid_SendCmd(Copy_u8Y+0b10000000);
}

void LCD2_vid_GoToX(uint8 Copy_u8X, uint8 Copy_u8Y){

	if(Copy_u8X==1){
		Copy_u8Y += 0x40;
	}

	LCD2_vid_SendCmd(Copy_u8Y+0b10000000);
}

void LCD_vid_SendSpecialChar(uint8 *pattern, uint8 Pattern_Num, uint8 Copy_u8XPos, uint8 Copy_u8YPos){

	uint8 Local_Address = 8 * Pattern_Num;
	LCD_vid_SendCmd(0b01000000 + Local_Address);

	for(uint8 i=0; i<8; i++){
		LCD_vid_SendData(pattern[i]);
	}

	LCD_vid_GoToX(Copy_u8XPos,Copy_u8YPos);
	LCD_vid_SendData(Pattern_Num);


}

void LCD_vid_SendInt(uint32 Copy_U32Number){
	if(Copy_U32Number != 0){
		LCD_vid_SendInt(Copy_U32Number/10);
		LCD_vid_SendData((Copy_U32Number%10)+'0');
	}

}

void LCD_vid_SendString(uint8 *str){
	uint8 i=0;
	 while(str[i] != '\0'){
		 LCD_vid_SendData(str[i]);
		 i++;
	 }
}


void LCD2_vid_SendString(uint8 *str){
	uint8 i=0;
	 while(str[i] != '\0'){
		 LCD2_vid_SendData(str[i]);
		 i++;
	 }
}
