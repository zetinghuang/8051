static unsigned char i=0;
P0=0XFF;

void INIT_INFRARED()
{
	IR_INPUT=1;
	TMOD|=0X10;
	TR1=0;
	ET1=0;
	IT1=1;
	EX1=1;
}
uint GET_HIGH_TIME()
{
 	TH1=0;
	TL1=0;
	TR1=1;
	while(IR_INPUT);
	{
	 if(TH1>0x40)
	 {
	  	break;
	 }
	}
	TR1=0;
	return(TH1*256+TL1);
}
uint GET_LOW_TIME()
{
 	TH1=0;
	TL1=0;
	TR1=1;
	while(!IR_INPUT);
	{
	 if(TH1>0x40)
	 {
	  	break;
	 }
	}
	TR1=0;
	return(TH1*256+TL1);	
}
void EXINT1_ISR() interrupt 2
{
 	uchar i,j;
	uint time;
	uchar byt;

	time=GET_LOW_TIME();
	if((time<7833)||(time>8755))
	{
	 	IE1=0;
		return;
	}
	time=GET_HIGH_TIME();
	if((time<3686)||(time>4608))
	{
	  IE1=0;
	  return;
	}
	for(i=0;i<4;i++)
	{
	 	for(j=0;j<8;j++)
		{
		 	time=GET_LOW_TIME();
			if((time<313)||(time>718))
			{
			 	IE1=0;
				return;
			}
			time=GET_HIGH_TIME()			
			if((time>313)&&(time<718))
			{
				byt>>=1;	 	
			}
			else if((time>1345)&&(time<1751))
			{
			 	byt>>=1;
				byt|=0x80;
			}
			else
			{
			 	IE1=0;
				return;
			}	
		}
		Ircode[i]=byt;
	}
	irflag=1;
	IE=0;
}