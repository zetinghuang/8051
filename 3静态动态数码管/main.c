
#include "reg52.h"			 
#include "intrins.h"
typedef unsigned int uint;	  
typedef unsigned char uchar;

#define smg P0

sbit LSA=P2^2;
sbit LSB=P2^3;
sbit LSC=P2^4;
   
	

 uchar code smgwei[8]={0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};
 uchar code smgduan[16]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90,0x88,0x83,0xC6,0xA1,0x86,0x8E};//œ‘ æ0~Fµƒ÷µ
 //uchar code smgduan[16]={0xf9,0xb0,0xf9,0x99,0xbf,0x92,0xa4,0xC0,0x80,0x90,0x88,0x83,0xC6,0xA1,0x86,0x8E};
void delay(uint i)
{
	while(i--);	
}

void smgdis()
{	uchar i;

	for(i=0;i<8;i++)
	{ 		 
	 switch(i)
	 	{
		 	case(0):LSA=0;LSB=0;LSC=0;break;
			case(1):LSA=1;LSB=0;LSC=0;break;
			case(2):LSA=0;LSB=1;LSC=0;break;
			case(3):LSA=1;LSB=1;LSC=0;break;
			case(4):LSA=0;LSB=0;LSC=1;break;
			case(5):LSA=1;LSB=0;LSC=1;break;
			case(6):LSA=0;LSB=1;LSC=1;break;
			case(7):LSA=1;LSB=1;LSC=1;break;
		}  
	  	smg=~smgduan[i];
	  	delay(100);
	  	smg=0xff;
	}
}


void main()
{	

	
		smgdis();
			
}
