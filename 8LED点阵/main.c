
#include "reg52.h"
#include "intrins.h"			 
typedef unsigned int uint;// 16位	  
typedef unsigned char uchar;//8 位
sbit SCK=P3^6;
sbit RCK=P3^5;
sbit SER=P3^4;
#define smg P1
uchar code smgduan[]={0xF8,0xFC,0xFE,0xFF,0xFF,0xFE,0xFC,0xF8,0xF8,0xFC,0xFE,0xFF,0xFF,0xFE,0xFC,0xF8,
					  0x01,0x03,0x07,0x0F,0x1F,0x3F,0x7F,0xFF,0xFF,0x7F,0x3F,0x1F,0x0F,0x07,0x03,0x01,};
uchar code smgwei[]={0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
					 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};

void delay(uint i)
{
	while(i--);	
}

void Read595(uchar indata1, uchar indata2, uchar indata3, uchar indata4)
{	uchar i;
	SCK = 1;
	RCK = 1;
	for(i=0;i<8;i++)
	{
	 	SER=indata1>>7;
		indata1<<=1;
		SCK=0;
		_nop_();
		_nop_();
		SCK=1;
	} 
		for(i=0;i<8;i++)
	{
	 	SER=indata2>>7;
		indata2<<=1;
		SCK=0;
		_nop_();
		_nop_();
		SCK=1;
	}
		for(i=0;i<8;i++)
	{
	 	SER=indata3>>7;
		indata3<<=1;
		SCK=0;
		_nop_();
		_nop_();
		SCK=1;
	}
		for(i=0;i<8;i++)
	{
	 	SER=indata4>>7;
		indata4<<=1;
		SCK=0;
		_nop_();
		_nop_();
		SCK=1;
	}
	RCK=0;
	_nop_();
	_nop_();
	RCK=1;
}
/*
void main()
{	
	uchar ledNum;

	ledNum = ~0x01;	  

	while(1)
	{
		Read595(ledNum);
		ledNum = _crol_(ledNum, 1);
		delay(50000);
	}			
}
  */
/*静态数码管显示0-F
void main()
{ uchar smgdis; uchar j;
  while(1)
  {	
  for(j=0;j<16;j++)
  	{	smgdis=smgduan[j];
   		Read595(smgdis);
		delay(500000);
	}
  }
}
*/
/*动态数码管显示0-7*/
void main()
 { uchar i;
   while(1)
   {
   	 for(i=0;i<16;i++)
	  {
		Read595(~smgwei[i+16],~smgwei[i],smgduan[i+16],smgduan[i]);
		delay(10);
	  }
   }
 }