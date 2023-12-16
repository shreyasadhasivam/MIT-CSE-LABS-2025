#include <LPC17xx.h>

unsigned char array_dec[10]={0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D,0x7d , 0X07, 0X7F , 0x6F};
unsigned int dig_value[4] = {4,3,2,1};
unsigned int disp_select[4] ={0,1,2,3};

void delay(void);
void display(void);
unsigned int i;
int main(void)
{
	
	SystemInit();
	SystemCoreClockUpdate();
	LPC_GPIO0->FIODIR |= 0xFF<<4;
	LPC_GPIO1->FIODIR |= 0xF<<23;
	
	while(1)
	{
		
		for(i=0;i<4;i++)
		{
			
			display();
			delay();
		}
		
	}
}

void display(void)
{
	LPC_GPIO1->FIOPIN = disp_select[i]<<23;
	LPC_GPIO0->FIOPIN=array_dec[dig_value[i]]<<4;
}

void delay(void)
{
	unsigned int j;
	for(j=0;j<500;j++);
}