#include <LPC17xx.h>
unsigned int i,j;
unsigned long LED;

int main(void)                                                                                                                                                                                   
{
	SystemInit();
	SystemCoreClockUpdate();
	
	LPC_PINCON->PINSEL0 &= 0xFF0000FF;
	
	LPC_GPIO0->FIODIR |= 0x00000FF0;
	
	LPC_PINCON->PINSEL4 &= 0XFCFFFFFF;
	LPC_GPIO2->FIODIR &= 0XFFFFEFFF;
	
	
	
	while(1)
	{
		if(LPC_GPIO2->FIOPIN & 1<<12)
		{
			for(LED=255;LED>=0;LED--)
			{
				LPC_GPIO0->FIOPIN=LED<<4;
			             
				for(j=0;j<3000;j++);
			}
		}
		else
		{
			for(LED=0;LED<=255;LED++)
			{
				LPC_GPIO0->FIOPIN=LED<<4;
			             
				for(j=0;j<3000;j++);
			}
		}
	}
	return 0;
}