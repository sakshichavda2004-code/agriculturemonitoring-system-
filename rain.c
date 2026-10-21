
#include"header.h"

int rain_xor=0;
void rain_exte_int_hand() __irq
{
EXTINT=(1<<1);

EXTPOLAR^=(1<<1);

if(rain_xor==0)
{
rainv=1;
pumpv=0;
}
else
{
rainv=0;
//raindetect_print();
pump_on(0);
}
rain_xor^=1;
VICVectAddr=0;
}


void rain_exte_int_init()
{

 PINSEL0|=(2<<28);       //14 3
 VICIntSelect|=0;
 EXTMODE|=(1<<1);
 EXTPOLAR|=0;
 VICVectCntl2=15|(1<<5);
 VICVectAddr2=(unsigned int)rain_exte_int_hand;
 VICIntEnable|=(1<<15);
}
