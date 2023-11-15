// #include <8052.h>
#define LOW
#include "low.c"

int main(void) {
  init();
  // u8 t0, t1;
  // u16 x = 0;
  u32 c = 0;
  P2 = 0b10011111;
  while (1) {

    // uint16_t t;
    // gett(t, P3_7);
    // uart_send_str(" 温度:");
    // uart_send_str(ttoa(t, str));
    // uart_send_str(" 电阻:");
    // uart_send_str(u16toax(u8zt2046(0b10010100), str));
    // uart_send_str(" 光敏:");
    // uart_send_str(u16toax(u8zt2046(0b10100100), str));
    // uart_send_str(" 热敏:");
    // uart_send_str(u16toax(u8zt2046(0b11010100), str));
    // uart_send_str(" 外部:");
    // uart_send_str(u16toax(u8zt2046(0b11100100), str));

    // u8 a = (at24c02_read_byte_inaddr(100));
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
  uart_send_d32n(++c);
  }
}
