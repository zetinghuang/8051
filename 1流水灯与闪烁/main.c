#include <reg52.h>
#include<intrins.h>
typedef  unsigned int  uint;
typedef  unsigned char uchar; 
#define led P0

void delay(uint i)
{
	while(i--);	
}
	  

void main()
{  	uchar i;
	led=~0x01;
	delay(50000); //大约延时450ms	
	while(1)
	{	
		for(i=0;i<8;i++)
		{
			P0=~(0x01<<i);	 //将1右移i位，然后将结果赋值到P0口
			delay(500000); //大约延时450ms
		}
}
}
