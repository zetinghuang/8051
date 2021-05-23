#define __I2C_H_

#include <reg52.h>


#define uint unsigned int 

#define uchar unsigned char 

sbit SDA=P2^0;
sbit SCL=P2^1;
static uchar num;

void delay_10US(); 
void iic_start();
void iic_end();
uchar iic_send_byte(uchar dat);
uchar iic_receive_byte();
void iic_send_data(uchar addr, uchar dat);
uchar iic_receive_data(uchar addr);
