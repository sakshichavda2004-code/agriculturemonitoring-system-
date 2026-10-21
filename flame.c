#include"header.h"
int flame_xor=0;
void flame_exte_int_hand() __irq
{
EXTINT|=(1<<2);
EXTPOLAR^=(1<<2);
if(flame_xor==0)
{
buzzeron();
flamev=1;
//firedetect_print();
}
else
{
buzzeroff();
flamev=0;
}
flame_xor^=1;
VICVectAddr=0;

}


void flame_exte_int_init()
{
 PINSEL0|=(2<<30);       //15 3
 VICIntSelect|=0;
 EXTMODE|=(1<<2);
 EXTPOLAR|=(0<<2);
 VICVectCntl1=16|(1<<5);
 VICVectAddr1=(unsigned int)flame_exte_int_hand;
 VICIntEnable|=(1<<16);
}
