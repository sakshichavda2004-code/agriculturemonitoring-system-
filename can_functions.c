#include"header.h"

void can1_init(void){
        PINSEL1|=0x40000;//P0.25->RD1
        VPBDIV=1;//PLCK=60MHz
        C1MOD=1;//reset mode
        C1BTR=0x001C001D;//125Kbps baudrate
        AFMR=2;//accept all incoming msgs
        C1MOD=0;//Release reset mode
}


void can1_tx(CAN1 v){
        C1TID1=v.id;
        C1TFI1=v.dlc<<16;//Set dlc,rtr=0,ff=0
        if(v.rtr==0){//if data-frame
                C1TDA1=v.byteA;
                C1TDB1=v.byteB;
        }
        else
                C1TFI1|=(1<<30);//rtr=1

        C1CMR=0x21;//select Txbuf1 & start Xmission
        while(TCS==0);
}



void can1_rx(CAN1 *v1)
{
while((C1GSR&0x1)==0);
v1->id=C1RID;
v1->rtr=((C1RFS>>30)&1);
v1->dlc=((C1RFS>>16)&0XF);
if(v1->rtr)
{
v1->byteA=C1RDA;
v1->byteB=C1RDB;
}
C1CMR=(1<<2);
}

void can_send_data()
{
//send frame data
send.id=0x111;
send.byteA=flamev;
send.rtr=0;
send.dlc=4;
can1_tx(send);
//sending water_levelv data;
send.id=0x112;
send.byteA=water_levelv;
send.rtr=0;
send.dlc=4;
can1_tx(send);
//sending dht22v.temp data;
send.id=0x113;
send.byteA=(dht22v.temp/10);
send.rtr=0;
send.dlc=4;
can1_tx(send);
//sending dht22v.humadity data;
send.id=0x114;
send.byteA=(dht22v.humadity/10);
send.rtr=0;
send.dlc=4;
can1_tx(send);
//sending rainv data;
send.id=0x115;
send.byteA=rainv;
send.rtr=0;
send.dlc=4;
can1_tx(send);
//sending ldrv= data;
send.id=0x116;
send.byteA=ldrv;
send.rtr=0;
send.dlc=4;
can1_tx(send);
}




/*
void can1_rx(CAN1 *ptr){
        while(RBS==0);
        ptr->id=C1RID;//get id
        ptr->dlc=(C1RFS>>16)&0xF;//extract dlc
        ptr->rtr=(C1RFS>>30)&1;//extract rtr
        if(ptr->rtr==0){//if data-frame
                ptr->byteA=C1RDA;//get lower 4bytes data
                ptr->byteB=C1RDB;//get higher 4bytes data
        }

        C1CMR=(1<<2);//Release receiver buffer
}

void can1_tx(CAN1 v){
        C1TID1=v.id;
        C1TFI1=v.dlc<<16;//Set dlc,rtr=0,ff=0
        if(v.rtr==0){//if data-frame
                C1TDA1=v.byteA;
                C1TDB1=v.byteB;
        }
        else
                C1TFI1|=(1<<30);//rtr=1

        C1CMR=0x21;//select Txbuf1 & start Xmission
        while(TCS==0);
}

 */
