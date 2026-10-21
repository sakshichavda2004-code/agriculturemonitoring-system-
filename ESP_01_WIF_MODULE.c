
#include"header.h"

void esp_sendcommand(char *a,int wait)
{
uart1_tx_string(a);
uart1_tx_string("\r\n");
delay_ms(wait);
}

void wifi_connect()
{
esp_sendcommand("AT",2000);
esp_sendcommand("AT+CWMODE=1",2000);
uart1_tx_string("AT+CWJAP=\"");
uart1_tx_string(WIFI_ID);
uart1_tx_string("\",\"");
uart1_tx_string(WIFI_PASSWORD);
uart1_tx_string("\"\r\n");
delay_sec(2);
}


void add_all_field()
{
char request[200];
char command[200];
esp_sendcommand("AT+CIPSTART=\"TCP\",\"api.thingspeak.com\",80",4000);
sprintf(request,"GET /update?api_key=%s&field1=%d&field2=%d&field3=%d&field4=%d&field5=%d&field6=%d&field7=%d&field8=%d HTTP/1.1\r\nHost: api.thingspeak.com\r\n\Connection: close\r\n\r\n",THINGSPEAK_API,soil_moisv,rainv,flamev,water_levelv,dht22v.humadity,ldrv);
sprintf(command,"AT+CIPSEND=%d",strlen(request));
esp_sendcommand(command,1000);
delay_ms(1000);
uart1_tx_string(request);
delay_ms(5000);
esp_sendcommand("AT+CIPCLOSE",1000);
}


