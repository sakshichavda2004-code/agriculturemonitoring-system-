
#include"header.h"

int pumpv=0;
int ldrv=0;
int rainv=0;
int flamev=0;
int pirv=0;
dht22_struc dht22v={0,0,0};
int soil_moisv=0;
int water_levelv=0;
int buzzer=0;
int location=2;
CAN1 send;

int main()
{
can1_init();
i2c_init();
uart1_init(9600);
uart_init(9600);
wifi_connect();
adc_init();
rain_exte_int_init();
flame_exte_int_init();
pir_exte_int_init();

while(1)
{
soil_moisture_sensor();
water_level_sensor();
ldr_sensor();
uart_tx_string("soil moisture is calculated\r\n");
dht22_value();
uart_tx_string("dht22\r\n");
//sending to cloud
add_all_field();
//can_send_data();
if((flamev==0)&&(pirv==0)&&(rainv==0)&&(water_levelv>20))
   {
   normal_print();
   green();
   }
if(flamev==1)
   {
   firedetect_print();
   red();
   }
if(pirv==1)
   {
   motiondetect_print();
   red();
   }
if(rainv==1)
   {
   raindetect_print();
   yellow();
   }
if(soil_moisv<30)
   {
   drysoil_print();
   yellow();
   }
if(water_levelv<20)
   {
   lowwaterlevel_print();
   yellow();
   }
if((soil_moisv>80)||(rainv==1)||(water_levelv<20))
    pump_on(0);
else if((soil_moisv<20))
    pump_on(1);
delay_ms(250);
}
}

