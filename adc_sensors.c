
#include"header.h"

void soil_moisture_sensor()
{
uart_tx('x');
   soil_moisv=adc_read(0);
         uart_tx('b');

   soil_moisv=( (416.0- soil_moisv)/ (416.0-300.0) )*100.0 ;
  //soil_moisv = ( (adc_dry - adc_soil_moisture )*100 ) / (adc_dry - adc_wet);
         if(soil_moisv>100)
             soil_moisv=100;
   if(soil_moisv<=0)
       soil_moisv=0;

}

void water_level_sensor()
{
    water_levelv = adc_read(1);
    //voltage show
    //water_level_voltage = (adc_water_level *3.3) / 1023.0;
    //direct 0v to 3.3v -> 0 to 100%
    water_levelv = (water_levelv * 100)/1023;
}

void ldr_sensor()
{
 ldrv=adc_read(2);
 ldrv=(ldrv * 100)/1023;
}
