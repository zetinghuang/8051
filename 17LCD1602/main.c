/*Һ����ʾ��ʵ��hello world ������ʾ���ұ���������Ƴ�*/
#include <reg52.h>			 //���ļ��ж����˵�Ƭ����һЩ���⹦�ܼĴ���
#include <LCD1602.h>	
	
 uchar disp[]="Hello World";

void main()
{	
	uchar i;
	LCD_INIT();
	LCD_WRITE_COM(0x80+0x40); 
	for(i=0;i<11;i++)
	{
	 	LCD_WRITE_DATA(disp[i]);
	}
	LCD_WRITE_COM(0x07);
	LCD_WRITE_COM(0x0f+0x80);
	while(1)
	{	for(i=0;i<16;i++)
	{
	 	LCD_WRITE_DATA(disp[i]);
		lcd1602_delay1ms(100);

	}
}
}