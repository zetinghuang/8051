
#include "reg52.h"			 
typedef unsigned int uint;	  
typedef unsigned char uchar;

#define key P1
#define smg P0

uchar code smgduan[16]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90,0x88,0x83,0xC6,0xA1,0x86,0x8E};
uchar keyvalue;

void delay(uint i)
{
	while(i--);	
}


 void button()
{	uint a;
	key=0x0f;
	if(key!=0x0f)
		{
		 delay(1000);
		 if(key!=0x0f)
		 	{
			 switch(key)
			 	{
				 case(0x07):keyvalue=0;break;
				 case(0x0b):keyvalue=1;break;
				 case(0x0d):keyvalue=2;break;
				 case(0x0e):keyvalue=3;break;
				}
			}
		}
	key=0xf0;
	if(key!=0xf0)
		{
		 delay(10);
		 if(key!=0xf0)
		 	{
			 switch(key)
			 	{
				 case(0x70):keyvalue=keyvalue;break;
				 case(0xb0):keyvalue=keyvalue+4;break;
				 case(0xd0):keyvalue=keyvalue+8;break;
				 case(0xe0):keyvalue=keyvalue+12;break;
				}
			}
		}
		while((a<50)&&(key!=0xf0))
		{
		 delay(100);
		 a++;
		}
				
}


void main()
{	

		while(1)
		{
		button();
		smg=smgduan[keyvalue];
		}			
}
