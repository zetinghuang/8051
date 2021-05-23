
#include "reg52.h"
#include "intrins.h"			 
typedef unsigned int uint;// 16位	  
typedef unsigned char uchar;//8 位
sbit SCK=P3^6;
sbit RCK=P3^5;
sbit SER=P3^4;
#define smg P1
uchar code smgduan[16]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90,0x88,0x83,0xC6,0xA1,0x86,0x8E};

void delay(uint i)
{
	while(i--);	
}

void Read595(uchar indata)
{	 uchar i;
	SCK = 1;
	RCK = 1;
	for(i=0;i<8;i++)
	{
	 	SER=indata>>7;
		indata<<=1;
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
 { uchar i; uchar smgwei;
   smgwei=0x01;
   while(1)
   {
   	 for(i=0;i<8;i++)
	  {
		Read595(smgwei);
		smg=smgduan[i];
		smgwei=smgwei<<i;
		delay(10);
	  }
   }
 }