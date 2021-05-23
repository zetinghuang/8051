#include "temp.h"

void delayms(uint y)
{
  uint x;
	for( ; y>0; y--)
	{
		for(x=110; x>0; x--);
	}
}

uchar DSB18B20_init()
{
 uint i;
 DSBUS=0;
 i=70;
 while(i--);
 DSBUS=1;
 i=0;
 while(DSBUS)
 {
  delayms(1); 
  i++;
  if(i>5)
  {
   	return 0;
  }
 }
 return 1;
}


