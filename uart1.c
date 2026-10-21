
#include"header.h"


void uart1_init(unsigned int baud)
        {
        unsigned int result,pclk;
        PINSEL0|=0X50000;    //89  0001 0100 0000 0000 0000
        pclk=60000000;
        if(VPBDIV==0)
                pclk=pclk/4;
        else if(VPBDIV==1)
                pclk=pclk/1;
        else if(VPBDIV==2)
                pclk=pclk/2;
        else
                pclk=60000000;
        result=(pclk/(16*baud));
        U1LCR=0X83;
        U1DLL=(result&0xff);
        U1DLM=((result&0xff00)>>8);
        U1LCR=0x3;
}
void uart1_tx(unsigned char a)
{
        while(((U1LSR>>5)&1)==0);
        U1THR=a;
}
unsigned char uart1_rx()
{
        while((U1LSR&0X1)==0);
        return U1RBR;
}
void uart1_tx_string(char *p)
{
        int i;
        for(i=0;p[i];i++)
        {
                uart1_tx(p[i]);
        }
}

void uart1_integer(int a)
{
 int ara[40];
 int i=0;
 if(a==0)
 uart1_tx('0');
 while(a)
 {
 ara[i++]=a%10;
 a=a/10;
 }
 i--;
 for(;i>=0;i--)
 {
 uart1_tx(ara[i]+48);
 }
}
void uart1_tx_hex(unsigned char data)
{
    unsigned char temp;

    temp = (data >> 4) & 0x0F;

    if(temp < 10)
        uart1_tx(temp + '0');
    else
        uart1_tx(temp - 10 + 'A');

    temp = data & 0x0F;

    if(temp < 10)
        uart1_tx(temp + '0');
    else
        uart1_tx(temp - 10 + 'A');
}

