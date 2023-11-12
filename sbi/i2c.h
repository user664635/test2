#ifndef I2C_H
#define I2C_H

#include "../type.h"

#ifndef I2C
static volatile u8 SCL, SDA;
#endif

inline void i2c_start(void) {
  SDA = 1;
  SCL = 1;
  SDA = 0;
  SCL = 0;
}

inline void i2c_stop(void) {
  SDA = 0;
  SCL = 1;
  SDA = 1;
}

inline void i2c_send_bit(u8 bit) {
  SDA = bit;
  SCL = 1;
  SCL = 0;
}

inline void i2c_send_ack(void) {
  SDA = 0;
  SCL = 1;
  SCL = 0;
}

inline u8 i2c_recv_bit(void) {
  SCL = 1;
  u8 bit = SDA;
  SCL = 0;
  return bit;
}

inline u8 i2c_recv_ack(void) {
  u8 bit = 1;
  SDA = 1;
  SCL = 1;
  bit = SDA;
  SCL = 0;
  return bit;
}

inline u8 i2c_send_byte(u8 byte) {
  i2c_send_bit(byte & 0x80);
  i2c_send_bit(byte & 0x40);
  i2c_send_bit(byte & 0x20);
  i2c_send_bit(byte & 0x10);
  i2c_send_bit(byte & 0x08);
  i2c_send_bit(byte & 0x04);
  i2c_send_bit(byte & 0x02);
  i2c_send_bit(byte & 0x01);
  return i2c_recv_ack();
}

inline u8 i2c_recv_byte(void) {
  Bit8 byte;
  byte.bits.b7 = i2c_recv_bit();
  byte.bits.b6 = i2c_recv_bit();
  byte.bits.b5 = i2c_recv_bit();
  byte.bits.b4 = i2c_recv_bit();
  byte.bits.b3 = i2c_recv_bit();
  byte.bits.b2 = i2c_recv_bit();
  byte.bits.b1 = i2c_recv_bit();
  byte.bits.b0 = i2c_recv_bit();
  i2c_send_ack();
  return byte.byte;
}

#endif