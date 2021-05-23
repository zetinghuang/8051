#include"DS1302.h"

uchar code READ_ADDR[7]={0x81,0x83,0x85,0x87,0x89,0x8b,0x8d};
uchar code WRITE_ADDR[7]={0x80,0x82,0x84,0x86,0x88,0x8a,0x8c};

uchar TIME[7]={0,0,0x12,0x07,0x05,0x06,0x16};

void DS1302_WRITE(uchar addr, uchar dat)
{
	uchar i;
	CE=0;
	_nop_();
	CLK=0;
	_nop_();
	CE=1;
	_nop_();
	for(i=0;i<8;i++)
	{
	 	IO=addr&0x01;
		addr>>=1;
		CLK=1;
		_nop_();
		CLK=0;
		_nop_();
	}
	for(i=0;i<8;i++)
	{
	 	IO=dat&0x01;
		dat>>=1;
		CLK=1;
		_nop_();
		CLK=0;
		_nop_();
	}
	CE=0;
	_nop_();

}

uint DS1302_RECEIVE(uchar addr)
{
	uchar i,dat,dat1;
	CE=0;
	_nop_();
	CLK=0;
	_nop_();
	CE=1;
	_nop_();
	for(i=0;i<8;i++)
	{
	 	IO=addr&0x01;
		addr>>=1;
		CLK=1;
		_nop_();
		CLK=0;
		_nop_();
	}
	for(i=0;i<8;i++)
	{
	 	dat1=IO;
		dat=(dat>>1)|(dat1<<7);
		CLK=1;
		_nop_();
		CLK=0;
		_nop_();
	}
	CE=0;
	_nop_(); 
	CLK=1;
	_nop_();
	return dat;

}

void DS1302_INIT()
{
 	uchar i;
	DS1302_WRITE(0x8E,0x00);
	for (i=0;i<7;i++)
	{
	 	DS1302_WRITE(WRITE_ADDR[i],TIME[i]);
	}
	DS1302_WRITE(0x8e,0x80);
}

void DS1302_READ_TIME()
{
 uchar i;
 for(i=0;i<7;i++)
 {
  	TIME[i]=DS1302_RECEIVE(READ_ADDR[i]);
 }
}