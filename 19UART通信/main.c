/*����UART����ͨ�ţ�ʵ��8051�����������ݻ���ʵ�飬�������8051����һ���ֽڵ����ݣ���8051�յ�������������I get ���յ�������*/
#include <reg52.h>
#include<intrins.h>
typedef  unsigned int  uint;
typedef  unsigned char uchar; 

uchar a,flag,i;
uchar code command[]="I get " //�����ַ��������Ա㷢�����ݣ�һ��������Ч�����ֽڣ�����4��Ӣ�ĺ�2���ո�

void delay(uint i)
{
	while(i--);	
}
void Init_serial_communication()
{
	TMOD=0x20;//����8λ��ֵ�Զ���װ�Ķ�ʱ������					
	TH1=0xfd;
	TL1=0xf9;
	EA=1;
	ES=1;
	TR1=1;
	REN=1;
	SM0=0;
	SM1=1;	
}	  
void main()
{  	Init_serial_communication();
	while(1)
	{	 
	 if(flag==1)
	 {	ES=0;
	  	for(i=0;i<6;i++)
		{
		 	SBUF=command[i];
			while(!TI);
			TI=0;
		}
		SBUF=a;
		while(!TI);
		TI=0;
		flag=0;
		ES=1;
	 }	
	}
}

void Receive() interrupt 4
{	RI=0;
	a=SBUF;
	flag=1;
} 