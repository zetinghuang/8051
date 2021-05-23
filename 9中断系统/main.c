#include <reg52.h>
#include<intrins.h>
typedef  unsigned int  uint;
typedef  unsigned char uchar; 
sbit key=P3^2;
sbit beep=P0^0;

void delay(uint i)
{
	while(i--);	
}
void Init0time()
{
  IT0=1;
  EA=1;
  EX0=1;
}	  
void main()
{  	
while(1)
{	 beep=0;
	 Init0time();
	   }
}

void Init0() interrupt 0
{	 delay(100);
 	if(key==0)
	{
	 	beep=1;
	}
} 