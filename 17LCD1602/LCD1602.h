
#define __LCD1602_H_

//#define LCD1602_4PINS

#include <reg52.h>


#define uchar unsigned char



#define uint unsigned int


#define LCD1602_DATAPINS P0
sbit LCD1602_E=P2^7;
sbit LCD1602_RW=P2^5;
sbit LCD1602_RS=P2^6;

void lcd1602_delay1ms(uint c);
void LCD_WRITE_COM(uchar com);
void LCD_WRITE_DATA(uchar dat);
void LCD_INIT();


