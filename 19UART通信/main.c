/*利用UART串口通信，实现8051与计算机的数据环回实验，计算机向8051发送一个字节的数据，在8051收到后，向计算机发送I get 加收到的数据*/
#include <reg52.h>
#include<intrins.h>
typedef  unsigned int  uint;
typedef  unsigned char uchar; 

uchar a,flag,i;
uchar code command[]="I get " //定义字符串数组以便发送数据，一共六个有效数据字节，包括4个英文和2个空格

void delay(uint i)
{
	while(i--);	
}
void Init_serial_communication()
{
	TMOD=0x20;//采用8位初值自动重装的定时计数器					
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