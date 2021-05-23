
#include "reg52.h"			 
typedef unsigned int uint;	  
typedef unsigned char uchar;

sbit key=P0^0;
sbit led=P0^1;
void delay(uint i)
{
	while(i--);	
}


void button()
{	if(key==0)
	{
	 delay(10);
	 if(key==0)
	 	{
		 led=~led;
		}
	}

	
}


void main()
{	

	
		button();
		while(!key);			
}
