#include "reg52.h"	
#include"intrins.h"		 
typedef unsigned int uint;	  
typedef unsigned char uchar;
sbit beep=P0^0;
sbit INPULSE=P1^5;
sbit INDATA=P1^6;
sbit CLK=P3^6;

//uchar code smgduan[16]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90,0x88,0x83,0xC6,0xA1,0x86,0x8E};


void delay(uint i)
{
	while(i--);	
}


 uint Read165(void)
{	uint indata; uint i;
	INPULSE=0;
	_nop_();
	INPULSE=1;
	_nop_();
	indata=0;
	for(i=0;i<8;i++)
	{
	 indata=indata<<1;
	 CLK=0;
	 _nop_();
	 indata|=INDATA;
	 CLK=1;	
	}	
	return(indata);
}
void main()
{	
		uint value; 
		while(1)
		{	
			value=Read165();
			if(value!=0xff)
			{
				switch(value)
			{
			 	case(0xfe):beep=~beep;delay(10);break;
				case(0xfd):beep=~beep;delay(30); break;
				case(0xfb):beep=~beep;delay(50);
				case(0x07):beep=~beep;delay(70);
				case(0xef):beep=~beep;delay(90);
				case(0xdf):beep=~beep;delay(110);
				case(0xbf):beep=~beep;delay(130);
				case(0x70):beep=~beep;delay(150);
			}
			}
		}			
}
