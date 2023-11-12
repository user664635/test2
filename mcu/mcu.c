#include "low.c"

int main(void) {
  init();
  char str[20];
  u8 t0, t1;
  u8 byte = 0;
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

    t0 = TL0;
    uart_send_str(u16toax(key16(),str));
    t1 = TL0;
    uart_send_str(u8toax(t1 - t0, str));


    uart_send_str("\n\r");
  }
}
