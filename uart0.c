
#include"header.h"

void uart_init(unsigned int baud)
        {
        unsigned int result,pclk;
        PINSEL0|=0X5;
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
        U0LCR=0X83;
        U0DLL=(result&0xff);
        U0DLM=((result&0xff00)>>8);
        U0LCR=0x3;
}
void uart_tx(unsigned char a)
{
        while(((U0LSR>>5)&1)==0);
        U0THR=a;
}
unsigned char uart_rx()
{
        while((U0LSR&0X1)==0);
        return U0RBR;
}
void uart_tx_string(char *p)
{
        int i;
        for(i=0;p[i];i++)
        {
                uart_tx(p[i]);
        }
}

void uart_integer(int a)
{
 int ara[40];
 int i=0;
 if(a==0)
 uart_tx('0');
 while(a)
 {
 ara[i++]=a%10;
 a=a/10;
 }
 i--;
 for(;i>=0;i--)
 {
 uart_tx(ara[i]+48);
 }
}
void uart_tx_hex(unsigned char data)
{
    unsigned char temp;

    temp = (data >> 4) & 0x0F;

    if(temp < 10)
        uart_tx(temp + '0');
    else
        uart_tx(temp - 10 + 'A');

    temp = data & 0x0F;

    if(temp < 10)
        uart_tx(temp + '0');
    else
        uart_tx(temp - 10 + 'A');
}

