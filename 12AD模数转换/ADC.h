#ifndef __ADC_H_
#define __ADC_H_

#include <reg52.h>
#include<intrins.h>

#ifndef uint
#define uint unsigned int 
#endif

#ifndef uchar
#define uchar unsigned char
#endif

sbit DOUT=P3^7;
sbit DIN=P3^4;
sbit CLK=P3^6;
sbit CS=P3^5;

void SENDBYTE(uchar dat);
uint RECEIVEBYTE(void);
uint ADCREAD(uchar cmd);
#endif
