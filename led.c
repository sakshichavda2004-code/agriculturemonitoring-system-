
  #include"header.h"
  void red()
  {
  IODIR0|=0x7<<8;
  IOSET0=0x7<<8;
  IOCLR0=1<<10;
  }
  void green()
  {
  IODIR0|=0x7<<8;
  IOSET0=0x7<<8;
  IOCLR0=1<<8;
  }
  void yellow( )
  {
  IODIR0|=0x7<<8;
  IOSET0=0x7<<8;
  IOCLR0=1<<9;
  }
