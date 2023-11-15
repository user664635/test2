#ifndef UART_H
#define UART_H

#include "../type.h"

#ifndef UART
static volatile u8 SBUF, TI;
#endif

inline void uart_send_byte(u8 byte) {
  SBUF = byte;
  while (!TI)
    ;
  TI = 0;
}

inline void uart_send_enter(void) {
  uart_send_byte('\n');
  uart_send_byte('\r');
}

#define uart_send_bit(bit) uart_send_byte((bit) + '0')
inline void uart_send_bitn(u8 bit) {
  uart_send_bit(bit);
  uart_send_enter();
}

inline void uart_send_hex(u8 hex) {
  uart_send_byte(hex > 9 ? hex + '7' : hex + '0');
}
inline void uart_send_hexn(u8 hex) {
  uart_send_hex(hex);
  uart_send_enter();
}

inline void uart_send_u8(u8 byte) {
  Hex2 tmp = {.byte = byte};
  uart_send_hex(tmp.hexs.h1);
  uart_send_hex(tmp.hexs.h0);
}
inline void uart_send_u8n(u8 byte) {
  uart_send_u8(byte);
  uart_send_enter();
}

inline void uart_send_u16(u16 word) {
  Byte2 tmp = {.word = word};
  uart_send_u8(tmp.bytes[1]);
  uart_send_u8(tmp.bytes[0]);
}
inline void uart_send_u16n(u16 word) {
  uart_send_u16n(word);
  uart_send_enter();
}

inline void uart_send_u32(u32 dword) {
  Byte4 tmp = {.dword = dword};
  uart_send_u8(tmp.bytes[3]);
  uart_send_u8(tmp.bytes[2]);
  uart_send_u8(tmp.bytes[1]);
  uart_send_u8(tmp.bytes[0]);
}
inline void uart_send_u32n(u32 dword) {
  uart_send_u32n(dword);
  uart_send_enter();
}

inline void uart_send_d32(u32 x) {
  u8 str[11], i = 0;
  u32 tmp;
  do {
    tmp = x / 10;
    str[i++] = x - (tmp << 3) - (tmp << 1);
  }
  while ((x = tmp));

  while (i)
    uart_send_bit(str[--i]);
}
inline void uart_send_d32n(u32 x) {
  uart_send_d32(x);
  uart_send_enter();
}

inline void uart_send_str(char *str) {
  while (*str)
    uart_send_byte(*str++);
}
inline void uart_send_strn(char *str) {
  uart_send_str(str);
  uart_send_enter();
}

#endif