#include"ADC.h"

/*
void DELAY10US()
{
	unsigned char a,b;
	for(b=1;b>0;b--)
		for(a=2;a>0;a--);

}
*/
void SENDBYTE(uchar dat)
{
	uint i;
	CLK=0;
	for(i=0;i<8;i++)
	{
	 	DIN=dat>>7;
		dat<<=1;
		CLK=0;
		CLK=1;
	}

}

uint RECEIVEBYTE(void)
{
	uint j,dat=0;
	CLK=0;
	for(j=0;j<12;j++)
	{
	 	dat<<=1;
		CLK=1;
		CLK=0;
		dat|=DOUT;
	}
	return dat;
}

uint ADCREAD(uchar cmd)
{
 	uint AD_VAL; uchar i;
	CLK=0; CS=0;
	SENDBYTE(cmd);
	for(i=6;i>0;i--);
	CLK=1;
	_nop_();
	_nop_();
	CLK=0;
	_nop_();
	_nop_();
	AD_VAL=RECEIVEBYTE;
	CS=1;
	return AD_VAL;
}