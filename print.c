
#include"header.h"
/*
void soilmoist_lcd()
{
if(soil_moisv<=20)
{
//lcd_cmd(0x80);
//lcd_string("Soil : DRY");
red();
}
else if(soil_moisv>=40 && soil_moisv<=70)
{
//lcd_cmd(0x80);
//lcd_string("Soil : NORMAL");
yellow();
}
else
{
// lcd_cmd(0x80);
// lcd_string("Soil : WET");
 green();
}
if(pumpv==1)
{
// lcd_cmd(0xc0);
// lcd_string("Pump : ON");
}
else
{
// lcd_cmd(0xc0);
// lcd_string("Pump : OFF");
}
}
void waterlevel_lcd()
{
if(water_levelv<=20)
      {
//      lcd_cmd(0x80);
//      lcd_string("Water : LOW");
          red();
          }
else if(water_levelv>=21 && water_levelv<=90)
      {
//      lcd_cmd(0x80);
//      lcd_string("Water : NORMAL");
          yellow();
          }
else
     {
//      lcd_cmd(0x80);
//      lcd_string("Water : FULL");
          green();
     }
if(pumpv==1)
     {
//      lcd_cmd(0xc0);
//      lcd_string("Pump : READY");
     }
else
     {
//      lcd_cmd(0xc0);
//      lcd_string("Pump : OFF");
     }
}

void ldr_sensor_lcd()
{
  if(ldrv<=20)
  {
//    lcd_cmd(0x80);
//    lcd_string("Light : LOW");
//    lcd_cmd(0xc0);
//    lcd_string("Cloudy Sky");
        red();
  }
  else if(ldrv>=21 && ldrv<=75)
  {
//    lcd_cmd(0x80);
//    lcd_string("Light : MED");
//    lcd_cmd(0xc0);
//    lcd_string("Normal Day");
        yellow();
  }
  else
  {
//     lcd_cmd(0x80);
//     lcd_string("Light : High");
//     lcd_cmd(0xc0);
//     lcd_string("Sunny Sky");
         green();
  }
 }

void rain_lcd()
{
if(rainv!=0)
    {
//    lcd_cmd(0x80);
//    lcd_string("Rain : NO");
//    lcd_cmd(0xc0);
//    lcd_string("Pump : Ready");
        yellow();
        }
else{
//    lcd_cmd(0x80);
//    lcd_string("Rain : YES");
//    lcd_cmd(0xc0);
//    lcd_string("Pump : OFF");
        green();
        }
}

void flame_lcd()
{
if(flamev==0)
  {
//   lcd_cmd(0x80);
//   lcd_string("Flame : SAFE");
//   lcd_cmd(0xc0);
//   lcd_string("Status : NORMAL");
   red();
   }
else
  {
//   lcd_cmd(0x80);
//   lcd_string("FIRE ALERT!!");
//   lcd_cmd(0xc0);
//   lcd_string("Check Fiels");
   green();
  }
}

void pir_lcd()
{
if(pirv==0)
 {
// lcd_cmd(0x80);
// lcd_string("Field : SAFE");
// lcd_cmd(0xc0);
// lcd_string("No Motion");
 green();
 }
else
 {
// lcd_cmd(0x80);
// lcd_string("Motion Found");
// lcd_cmd(0xc0);
// lcd_string("Check Field");
 yellow();
 }
}

*/

void normal_print()
{
uart_init(9600);
uart_tx_string("\r\n=============================================\r\nSMART PRECISION AGRICULTURE MONITORING SYSTEM\r\n=============================================");
uart_tx_string("\r\nController : LPC2129 ARM7\r\nProject Status : RUNNING\r\n---------------------------------------------\r\n");
time();
uart_tx_string("Soil Moisture : ");
uart_integer(soil_moisv);
uart_tx_string("%\r\n");
uart_tx_string("Water Level : ");
uart_integer(water_levelv);
uart_tx_string("%\r\n");
uart_tx_string("Temperature : ");
uart_integer(dht22v.temp);
uart_tx_string("�C\r\n");
uart_tx_string("Humidity : ");
uart_integer(dht22v.humadity);
uart_tx_string("%\r\n");
uart_tx_string("Rain Status : ");
if(rainv==1)
      uart_tx_string("YES\r\n");
else
      uart_tx_string("NO\r\n");
uart_tx_string("Light Intensity : ");
if(ldrv==1)
uart_tx_string("HIGH\r\n");
else
uart_tx_string("low");
uart_tx_string("Flame Status : ");
if(flamev==1)
uart_tx_string("NOT SAFE\r\n");
else
uart_tx_string("SAFE\r\n");
if(pirv==1)
  uart_tx_string("Motion Status : DETECTED\r\n");
else
  uart_tx_string("Motion Status : CLEAR\r\n");
if(pumpv==1)
  {
   uart_tx_string("Pump Status : ON\r\n");
   uart_tx_string("Relay Status : ON\r\n");
  }
else
  {
   uart_tx_string("Pump Status : OFF\r\n");
   uart_tx_string("Relay Status : OFF\r\n");
  }
uart_tx_string("---------------------------------------------\r\n");
uart_tx_string("MONITORING...\r\n");
}


