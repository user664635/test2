#ifndef U8ZT2046_C
#define U8ZT2046_C

#include "../sbi/spi.h"

uint16_t u8zt2046(uint8_t cmd) {
  spi_start();
  spi_send_byte(cmd);
  uint8_t data[2];
  data[1] = spi_recv_byte();data[0] = spi_recv_byte();
  spi_stop();
  return *(uint16_t *)data;
}

#endif