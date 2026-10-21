#include"header.h"

void pump_on(int a)
{
IODIR0|=PUMP;
if(a==0)
  IOCLR0=PUMP;
else
  IOSET0=PUMP;
}
