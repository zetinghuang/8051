#include <reg52.h>
#include<intrins.h>
typedef  unsigned int  uint;
typedef  unsigned char uchar; 
sbit beep=P0^0;
sbit relay=P0^1;

void delay(uint i)
{
	while(i--);	
}
	  

void main()
{  	
	while(1)
	{	
		relay=0;
		//beep=~beep;		 
		delay(50);
}
}
