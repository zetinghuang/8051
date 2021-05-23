/**************************************************************************************
实验现象：下载程序后数码管后4位显示0，按K1保存显示的数据，按K2读取上次保存的数据，
		  按K3显示数据加一，按K4显示数据清零。最大能写入的数据是255
		  
接线说明： (具体接线图可见开发攻略对应实验的“实验现象”章节)
		   1，单片机-->EEPROM模块
		   		P20-->SDA
				P21-->SCL
		   2，单片机-->动态数码管模块
		   		J22-->J6
				P22-->J9(A)
				P23-->J9(B)
				P24-->J9(C)
		   3，单片机-->独立按键模块
		   		P30-->K2
				P31-->K1
				P32-->K3
				P33-->K4	
	
注意事项：																				  
***************************************************************************************/

#include "reg52.h"			 //此文件中定义了单片机的一些特殊功能寄存器
#include "i2c.h"
	
//#define P0	smg 
uint key_val=4;
sbit LSA=P2^2;
sbit LSB=P2^3;
sbit LSC=P2^4;
sbit key0=P3^0;
sbit key1=P3^1;
sbit key2=P3^2;
sbit key3=P3^3;
   
	
uint display_data=0;
uchar addr=0x01;
uchar code smgwei[8]={0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};
uchar code smgduan[16]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90,0x88,0x83,0xC6,0xA1,0x86,0x8E};//显示0~F的值
uchar disp[4];


void delay(uint i)
{
 	while(i--);
}
uint key_check()
{
	while(key0||key1||key2||key3!=1)
	{
		delay_10US();
		while(key0||key1||key2||key3!=1)
		{
		 	if(!key0)
				{
					key_val=0;
				}
			if(!key1)
				{
					key_val=1;
				}
			if(!key2)
				{
					key_val=2;
				}
			if(!key3)
				{
					key_val=3;					
				}
		}
	}
	while(!key0||!key1||!key2||!key3);	
	return key_val;		
}
void data_pros()
{
	disp[0]=smgduan[display_data/1000];
	disp[1]=smgduan[display_data/100];
	disp[2]=smgduan[display_data/10%10];
	disp[3]=smgduan[display_data%10];	
}
void smg_change()
{
	if(key_val==0)
	{
		iic_send_data(addr, display_data);	
	}
	else if(key_val==1)
	{
		iic_receive_data(addr);
	}
	else if(key_val==2)
	{	
		if(display_data<255)
		{
			display_data++;
		}
		else
			display_data--;
	}
	else if(key_val==3)
	{
		display_data=0;
	}
}
void smg()
{	uchar i;

	for(i=0;i<4;i++)
	{ 		 
	 switch(i)
	 	{
		 	case(0):LSA=0;LSB=0;LSC=0;break;
			case(1):LSA=1;LSB=0;LSC=0;break;
			case(2):LSA=0;LSB=1;LSC=0;break;
			case(3):LSA=1;LSB=1;LSC=0;break;
		}  
	  	P0=disp[i];
	  	delay(100);
	  	P0=0xff;
	}
}


void main()
{	
	while(1)
	{
		data_pros();
		smg();
		key_check();
		smg_change();			
	}		
}

