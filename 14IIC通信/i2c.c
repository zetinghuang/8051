#include"i2c.h"

/*******************************************************************************
* ������         : Delay10us()
* ��������		   : ��ʱ10us
* ����           : ��
* ���         	 : ��
*******************************************************************************/

void delay_10US()
{
	unsigned char a,b;
	for(b=1;b>0;b--)
		for(a=2;a>0;a--);

}
void iic_start()//��ʼ�ź��Ǽ��SCLΪ�ߵ�ƽʱSDA���½���,��SCL����
{
 	SDA=1;
 	delay_10US();
 	SCL=1;
 	delay_10US();
 	SDA=0;
 	delay_10US();
 	SCL=0;
}
void iic_end()//�����ź��Ǽ��SCLΪ�ߵ�ƽʱSDA��������
{
 	SDA=0;
 	delay_10US();
 	SCL=1;
 	delay_10US();
 	SDA=1;
 	delay_10US();
}

uchar iic_send_byte(uchar dat) //��������ʱÿ��ʱ�����ڷ���һλ�����ݣ��ȷ��ͺ���λ�������λ��ʼ����
{
 	uchar i,j;
 	for(i=0;i<8;i++)
 	{
  		SDA=dat>>7;//�����ȷ�������������λ��ĵ�һλ��Ҳ���Խ���������һλ�����λ��������PSW�Ĵ�����CYλ����CYλ��ֵ��������
 		dat<<=1;
  		delay_10US();//�ӳ�һ��ʱ��ʹ�����ȶ�
  		SCL=1;
  		delay_10US();//����ʱ�������ź�
  		SCL=0;
  		delay_10US();
 	}
 	SDA=1;//������Ϻ󣬽����������ߣ��ȴ�Ӧ��
 	delay_10US();

 /*��ʱ���źŸߵ�ƽʱ���ڣ���⵽SDAΪ�͵�ƽ��ΪӦ�𣬷���Ϊ��Ӧ��*/
 	SCL=1;
 	while(SDA)//���SDAΪ�͵�ƽ,������whileѭ��,����Ӧ��,ʱ���źſ������ͣ����ҷ���1��ʾӦ��
 	{
  		j++;
  		if(j>200)//�����涨ʱ�仹û���յ��͵�ƽ�����˳�ѭ����ʱ���ź����ͣ�����0��ʾ��Ӧ��
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
  	for(a=0;a<8;a++)//��������ʱ������λ�ٽ���
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
 	iic_start();//������ʼ�ź�
	iic_send_byte(0xa0); //����оƬ��������ַ������Ϊ��������ӻ�����
	iic_send_byte(addr); //�������ݶ�Ӧ���������׵�ַ
	iic_send_byte(dat); //��������
	iic_end();
}
uchar iic_receive_data(uchar addr)
{
 	iic_start();
	iic_send_byte(0xa0);//����оƬ��������ַ��ȷ���Ƿ���ȷ
	iic_send_byte(addr);//�����������׵�ַ��ȷ���Ƿ���ȷ
	iic_start();//���·�����ʼ�źţ���һ�����ı����ݴ��䷽��
	iic_send_byte(0xa1);//�������ͽ����������͵����ݵ�����ı䴫�䷽��
	num=iic_receive_byte();//�����ݶ�ȡ���ұ������ַ��ͱ�����
	iic_end();
	return num;
}