/*
 * main.c
 *
 *  Created on: Jan 17, 2024
 *      Author: ahmed saeed
 */
#include "STD_Types2.h"
#include "BIT_Math.h"
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "DIO_int.h"
#include "LCD_int.h"
#include "UART_Int.h"
#include "ADC_int.h"
#include "GIE_interface.h"
#include "EXTI_int.h"
#include <util/delay.h>
//define semaphore for sahred rersourse LCD
SemaphoreHandle_t LEDsemph ;
int led = 0;
int door;
float temp;

void LED(void* pvParameter);
void Door(void* pvParameter);
void LCD(void* pvParameter);
void Temp(void* pvParameter);
void UART(void* pvParameter);

int main()
{
	DIO_Vid_SetPortDirection(Port_A,output);
	DIO_Vid_SetPortDirection(Port_B,output);
	DIO_Vid_SetPortDirection(Port_C,output);
	DIO_Vid_SetPortDirection(Port_D,output);

	LCD_Vid_Init();
	LCD2_Vid_Init();
	UART_VidInt();
	ADC_Vid_Init();

	DIO_Vid_SetPinDirection(Port_A,pin0, input); //ADC pin
	// UART pins
	DIO_Vid_SetPinDirection(Port_D,pin0,input);
	DIO_Vid_SetPinDirection(Port_D,pin1,output);
	//led pin
	DIO_Vid_SetPinDirection(Port_D,pin3,output);
	// button pin
	DIO_Vid_SetPinDirection(Port_D, pin2,input);
	DIO_Vid_SetPinValue(Port_D, pin2, PinHigh);

	//buzzer pin
	DIO_Vid_SetPinDirection(Port_A, pin2, input);

	//door pin
	DIO_Vid_SetPinDirection(Port_A, pin1,input);
	//DIO_Vid_SetPinValue(Port_A, pin1, PinHigh);

	LEDsemph = xSemaphoreCreateBinary(); // returns 0 so we have to release the semaphore

	xSemaphoreGive(LEDsemph);

	GIE_voidEnable();
	EXTI_Vid_Enable();

	//create the tasks
	xTaskCreate(&LED, NULL,100,NULL,2,NULL);
	xTaskCreate(&LCD, NULL,200,NULL,0,NULL);
	xTaskCreate(&Door, NULL,100,NULL,4,NULL);
	xTaskCreate(&Temp, NULL,100,NULL,5,NULL);
	xTaskCreate(&UART, NULL,400,NULL,1,NULL);


	vTaskStartScheduler();

	while(1)
	{
	}
	return 0;
}


void LED(void* pvParameter)
{

	while(1)
	{
		if(xSemaphoreTake(LEDsemph,0) == pdTRUE)
		{
			led = led ^ 1; //toggle led
			DIO_Vid_SetPinValue(Port_D, pin3, led);
			xSemaphoreGive(LEDsemph);
			vTaskDelay(5000);
		}

	}
}



void LCD(void* pvParameter)
{

	while(1)
	{
		if(led == 1)
		{
			LCD_vid_DisplayClear();
			LCD_vid_GoToX(0, 0);
			LCD_vid_SendString("led is on");

		}

		else if(led == 0){
			LCD_vid_DisplayClear();
			LCD_vid_GoToX(0, 0);
			LCD_vid_SendString("led is off");
		}

		LCD_vid_GoToX(1, 0);
		LCD_vid_SendString("temp: ");
		LCD_vid_SendInt(temp);

		if(door == PinLow){
			LCD2_vid_DisplayClear();
			LCD2_vid_GoToX(0, 0);
			LCD2_vid_SendString("door is open");
		}

		else{
			LCD2_vid_DisplayClear();
			LCD2_vid_GoToX(0, 0);
			LCD2_vid_SendString("door is closed");
		}

		vTaskDelay(1000);



	}
}


void UART(void* pvParameter)
{

	while(1)
	{
		UART_Vid_SendString("\f");
		if(led == 1)
		{

			UART_Vid_SendString("led is on\r");

		}

		else if(led == 0){

			UART_Vid_SendString("led is off\r");
		}

		if(door == PinLow){
			UART_Vid_SendString("door is open\r");
		}

		else{
			UART_Vid_SendString("door is closed");
			UART_Vid_SendString("\r");
		}

		UART_Vid_SendString("temp:");
		UART_Vid_SendInt(temp);
		UART_Vid_SendString("\r");
		vTaskDelay(1200);



	}
}

void Temp(void* pvParameter)
{

	while(1)
	{
		signed int volt;

		volt=Temp_ADC_read();
		temp=(float)(volt*5)/1023.0;//conversation for LM45 Sensor
		temp = temp*100;

		vTaskDelay(2000);

	}
}


void Door(void* pvParameter)
{

	while(1)
	{

		door = GET_BIT(PINA, pin1);

		if(GET_BIT(PINA, pin1) == PinLow){
			DIO_Vid_SetPinDirection(Port_A, pin2, output);
		}

		if(GET_BIT(PINA, pin1) == PinHigh){
			DIO_Vid_SetPinDirection(Port_A, pin2, input);
		}

		vTaskDelay(2000);

	}
}




void __vector_1 (void) __attribute__ ((signal));

void __vector_1 (void){

	if(xSemaphoreTake(LEDsemph,10) == pdTRUE)
	{

		led = led ^ 1; //toggle led
		DIO_Vid_SetPinValue(Port_D, pin3, led);
		xSemaphoreGive(LEDsemph);

	}

}

