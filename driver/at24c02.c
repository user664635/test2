#include "../sbi/i2c.h"

uint8_t at24c02_write_byte(uint8_t addr, uint8_t byte) {
  i2c_start();
  if (i2c_send_byte(0xa0))
    return 1;
  if (i2c_send_byte(addr))
    return 1;
  if (i2c_send_byte(byte))
    return 1;
  i2c_stop();
  for (uint16_t i = 2000; --i;)
    ;
  return 0;
}

uint8_t at24c02_read_byte(void) {
  i2c_start();
  i2c_send_byte(0xa1);
  uint8_t byte = i2c_recv_byte();
  i2c_stop();
  return byte;
}

uint8_t at24c02_read_byte_inaddr(uint8_t addr){
  i2c_start();
  i2c_send_byte(0xa0);
  i2c_send_byte(addr);
  i2c_start();
  i2c_send_byte(0xa1);
  uint8_t byte = i2c_recv_byte();
  i2c_stop();
  return byte;
}