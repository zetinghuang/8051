//DS1302时钟的数码管显示
#include "reg52.h"			 //此文件中定义了单片机的一些特殊功能寄存器
#include <DS1302.h>
#define smg P0

sbit LSA=P2^2;
sbit LSB=P2^3;
sbit LSC=P2^4;
   
	
 uchar disp[8];
 uint num;
 uchar code smgduan[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
 //uchar code smgduan[16]={0xf9,0xb0,0xf9,0x99,0xbf,0x92,0xa4,0xC0,0x80,0x90,0x88,0x83,0xC6,0xA1,0x86,0x8E};
void delay(uint i)
{
	while(i--);	
}

void datapro()
{
	DS1302_READ_TIME();
	disp[0]=smgduan[TIME[2]/16];
	disp[1]=smgduan[TIME[2]&0x0f];
	disp[2]=0x40;
	disp[3]=smgduan[TIME[1]/16];
	disp[4]=smgduan[TIME[1]&0x0f];
	disp[5]=0x40;
	disp[6]=smgduan[TIME[0]/16];
	disp[7]=smgduan[TIME[0]&0x0f];
}		  
void smgdis()
{	uchar i;

	for(i=0;i<8;i++)
	{ 		 
	 switch(i)
	 	{
		 		case(0):
				LSA=0;LSB=0;LSC=0; break;//显示第0位
			case(1):
				LSA=1;LSB=0;LSC=0; break;//显示第1位
			case(2):
				LSA=0;LSB=1;LSC=0; break;//显示第2位
			case(3):
				LSA=1;LSB=1;LSC=0; break;//显示第3位
			case(4):
				LSA=0;LSB=0;LSC=1; break;//显示第4位
			case(5):
				LSA=1;LSB=0;LSC=1; break;//显示第5位
			case(6):
				LSA=0;LSB=1;LSC=1; break;//显示第6位
			case(7):
				LSA=1;LSB=1;LSC=1; break;//显示第7位	
		}  
	  	smg=disp[i];
	  	delay(100);
	  	smg=0x00;
	}
}


void main()
{	
	DS1302_INIT();
	while(1)
	{
		datapro();
		smgdis();
	}	
}