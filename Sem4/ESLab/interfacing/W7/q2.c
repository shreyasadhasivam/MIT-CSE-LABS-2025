#include <LPC17xx.h>

unsigned char to_hex[10]={0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D,0x7d , 0X07, 0X7F , 0x6F};
int arr[4]={0,0,0,0};
unsigned int i,j;
int main(void)
{
	
	SystemInit();
	SystemCoreClockUpdate();
	LPC_GPIO0->FIODIR |= 0xFF0;
	LPC_GPIO1->FIODIR |= 0xF<<23;
	
	while(1)
	{
		for(arr[3]=0;arr[3]<10;arr[3]++)
		{
			for(arr[2]=0;arr[2]<10;arr[2]++)
			{
				for(arr[1]=0;arr[1]<10;arr[1]++)
				{
					for(arr[0]=0;arr[0]<10;arr[0]++)
					{
						for(i=0;i<4;i++)
						{
							LPC_GPIO1->FIOPIN=i<<23;
							LPC_GPIO0->FIOPIN=to_hex[arr[i]]<<4;
							for(j=0;j<100000;j++);
						}
						for(j=0;j<100000;j++);
						LPC_GPIO0->FIOCLR |= 0x00FF0;
					}
				}
			}
		}
	}
}

