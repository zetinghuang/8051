#ifndef __DS1302_H_
#define __DS1302_H_

#include <reg52.h>
#include<intrins.h>

#ifndef uint
#define uint unsigned int 
#endif

#ifndef uchar
#define uchar unsigned char
#endif

sbit CE=P3^5;
sbit IO=P3^4;
sbit CLK=P3^6;

void DS1302_WRITE(uchar addr, uchar dat);
uint DS1302_RECEIVE(uchar addr);
void DS1302_INIT();
void DS1302_READ_TIME();

extern uchar TIME[7];
#endif
