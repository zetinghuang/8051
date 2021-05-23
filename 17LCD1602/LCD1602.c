#include"LCD1602.h"


void lcd1602_delay1ms(uint c)
{
	uchar a,b;
	for(;c>0;c--)
	{
	 	for(b=199;b>0;b--)
		{
		 	for(a=1;a>0;a--);
		}
	}

}

void LCD_WRITE_COM(uchar com)  //写入命令
{
	LCD1602_E = 0;     //使能
	LCD1602_RS = 0;	   //选择发送命令
	LCD1602_RW = 0;	   //选择写入
	
	LCD1602_DATAPINS = com;     //放入命令
	lcd1602_delay1ms(1);		//等待数据稳定

	LCD1602_E = 1;	          //写入时序
	lcd1602_delay1ms(5);	  //保持时间
	LCD1602_E = 0;
}


void LCD_WRITE_DATA(uchar dat)			//写入数据
{
	LCD1602_E = 0;	//使能清零
	LCD1602_RS = 1;	//选择输入数据
	LCD1602_RW = 0;	//选择写入

	LCD1602_DATAPINS = dat; //写入数据
	lcd1602_delay1ms(1);

	LCD1602_E = 1;   //写入时序
	lcd1602_delay1ms(5);   //保持时间
	LCD1602_E = 0;
}



void LCD_INIT()
{	/*
	LCD_WRITE_COM(0x32);
	LCD_WRITE_COM(0x28);
	LCD_WRITE_COM(0x0c);
	LCD_WRITE_COM(0x06);
	LCD_WRITE_COM(0x01);
	LCD_WRITE_COM(0x80);
	 */
	LCD1602_E=0;
	LCD_WRITE_COM(0x38);
	LCD_WRITE_COM(0x0c);
	LCD_WRITE_COM(0x06);
	LCD_WRITE_COM(0x01); 
}
