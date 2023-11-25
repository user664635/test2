#include <8052.h>
#include "../lib/def.h"
#define LOW
// #include "low.c"

int main(void) {
  // init();
  // uint8_t t0, t1;
  // uint16_t x = 0;
  // bool a;
  u32 c = 0;
  _BitInt(65) a;
  // __asm inline ("");
  P2 = 0b10011111;
  while (1) {

    // uint8_t a = (at24c02_read_byte_inaddr(100));
    // ++a;
    // if (at24c02_write_byte(100, a)) uart_send_str("error writing\n");

    // uart_send_str(u8toax(a,str));

    // x = key16();
    // u16toax(x, str);

    // t0 = TL0;
    // x = TH0 << 8 | TL0;
    // t1 = TL0;
    // uart_send_u8n(t1 - t0);
    // uart_send_u16n(x);

  // uart_send_bit(1);
  // uart_send_d32n(++c);
  }
}
