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

void LCD_WRITE_COM(uchar com)  //д������
{
	LCD1602_E = 0;     //ʹ��
	LCD1602_RS = 0;	   //ѡ��������
	LCD1602_RW = 0;	   //ѡ��д��
	
	LCD1602_DATAPINS = com;     //��������
	lcd1602_delay1ms(1);		//�ȴ������ȶ�

	LCD1602_E = 1;	          //д��ʱ��
	lcd1602_delay1ms(5);	  //����ʱ��
	LCD1602_E = 0;
}


void LCD_WRITE_DATA(uchar dat)			//д������
{
	LCD1602_E = 0;	//ʹ������
	LCD1602_RS = 1;	//ѡ����������
	LCD1602_RW = 0;	//ѡ��д��

	LCD1602_DATAPINS = dat; //д������
	lcd1602_delay1ms(1);

	LCD1602_E = 1;   //д��ʱ��
	lcd1602_delay1ms(5);   //����ʱ��
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
