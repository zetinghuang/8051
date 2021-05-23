#include <reg52.h>
#include<intrins.h>
typedef  unsigned int  uint;
typedef  unsigned char uchar; 
sbit led=P1^3;
uchar num,sec,shi,ge;
#define smg P0

sbit LSA=P1^0;
sbit LSB=P1^1;
sbit LSC=P1^2;
   
	

 uchar code smgduan[16]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90,0x88,0x83,0xC6,0xA1,0x86,0x8E};//显示0~F的值

 void delay(uint i)
 {
  while(i--);
 }
void smgdis(uchar shi,uchar ge)
{	uint j;

	for(j=0;j<2;j++)
	{ 
		 switch(j)
	 	{
		 	case(0):LSA=0;LSB=0;LSC=0;smg=~smgduan[shi];break;
			case(1):LSA=1;LSB=0;LSC=0;smg=~smgduan[ge];break;
			/*
			case(2):LSA=0;LSB=1;LSC=0;break;
			case(3):LSA=1;LSB=1;LSC=0;break;
			case(4):LSA=0;LSB=0;LSC=1;break;
			case(5):LSA=1;LSB=0;LSC=1;break;
			case(6):LSA=0;LSB=1;LSC=1;break;
			case(7):LSA=1;LSB=1;LSC=1;break;
			*/
		}  
	  	delay(100);
	  	smg=0xff;
	}
}


void Timerinit()
{
  TMOD|=0x01;
  TH0=0x3C;
  TL0=0xB0;;
  EA=1;
  ET0=1;
  TR0=1;
}
	  
void main()
{  	led=0;
	Timerinit();
	while(1)
	{
	 if(num==20) //1秒时间到
	{
	 num=0;
	 sec++;
	 led=~led;
	 if(sec==60)
	 {sec=0;}
	 shi=sec/10;
	 ge=sec%10;
	}
	smgdis(shi,ge);
	}
}

void Timer0() interrupt 1 
{ 	 
	TH0=0X3C; //给定时器0重新赋值，定时 50ms 
	TL0=0XB0; 
	num++;  
	
}