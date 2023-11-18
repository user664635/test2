#ifndef UART_H
#define UART_H

#include "../type.h"

#ifndef UART
static volatile uint8_t SBUF, TI;
#endif

inline void uart_send_byte(uint8_t byte) {
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
inline void uart_send_bitn(uint8_t bit) {
  uart_send_bit(bit);
  uart_send_enter();
}

inline void uart_send_hex(uint8_t hex) {
  uart_send_byte(hex > 9 ? hex + '7' : hex + '0');
}
inline void uart_send_hexn(uint8_t hex) {
  uart_send_hex(hex);
  uart_send_enter();
}

inline void uart_send_u8(uint8_t byte) {
  Hex2 tmp = {.byte = byte};
  uart_send_hex(tmp.hexs.h1);
  uart_send_hex(tmp.hexs.h0);
}
inline void uart_send_u8n(uint8_t byte) {
  uart_send_u8(byte);
  uart_send_enter();
}

inline void uart_send_u16(uint16_t word) {
  Byte2 tmp = {.word = word};
  uart_send_u8(tmp.bytes[1]);
  uart_send_u8(tmp.bytes[0]);
}
inline void uart_send_u16n(uint16_t word) {
  uart_send_u16n(word);
  uart_send_enter();
}

inline void uart_send_u32(uint32_t dword) {
  Byte4 tmp = {.dword = dword};
  uart_send_u8(tmp.bytes[3]);
  uart_send_u8(tmp.bytes[2]);
  uart_send_u8(tmp.bytes[1]);
  uart_send_u8(tmp.bytes[0]);
}
inline void uart_send_u32n(uint32_t dword) {
  uart_send_u32n(dword);
  uart_send_enter();
}

inline void uart_send_d32(uint32_t x) {
  uint8_t str[11], i = 0;
  uint32_t tmp;
  do {
    tmp = x / 10;
    str[i++] = x - (tmp << 3) - (tmp << 1);
  }
  while ((x = tmp));

  while (i)
    uart_send_bit(str[--i]);
}
inline void uart_send_d32n(uint32_t x) {
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