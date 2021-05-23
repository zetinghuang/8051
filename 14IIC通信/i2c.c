#include"i2c.h"

/*******************************************************************************
* 函数名         : Delay10us()
* 函数功能		   : 延时10us
* 输入           : 无
* 输出         	 : 无
*******************************************************************************/

void delay_10US()
{
	unsigned char a,b;
	for(b=1;b>0;b--)
		for(a=2;a>0;a--);

}
void iic_start()//起始信号是检测SCL为高电平时SDA的下降沿,后将SCL拉高
{
 	SDA=1;
 	delay_10US();
 	SCL=1;
 	delay_10US();
 	SDA=0;
 	delay_10US();
 	SCL=0;
}
void iic_end()//结束信号是检测SCL为高电平时SDA的上升沿
{
 	SDA=0;
 	delay_10US();
 	SCL=1;
 	delay_10US();
 	SDA=1;
 	delay_10US();
}

uchar iic_send_byte(uchar dat) //发送数据时每个时钟周期发送一位的数据，先发送后移位，由最高位开始发送
{
 	uchar i,j;
 	for(i=0;i<8;i++)
 	{
  		SDA=dat>>7;//可以先发送数据右移七位后的第一位，也可以将数据左移一位，最高位将储存在PSW寄存器的CY位，将CY位赋值给数据线
 		dat<<=1;
  		delay_10US();//延迟一定时间使数据稳定
  		SCL=1;
  		delay_10US();//制造时钟脉冲信号
  		SCL=0;
  		delay_10US();
 	}
 	SDA=1;//发送完毕后，将数据线拉高，等待应答
 	delay_10US();

 /*在时钟信号高电平时间内，检测到SDA为低电平则为应答，否则为非应答*/
 	SCL=1;
 	while(SDA)//如果SDA为低电平,则跳出while循环,器件应答,时钟信号可以拉低，并且返回1表示应答
 	{
  		j++;
  		if(j>200)//超过规定时间还没有收到低电平，则退出循环，时钟信号拉低，返回0表示非应答
  		{
   			SCL=0;
   			delay_10US();
   			return 0;
  		}
 	}
 	SCL=0;
 	delay_10US();
 	return 1;
}

uchar iic_receive_byte()
{
  	uchar a,dat;
  	SDA=1;
  	delay_10US();
  	for(a=0;a<8;a++)//接收数据时，先移位再接收
  	{
  		dat<<=1;
  		dat=SDA;
  		delay_10US();
  		SCL=1;
  		delay_10US();
  		SCL=0;
  		delay_10US();
  	}
  	return dat;
}

void iic_send_data(uchar addr, uchar dat)
{
 	iic_start();//发出起始信号
	iic_send_byte(0xa0); //发出芯片的器件地址，方向为由主机向从机发送
	iic_send_byte(addr); //发出数据对应储存区的首地址
	iic_send_byte(dat); //发出数据
	iic_end();
}
uchar iic_receive_data(uchar addr)
{
 	iic_start();
	iic_send_byte(0xa0);//发出芯片的器件地址，确认是否正确
	iic_send_byte(addr);//发出储存区首地址，确认是否正确
	iic_start();//重新发送起始信号，下一步将改变数据传输方向
	iic_send_byte(0xa1);//主机发送接收器件发送的数据的命令，改变传输方向
	num=iic_receive_byte();//将数据读取并且保存在字符型变量中
	iic_end();
	return num;
}