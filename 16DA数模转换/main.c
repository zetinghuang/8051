//PWMÊä³öÊ¹LED³ÊÏÖºôÎüµÆ×´Ì¬
#include <reg52.h>
#include<intrins.h>
typedef  unsigned int  uint;
typedef  unsigned char uchar; 
sbit PWM=P2^1;
bit DIR;

uint count,value,timer1;

void TimerInit()
{
 TMOD|=0X10;
 TH1=0XFF;
 TL1=0XFF;
 ET1=1;
 EA=1;
 TR1=1;
}	  

void main()
{  	TimerInit();
	while(1)
	{
	 	if(count>100)
		{
		 	count=0;
			if(DIR==1)
				{
				 	value++;
				}
			 if(DIR==0)
				{
					value--;
				}
		}
		if(value==100)
		{
		 	DIR=0;
		}		
		if(value==0)
		{
		 	DIR=1;
		}
		if(timer1>500)
		{
		 	timer1=0;
		}
		else if(timer1<value)
		{
		 	PWM=1;
		}
		else
		{
		 	PWM=0;
		}	
	}

}

void Time1(void) interrupt 3
{
 	TH1=0XFF;
	TL1=0XFF;
	timer1++;
	count++;
}
