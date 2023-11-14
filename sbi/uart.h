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

inline void uart_send_u8(u8 byte) {
  Hex2 tmp = {.byte = byte};
  uart_send_byte(tmp.hexs.h1 > 9 ? tmp.hexs.h1 + '7' : tmp.hexs.h1 + '0');
  uart_send_byte(tmp.hexs.h0 > 9 ? tmp.hexs.h0 + '7' : tmp.hexs.h0 + '0');
}

inline void uart_send_str(char *str) {
  while (*str)
    uart_send_byte(*str++);
}

#endif