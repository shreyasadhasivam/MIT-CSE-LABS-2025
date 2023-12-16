#include <LPC17xx.h>
int i,j;
unsigned char to_hex[16]={0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D,0x7d , 0X07, 0X7F , 0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71};
int d[4];

int main(void)
{
	
	SystemInit();
	SystemCoreClockUpdate();
	LPC_PINCON->PINSEL0 &= 0xFF0000FF;
	LPC_GPIO1->FIODIR |= 0xF<<23;
	LPC_PINCON->PINSEL1=0xFFFFF3FF;
	LPC_GPIO0->FIODIR |= 0x0<<21;

	
	
	while(1)
	{
		unsigned int k=((LPC_GPIO0->FIOPIN)&(1<<21));
		if(k==0)
		{
			for(d[3]=0;d[3]<16;d[3]++)
			{
			for(d[2]=0;d[2]<16;d[2]++)
			{
				for(d[1]=0;d[1]<16;d[1]++)
				{
					for(d[0]=0;d[0]<16;d[0]++)
					{
						for(i=0;i<4;i++)
						{
							LPC_GPIO1->FIOPIN=i<<23;
							LPC_GPIO0->FIOPIN=to_hex[d[i]]<<4;
							for(j=0;j<10;j++);
						}
						for(j=0;j<1000;j++);
						LPC_GPIO0->FIOCLR |= 0x00FF0;
					}
				}
			}
		}
	}
}
}


