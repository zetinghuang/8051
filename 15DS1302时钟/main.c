//DS1302ʱ�ӵ��������ʾ
#include "reg52.h"			 //���ļ��ж����˵�Ƭ����һЩ���⹦�ܼĴ���
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
				LSA=0;LSB=0;LSC=0; break;//��ʾ��0λ
			case(1):
				LSA=1;LSB=0;LSC=0; break;//��ʾ��1λ
			case(2):
				LSA=0;LSB=1;LSC=0; break;//��ʾ��2λ
			case(3):
				LSA=1;LSB=1;LSC=0; break;//��ʾ��3λ
			case(4):
				LSA=0;LSB=0;LSC=1; break;//��ʾ��4λ
			case(5):
				LSA=1;LSB=0;LSC=1; break;//��ʾ��5λ
			case(6):
				LSA=0;LSB=1;LSC=1; break;//��ʾ��6λ
			case(7):
				LSA=1;LSB=1;LSC=1; break;//��ʾ��7λ	
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