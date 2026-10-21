#include"header.h"

void delay_ms(int a)
{
         unsigned int pclk;
     pclk=60000000;
         if(VPBDIV==0)
                pclk=pclk/4;
         else if(VPBDIV==1)
                pclk=pclk/1;
     else if(VPBDIV==2)
                pclk=pclk/2;
         else
            pclk=15000000;
         pclk=pclk/1000;

         T0TC=0;
         T0PC=0;
         T0PR=pclk-1;
         T0TCR=1;
         while(T0TC<a);
         T0TC=0;
}
void delay_sec(int a)
{
         unsigned int pclk;
     pclk=60000000;
         if(VPBDIV==0)
                pclk=pclk/4;
         else if(VPBDIV==1)
                pclk=pclk/1;
     else if(VPBDIV==2)
                pclk=pclk/2;
         else
            pclk=15000000;
         T0TC=0;
         T0PC=0;
         T0PR=pclk-1;
         T0TCR=1;
         while(T0TC<a);
         T0TC=0;
}
void delay_us(int a)
{
         unsigned int pclk;
     pclk=60000000;
         if(VPBDIV==0)
                pclk=pclk/4;
         else if(VPBDIV==1)
                pclk=pclk/1;
     else if(VPBDIV==2)
                pclk=pclk/2;
         else
            pclk=15000000;


         T0TC=0;
         T0PC=0;
         T0PR=(pclk/1000000)-1;
         T0TCR=1;
         while(T0TC<a);
         T0TC=0;
}




