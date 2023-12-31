#ifndef UART_H
#define UART_H

#include "../lib/def.h"

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

inline void uart_send_str(char *str) {
  while (*str)
    uart_send_byte(*str++);
}


#endif