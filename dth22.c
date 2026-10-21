v25be9s7@system7:~/final_project_vector$ cat dth22.c

#include"header.h"

dht22_struc dht22_value()
{
unsigned int value1=0,value2=0,msec=0,checksum=0;

unsigned int pclk;
int i=0;
IODIR0|=DHT22;
IOSET0=DHT22;
delay_sec(1);
IOCLR0=DHT22;
delay_sec(2);
IOSET0=DHT22;
delay_us(30);
IODIR0&=(~DHT22);

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
while((IOPIN0&DHT22)!=0);
while((IOPIN0&DHT22)==0);
while((IOPIN0&DHT22)!=0);
T0TCR=1;
for(i=31;i>=0;i--)
{
       while((IOPIN0&DHT22)==0);
              T0TC=0;
       while((IOPIN0&DHT22)!=0);
       msec=T0TC;
       T0TC=0;
           T0PC=0;
       if(msec>45)                     //70us
              {value1=(value1|(1<<i));
                                //uart_tx('1');
                  }
             else
                 {                        //26us;
              value1=(value1&(~(1<<i)));
                                //uart_tx('0');
                  }
}
for(i=7;i>=0;i--)
{
       while((IOPIN0&DHT22)==0);
              T0TC=0;
       while((IOPIN0&DHT22)!=0);
       msec=T0TC;
       T0TC=0;
           T0PC=0;
       if(msec>60)
           {                    //70us
              value2=(value2|(1<<i));
           }
           else
           {                          //26us;
              value2=(value2&(~(1<<i)));
           }
}

T0TCR=0;

dht22v.humadity=(value1>>24)&0xff; ;
dht22v.temp=(value1>>8)&0xff;

checksum=((value1)&0xff) +(((value1)>>8)&0xff);
checksum+=((value1>>16)&0xff) +(((value1)>>24)&0xff);

if((checksum&0xff)==((value2)&0xff))
   dht22v.check_sum=1;

/*
uart_tx_string("\r\nvalue: ");
uart_integer( dht22v.temp);
uart_tx_string(" ");
uart_integer(dht22v.humadity);
uart_tx_string("  ");
uart_integer(dht22v.check_sum);
*/
return dht22v;
/*


uart_tx_string("value: ");
uart_integer(value1);
uart_tx_string("\n\r");

dht22v.temp    =(value1)&0xffff; // 16 to 31 bit
dht22v.humadity= (value1>>16)&0xffff;     // 0 to 15 bit
dht22v.check_sum=0;

checksum=((dht22v.temp)&0xff) +(((dht22v.temp)>>8)&0xff);
checksum+=(dht22v.humadity&0xff) +(((dht22v.humadity)>>8)&0xff);

uart_tx_string("\r\ntemp :");
uart_tx_hex(dht22v.temp&0xff);
uart_tx_hex((dht22v.temp&0xff00)>>8);

uart_tx_string("\r\nhum :");
uart_tx_hex(dht22v.humadity&0xff);
uart_tx_hex((dht22v.humadity&0xff00)>>8);

if((checksum&0xff)==((value2)&0xff))
   dht22v.check_sum=1;

uart_tx_string("\r\nche :");
uart_integer(dht22v.check_sum);

fi=(value1>>24)&0xff;
se=(value1>>16)&0xff;
th=(value1>>8)&0xff;
fo=(value1)&0xff;

dht22v.temp=fi;
dht22v.humadity=th;
return dht22v;
*/
}

