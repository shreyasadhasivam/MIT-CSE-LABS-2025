#include <LPC17xx.h>

unsigned int i,j, k, l;
unsigned char array_dec[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};


int output_arr[4] = {9,9,9,9};

int main() {
    SystemInit(); 
    SystemCoreClockUpdate();
    
    LPC_GPIO0->FIODIR |= 0xFF0;
    LPC_GPIO0->FIODIR |= 0XF<<15;
    
    while (1){
        
        for (output_arr[3] =9 ; output_arr[3]>=0; output_arr[3]--)
				{
            for (output_arr[2] =9 ; output_arr[2]>=0; output_arr[2]--)
						{
                for (output_arr[1] =9 ; output_arr[1]>=0; output_arr[1]--)
								{
                    for (output_arr[0] =9 ; output_arr[0]>=0; output_arr[0]--)
										{
                        for (i = 0; i<4;i++)
												{
                            
                            if (LPC_GPIO2->FIOPIN & (1<<12))
															{
                                LPC_GPIO0->FIOPIN = i<<15;
                                LPC_GPIO0->FIOPIN |= array_dec[output_arr[i]]<<4;
															}
                            
                            else
															{
                                LPC_GPIO0->FIOPIN = i<<15;
                                LPC_GPIO0->FIOPIN |= array_dec[9-output_arr[i]]<<4;
															}
                        
                            for (j =0 ; j<10000; j++);
                        }
                    }
                }
            }
        }
			}
		}
    