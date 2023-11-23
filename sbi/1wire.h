#ifndef WIRE1_H
#define WIRE1_H

#include "../lib/def.h"
#define delay(t) for (u8 i = t; --i;)

#ifndef DQ
volatile static u8 DQ;
#endif

static inline void wire1_init(void) {
  DQ = 1, DQ = 0;
  delay(240);
  DQ = 1;
  delay(240);
}

static inline void wire1_send_bit(u8 bit) {
  DQ = 1, DQ = 0, DQ = bit;
  delay(40);
}

static inline u8 wire1_recv_bit(void) {
  DQ = 1, DQ = 0, DQ = 1;
  delay(10);
  u8 bit = DQ;
  delay(30);
  return bit;
}

static inline void wire1_send_byte(u8 byte) {
  wire1_send_bit(byte & 0x01);
  wire1_send_bit(byte & 0x02);
  wire1_send_bit(byte & 0x04);
  wire1_send_bit(byte & 0x08);
  wire1_send_bit(byte & 0x10);
  wire1_send_bit(byte & 0x20);
  wire1_send_bit(byte & 0x40);
  wire1_send_bit(byte & 0x80);
}

static inline u8 wire1_recv_byte(void) {
  bit8 byte;
  byte.b0 = wire1_recv_bit();
  byte.b1 = wire1_recv_bit();
  byte.b2 = wire1_recv_bit();
  byte.b3 = wire1_recv_bit();
  byte.b4 = wire1_recv_bit();
  byte.b5 = wire1_recv_bit();
  byte.b6 = wire1_recv_bit();
  byte.b7 = wire1_recv_bit();
  return *(u8 *)&byte;
}
#endif