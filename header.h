#include<lpc21xx.h>
#include<stdlib.h>
#include<stdio.h>

#define BUZZER (1<<21)
#define  DHT22 (1<<16)
#define RAIN_SENSOR (1<<14)
#define FLAME_SENSOR (1<<15)
#define PIR_SENSOR (1<<20)
#define PUMP (1<<12)

// WIFI
#define WIFI_ID "SA chavda"
#define WIFI_PASSWORD "sakshi123"
#define THINGSPEAK_API  "KPVP0309Q1C2KI63"

#define RBS (C1GSR&1)
#define TCS ((C1GSR>>3)&1)



//PUMP
void pump_on(int a);


/// CAN
typedef unsigned int u32;
typedef signed int s32;
typedef unsigned char u8;
typedef signed char s8;

typedef struct CAN1_MSG{
        u32 id;
        u32 byteA;
        u32 byteB;
        u8 rtr;
        u8 dlc;
        u8 ff;
}CAN1;
extern CAN1 send;

extern void can1_init(void);
extern void can1_tx(CAN1 v);
extern void can1_rx(CAN1 *ptr);
void can_send_data(void);
//dht22
typedef struct dht22_sensor_value
{
int temp;
int humadity;
int check_sum;
}dht22_struc;

//interupt variables
extern int pir_xor;
extern int flame_xor;
extern int rain_xor;

extern int pumpv;
extern int ldrv;
extern int rainv;
extern int flamev;
extern int pirv;
extern dht22_struc dht22v;
extern int soil_moisv;
extern int water_levelv;
extern int led1;
extern int led2;
extern int led3;
extern int buzzer;

//delay
void delay_ms(int a);
void delay_us(int a);
void delay_sec(int a);

//uart0
void uart_init(unsigned int baud);
void uart_tx(unsigned char a);
unsigned char uart_rx(void);
void uart_tx_string(char *p);
void uart_tx_hex(unsigned char data);
void uart_integer(int a);

//uart1
void uart1_init(unsigned int baud);
void uart1_tx(unsigned char a);
unsigned char uart1_rx(void);
void uart1_tx_string(char *p);
void uart1_tx_hex(unsigned char data);
void uart1_integer(int a);

//lcd
void lcd_cmd(unsigned int cmd);
void lcd_data(unsigned char data);
void lcd_init(void);
void lcd_string(char *a);

/*
//sensor_print_lcd
void soilmoist_lcd(void);
void waterlevel_lcd(void);
void ldr_sensor_lcd(void);
void rain_lcd(void);
void flame_lcd(void);
void pir_lcd(void);
*/

//LED
void red(void);
void green(void);
void yellow(void);

//BUZZER

void buzzeron(void);
void buzzeroff(void);


//i2c
#define SI ((I2CONSET>>3)&1)
void i2c_send(u8 sa, int mr, u8 data);
u8 i2c_receive(u8 sa, int  mr);
void i2c_init(void);

//RTC
void rtc_send(u8 sa, u8 mr, u8 data);
u8 rtc_receive(u8 sa, u8 mr);
void time(void);


//adc
void adc_init(void);
unsigned int adc_read(int chno);

//dht22
dht22_struc dht22_value(void);
//rain_sensor
void rain_exte_int_init(void);
//FLAME
void flame_exte_int_init(void);
//pir
void pir_exte_int_init(void);


//print function
void soil_moisture_sensor(void);
void water_level_sensor(void);
void ldr_sensor(void);

void normal_print(void);
void drysoil_print(void);
void raindetect_print(void);
void firedetect_print(void);
void  motiondetect_print(void);
void lowwaterlevel_print(void);

//WIFI_MODULE
void wifi_connect(void);
void esp_sendcommand(char *a,int wait);
void add_all_field(void);





