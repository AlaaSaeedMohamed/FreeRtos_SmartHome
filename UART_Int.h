#ifndef UART_INT_H
#define UART_INT_H

void UART_VidInt(void);

void UART_VidSendData(uint8 Copy_u8Data);

uint8 UART_u8RecieveData(void);

void UART_Vid_SendString(uint8 *user);

void UART_Vid_SendInt(uint32 Copy_U32Number);

#endif
