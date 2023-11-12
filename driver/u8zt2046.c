#ifndef U8ZT2046_C
#define U8ZT2046_C

#include "../sbi/spi.h"

u16 u8zt2046(u8 cmd) {
  spi_start();
  spi_send_byte(cmd);
  u8 data[2];
  data[1] = spi_recv_byte();data[0] = spi_recv_byte();
  spi_stop();
  return *(u16 *)data;
}

#endif