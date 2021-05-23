//定时器0方式0实现led一秒闪烁一次,12MHz晶振
#include <reg52.h>
#include<intrins.h>
typedef  unsigned int  uint;
typedef  unsigned char uchar; 

sbit led=P0^0;

uint i;

void delay(uint i)
{
	while(i--);	
}
void Init_timer0_method0
{
	TMOD=0X00;
	TH0=(8192-5000)/32;
	TL0=(8192-5000)%32;
	EA=1;
	ET0=1;
	TR0=1;	
}	  
void main()
{  	
	Init_timer0_method0();
	while(1)
	{	 
	  if(i==200)
	  {
	   i=0;
	   led=~led;
	  }
	}
}

void Timer0() interrupt 1
{	
	TH0=(8192-5000)/32;
	TL0=(8192-5000)%32;
	i++;
} 

//定时器2方式0实现led一秒闪烁一次,12MHz晶振


/*
#include <reg52.h>
#include<intrins.h>
typedef  unsigned int  uint;
typedef  unsigned char uchar; 

sbit led=P0^0;

uint i;

void delay(uint i)
{
	while(i--);	
}
void Init_timer0_method0
{
	TMOD=0X20;
	TH0=6;
	TL0=6;
	EA=1;
	ET0=1;
	TR0=1;	
}	  
void main()
{  	
	Init_timer0_method0();
	while(1)
	{	 
	  if(i==4000)
	  {
	   i=0;
	   led=~led;
	  }
	}
}

void Timer0() interrupt 1
{	
	i++;
} 
*/