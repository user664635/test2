#include "../sbi/i2c.h"

u8 at24c02_write_byte(u8 addr, u8 byte) {
  i2c_start();
  if (i2c_send_byte(0xa0))
    return 1;
  if (i2c_send_byte(addr))
    return 1;
  if (i2c_send_byte(byte))
    return 1;
  i2c_stop();
  for (u16 i = 2000; --i;)
    ;
  return 0;
}

u8 at24c02_read_byte(void) {
  i2c_start();
  i2c_send_byte(0xa1);
  u8 byte = i2c_recv_byte();
  i2c_stop();
  return byte;
}

u8 at24c02_read_byte_inaddr(u8 addr){
  i2c_start();
  i2c_send_byte(0xa0);
  i2c_send_byte(addr);
  i2c_start();
  i2c_send_byte(0xa1);
  u8 byte = i2c_recv_byte();
  i2c_stop();
  return byte;
}