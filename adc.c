
#include"header.h"

void adc_init()
{
PINSEL1|=0X15400000;
ADCR=0X00200400;
}

unsigned int adc_read(int chno)
{
unsigned int result=0;
ADCR|=(1<<chno);
ADCR|=(1<<24);
while(((ADDR>>31)&1)==0);
ADCR^=(1<<24);
ADCR^=(1<<chno);
result=((ADDR>>6)&0X3FF);
return result;
}
