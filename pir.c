
#include"header.h"

int pir_xor=1;
void pir_exte_int_hand() __irq
{
EXTINT|=(1<<3);
EXTPOLAR^=(1<<3);
if(pir_xor==1)
{
buzzeron();
pirv=1;
//motiondetect_print();
}
else
{
buzzeroff();
pirv=0;
}
pir_xor^=1;
VICVectAddr=0;
}


void pir_exte_int_init()
{
 PINSEL1|=(3<<8);        //15 3
 VICIntSelect|=0;
 EXTMODE|=(1<<3);
 EXTPOLAR|=(1<<3);
 VICVectCntl3=17|(1<<5);
 VICVectAddr3=(unsigned int)pir_exte_int_hand;
 VICIntEnable|=(1<<17);
}

