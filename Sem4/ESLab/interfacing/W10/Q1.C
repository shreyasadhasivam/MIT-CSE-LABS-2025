#include <LPC17xx.h>
void initPWM(void);
void updatePulseWidth(unsigned int pulseWidth);
void delayMS(unsigned int milliseconds);

int main(void)
{
	unsigned long int temp3;
	initPWM();
	LPC_GPIO0->FIODIR |= 0x00000F00;
	while(1)
	{
		LPC_GPIO0->FIOSET = 0x00000100;
		temp3 = LPC_GPIO0->FIOPIN;
		temp3 &= 0x000000F0;
		temp3 >>= 4;
		if(temp3 == 1)
		{
			updatePulseWidth(3000);
			delayMS(10000);
		}
		else if(temp3 == 2)
		{
			updatePulseWidth(7500);
			delayMS(10000);
		}
		else if(temp3 == 4)
		{
			updatePulseWidth(15000);
			delayMS(10000);
		}
		else if(temp3 == 8)
		{
			updatePulseWidth(30000);
			delayMS(10000);
		}
}

}
void initPWM(void)
{
    /*Assuming that PLL0 has been setup with CCLK = 100Mhz and PCLK = 25Mhz.*/

    LPC_PINCON->PINSEL3 |= (2<<14); //Select PWM1.4 output for Pin1.23
    LPC_PWM1->PCR = 0x0; //Select Single Edge PWM - by default its single Edged so this line can be removed
    LPC_PWM1->PR = 0; //1 micro-second resolution PCLK=1MHZ
    LPC_PWM1->MR0 = 30000; //30000us = 30ms period duration
    LPC_PWM1->MCR = (1<<1); //Reset PWM TC on PWM1MR0 match
    LPC_PWM1->LER = (1<<0); //update values in MR0
    LPC_PWM1->PCR = 0x1000; //enable PWM output
    LPC_PWM1->TCR = (1<<1); //Reset PWM TC & PC

    LPC_PWM1->TCR = (1<<0) | (1<<3); //enable TC and PC and PWM Mode

    //PWM Generation goes active now!
    //Now you can get the PWM output on Pin P1.23
}
void updatePulseWidth(unsigned int pulseWidth)
{
	LPC_PWM1->MR4 = pulseWidth; //Update MR4 with new value
	LPC_PWM1->LER = 0xff; //Load the MR4 new value at start of next cycle
}
void delayMS(unsigned int milliseconds) //Using Timer0
{
	LPC_TIM0->CTCR = 0x0; //Timer mode
	LPC_TIM0->PR = 2; //Increment TC at every 3 pclk

	LPC_TIM0->TCR = 0x02; //Reset Timer
	LPC_TIM0->TCR = 0x01; //Enable timer
	while(LPC_TIM0->TC < milliseconds); //wait until timer counter reaches the desired delay
	LPC_TIM0->TCR = 0x00; //Disable timer
}