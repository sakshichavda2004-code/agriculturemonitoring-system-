#include"header.h"

void buzzeron()
{
IODIR0|=BUZZER;
IOSET0=BUZZER;
buzzer=1;
}

void buzzeroff()
{
IOCLR0=BUZZER;
buzzer=0;
}
