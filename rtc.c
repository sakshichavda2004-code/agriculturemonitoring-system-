#include <LPC21xx.H>
#include "header.h"

void rtc_send(u8 sa, u8 mr, u8 data)
{
        /*step1: generate start condi*/
        I2CONSET=(1<<5);//STA=1
        I2CONCLR=(1<<3);//clear SI*
        while(SI==0);//waiting for start condi
                                                         //to generate
        I2CONCLR=(1<<5);//STA=0

        /*step2: send SA+W & check ack*/
        I2DAT=sa;//send SA+W
        I2CONCLR=(1<<3);//SI=0
        while(SI==0);
        if(I2STAT==0x20){
         uart_tx_string("ERR: SA+W\r\n");
         goto exit;
        }

        /*step3: send mr addr & check ack*/
        I2DAT=mr&0xff;//send memory addr
        I2CONCLR=(1<<3);//SI=0
        while(SI==0);
        if(I2STAT==0x30){
         uart_tx_string("ERR: Memory Addr\r\n");
         goto exit;
        }


        /*step4: send data & check ack*/
        I2DAT=data;//send data
        I2CONCLR=(1<<3);//SI=0
        while(SI==0);
        if(I2STAT==0x30){
         uart_tx_string("ERR: Data\r\n");
         goto exit;
        }

        /*step5: generate stop condi*/
        exit:
                        I2CONSET=(1<<4);//STO=1
                        I2CONCLR=(1<<3);//clear SI
                        delay_ms(10);

}
u8 rtc_receive(u8 sa, u8 mr)
{
        u8 temp;
        /*step1: generate start condi*/
        I2CONSET=(1<<5);//STA=1
        I2CONCLR=(1<<3);//clear SI*
        while(SI==0);//waiting for start condi
                                                         //to generate
        I2CONCLR=(1<<5);//STA=0

        /*step2: send SA+W & check ack*/
        I2DAT=sa^1;//send SA+W
        I2CONCLR=(1<<3);//SI=0
        while(SI==0);
        if(I2STAT==0x20)
        {
         uart_tx_string("ERR: SA+W\r\n");
         goto exit;
        }

         /*step3: send mr addr & check ack*/
        I2DAT=mr&0xff;//send memory addr
        I2CONCLR=(1<<3);//SI=0
        while(SI==0);
        if(I2STAT==0x30){
         uart_tx_string("ERR: Memory Addr\r\n");
         goto exit;
        }

        /*step4: generate restart condi*/
        I2CONSET=(1<<5);//STA=1
        I2CONCLR=(1<<3);//clear SI*
        while(SI==0);//waiting for start condi
                                                         //to generate
        I2CONCLR=(1<<5);//STA=0

        /*step5: send SA+R & check ack*/
        I2DAT=sa;//send SA+R
        I2CONCLR=(1<<3);
        while(SI==0);
        if(I2STAT==0x48){
                uart_tx_string("ERR: SA+R\r\n");
                goto exit;
        }


        /*step6: read data from slave & send noack*/
        I2CONCLR=(1<<3);//SI=0
        while(SI==0);//waiting for data to receive
        temp=I2DAT;


        /*step7: generate stop condi*/
        exit:
                        I2CONSET=(1<<4);//STO=1
                        I2CONCLR=(1<<3);//clear SI*

        /*step8: return data*/
        return temp;
}

void time()
{
   int s,h,m;
   s=rtc_receive(0xd1,0x0);
   m=rtc_receive(0xd1,0x1);
   h=(rtc_receive(0xd1,0x2));
   uart_tx_string("TIME : ");
   uart_tx(((h&0x10)>>4)+48);
   uart_tx((h&0xf)+48);
   uart_tx_string(": ");
   uart_tx(((m&0xf0)>>4)+48);
   uart_tx((m&0xf)+48);
   uart_tx_string(": ");
   uart_tx(((s&0xf0)>>4)+48);
   uart_tx((s&0xf)+48);
   uart_tx_string("\r\n");
}


