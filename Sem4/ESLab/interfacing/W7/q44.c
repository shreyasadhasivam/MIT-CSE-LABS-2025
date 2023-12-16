#include <LPC17xx.h>

unsigned int i,j, k, l;
unsigned char array_dec[16]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x77,0x7C, 0x39, 0x5E, 0x79,0x71};
//unsigned int seg_select[4] = {0, 1, 2 ,3};
//unsigned int dig_select[4] = {4, 3, 2 ,1};
int output_arr[4] = {9,9,9,9};

int main() {
    SystemInit(); //Add these two function for its internal operation
    SystemCoreClockUpdate();
    
    LPC_GPIO0->FIODIR |= 0xFF0;  // select led to display
    LPC_GPIO0->FIODIR |= 0XF<<15;  // which seven segment to use
    
    while (1){
        
        for (output_arr[3] =15 ; output_arr[3]>=0; output_arr[3]--){
            for (output_arr[2] =15 ; output_arr[2]>=0; output_arr[2]--){
                for (output_arr[1] =15 ; output_arr[1]>=0; output_arr[1]--){
                    for (output_arr[0] =15 ; output_arr[0]>=0; output_arr[0]--){
                        for (i = 0; i<4;i++){
                            
                            if (LPC_GPIO2->FIOPIN & (1<<12)){
                                LPC_GPIO0->FIOPIN = i<<15;
                                LPC_GPIO0->FIOPIN |= array_dec[output_arr[i]]<<4;
                            }
                            
                            else{
                                LPC_GPIO0->FIOPIN = i<<15;
                                LPC_GPIO0->FIOPIN |= array_dec[15-output_arr[i]]<<4;
                            }
                        
                            for (j =0 ; j<50000; j++);
                        }
                    }
                }
            }
        }
    
   
    }
}