void drysoil_print()
{
uart_init(9600);
uart_tx_string("\r\n=============================================\r\nSMART PRECISION AGRICULTURE MONITORING SYSTEM\r\n=============================================");
uart_tx_string("\r\nController : LPC2129 ARM7\r\nProject Status : RUNNING\r\n---------------------------------------------\r\n");
time();
uart_tx_string("Soil Moisture : ");
uart_integer(soil_moisv);
uart_tx_string("%\r\n");
uart_tx_string("Water Level : ");
uart_integer(water_levelv);
uart_tx_string("%\r\n");
uart_tx_string("Temperature : ");
uart_integer(dht22v.temp);
uart_tx_string("�C\r\n");
uart_tx_string("Humidity : ");
uart_integer(dht22v.humadity);
uart_tx_string("%\r\n");
uart_tx_string("Rain Status : ");
if(rainv==1)
uart_tx_string("YES\r\r");
else
uart_tx_string("NO\r\n");
if(pumpv==1)
  {
   uart_tx_string("Pump Status : ON\r\n");
   uart_tx_string("Relay Status : ON\r\n");
  }
else
  {
   uart_tx_string("Pump Status : OFF\r\n");
   uart_tx_string("Relay Status : OFF\r\n");
  }
if((rainv==0)&&(pumpv==1))
        uart_tx_string("Warning : SOIL DRY\r\nAction : IRRIGATION STARTED\r\n");

//thingspeak1(soil_moisv);
uart_tx_string("Cloud Status : UPDATED\r\n");
uart_tx_string("---------------------------------------------\r\n");
uart_tx_string("MONITORING...\r\n");
}

void raindetect_print()
{
uart_init(9600);
uart_tx_string("\r\n=============================================\r\nSMART PRECISION AGRICULTURE MONITORING SYSTEM\r\n=============================================");
uart_tx_string("\r\nController : LPC2129 ARM7\r\nProject Status : RUNNING\r\n---------------------------------------------\r\n");
time();
uart_tx_string("Rain Status : ");
uart_tx_string("YES\r\n");
//rain_lcd();
uart_tx_string("Soil Moisture : ");
uart_integer(soil_moisv);
uart_tx_string("%\r\n");
uart_tx_string("Pump Status : OFF\r\n");
uart_tx_string("Relay Status : OFF\r\n");
//thingspeak2(rainv);
uart_tx_string("Cloud Status : UPDATED\r\n");

uart_tx_string("Message : RAIN DETECTED\r\nAction : IRRIGATION STOPPED\r\n");
uart_tx_string("---------------------------------------------\r\n");
uart_tx_string("MONITORING...\r\n");
}


void firedetect_print()
{
uart_init(9600);
uart_tx_string("\r\n=============================================\r\nSMART PRECISION AGRICULTURE MONITORING SYSTEM\r\n=============================================");
uart_tx_string("\r\nController : LPC2129 ARM7\r\nProject Status : RUNNING\r\n---------------------------------------------\r\n");
time();
uart_tx_string("Flame Status : DETECTED\r\nBuzzer : ON\r\nAlarm : ACTIVE\r\n");

//thingspeak3(flamev);
uart_tx_string("Cloud Status : UPDATED\r\n");

uart_tx_string("Emergency : FIRE ALERT\r\n");
uart_tx_string("---------------------------------------------\r\n");
uart_tx_string("MONITORING...\r\n");
}
void  motiondetect_print()
{
uart_init(9600);
uart_tx_string("\r\n=============================================\r\nSMART PRECISION AGRICULTURE MONITORING SYSTEM\r\n=============================================");
uart_tx_string("\r\nController : LPC2129 ARM7\r\nProject Status : RUNNING\r\n---------------------------------------------\r\n");
time();
uart_tx_string("\r\nMotion Status : DETECTED\r\nSecurity : ALERT\r\nBuzzer : ON\r\n");
//thingspeak4(pirv);
uart_tx_string("Cloud Status : UPDATED\r\n");

uart_tx_string("Message : UNAUTHORIZED MOVEMENT\r\n");
uart_tx_string("---------------------------------------------\r\n");
uart_tx_string("MONITORING...\r\n");
}
void lowwaterlevel_print()
{
uart_init(9600);
uart_tx_string("\r\n=============================================\r\nSMART PRECISION AGRICULTURE MONITORING SYSTEM\r\n=============================================");
uart_tx_string("\r\nController : LPC2129 ARM7\r\nProject Status : RUNNING\r\n---------------------------------------------\r\n");
time();
uart_tx_string("\r\nWater Level : ");
uart_integer(water_levelv);
uart_tx_string("%\r\n");
uart_tx_string("Tank Status : LOW\r\nPump Status : OFF\r\nRelay Status : OFF\r\n");
//thingspeak5(water_levelv);
uart_tx_string("Cloud Status : UPDATED\r\n");
uart_tx_string("Warning : LOW WATER LEVEL\r\nAction : PUMP PROTECTED\r\n");
uart_tx_string("---------------------------------------------\r\n");
uart_tx_string("MONITORING...\r\n");
}



