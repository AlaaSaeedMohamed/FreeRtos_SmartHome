#ifndef LCD_INT_H
#define LCD_INT_H

void LCD_vid_SendData(uint8 Copy_u8Data);

void LCD_vid_SendCmd(uint8 Copy_u8Cmd);

void LCD_Vid_Init(void);

void LCD_vid_GoToX(uint8 Copy_u8X, uint8 Copy_u8Y);

void LCD_vid_SendSpecialChar(uint8 *pattern, uint8 Pattern, uint8 Copy_u8XPos, uint8 Copy_u8YPos);

void LCD_vid_SendInt(uint32 Copy_U32Number);

void LCD_vid_SendString(uint8 *str);

void LCD2_Vid_Init(void);

void LCD2_vid_SendData(uint8 Copy_u8Data);

void LCD2_vid_SendCmd(uint8 Copy_u8Cmd);

void LCD2_vid_GoToX(uint8 Copy_u8X, uint8 Copy_u8Y);

void LCD2_vid_SendString(uint8 *str);

#endif
