/*液晶显示屏实现hello world 滚动显示，右边移入左边移出*/
#include <reg52.h>			 //此文件中定义了单片机的一些特殊功能寄存器
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