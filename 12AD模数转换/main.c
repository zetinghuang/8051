//数码管显示电位器的值
#include <reg52.h>			 //此文件中定义了单片机的一些特殊功能寄存器
#include <adc.h>	
#define smg P0

sbit LSA=P2^2;
sbit LSB=P2^3;
sbit LSC=P2^4;
   
	
 uchar disp[4];
 uchar code smgduan[16]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90,0x88,0x83,0xC6,0xA1,0x86,0x8E};//显示0~F的值
 //uchar code smgduan[16]={0xf9,0xb0,0xf9,0x99,0xbf,0x92,0xa4,0xC0,0x80,0x90,0x88,0x83,0xC6,0xA1,0x86,0x8E};
void delay(uint i)
{
	while(i--);	
}

void datapro()
{
	uint temp;
	static uchar i;
	if(i==50)
	{
	 i=0;
	 temp=ADCREAD(0x94);
	}
	i++;
	disp[0]=smgduan[temp/1000];
	disp[1]=smgduan[temp%1000/100];
	disp[2]=smgduan[temp%1000%100/10];
	disp[3]=smgduan[temp%1000%100%10];
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
		}  
	  	smg=~disp[i];
	  	delay(100);
	  	smg=0xff;
	}
}


void main()
{	
	while(1)
	{
		datapro();
		smgdis();
	}	
}