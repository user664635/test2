#include "../math.h"
#ifdef LOW
#include <8052.h>
#endif

#define UART
#include "../sbi/uart.h"

#define I2C
#define SCL P2_1
#define SDA P2_0
#include "../driver/at24c02.c"

#define SPI
#define SCLK P3_6
#define MOSI P3_4
#define MISO P3_7
#define CS P3_5

// 001 Adjustable resistance
// 010 Photoresistance
// 101 thermistor
// 110 External resistor
// 0b1---'0100
#include "../driver/u8zt2046.c"

#define KEY P1
#include "../driver/key.h"

// #include "io.c"
#include "../driver/ds18b20.h"

#define maxt 30 * 16

#ifdef LOW

__sfr __at(0x8e) AUXR;

void init(void) {
  EA = 1;
  ES = 1;
  AUXR = 0xc0;
  SCON = 0x50;
  PCON |= 0x80;
  TMOD = 0x21;
  TR1 = TR0 = 1;
  TL1 = TH1 = 0xff;

  // ET0 = 1;
  EX0 = EX1 = 1;
  IT0 = IT1 = 1;
}
#endif

#ifndef LOW
static uint8_t EA, SM1, PCON, TMOD, TR0, TR1, TL0, TL1, TH0, TH1, EX0, EX1, IT0, IT1;
#endif

static uint8_t t20, t21, dt;

static Byte4 data;
static char str[20];
static uint8_t count = 0;

inline void exint0(void) {
  ++count;
  t21 = TH0;
  dt = t21 - t20;
  t20 = t21;

  if (dt > 0x07 && dt < 0x0a) {
    data.dword <<= 1;
  } else if (dt > 0x0f && dt < 0x12) {
    data.dword <<= 1;
    ++data.dword;
  } else if (data.dword) {
    uint8_t a = data.bytes[1], b = ~data.bytes[0];
    uart_send_u8(a == (b));
    if (data.bytes[1] == ~data.bytes[0]) {
      uart_send_u8(data.bytes[1]);
      uart_send_str("\n\r");
      // uart_send_u8(data.bytes[3]);
    }
    // if (data.bytes[0] == ~data.bytes[1] && data.bytes[2] == ~data.bytes[3]) {
    //   uart_send_str(u32toax(data.dword, str));
    //   uart_send_str("\n\r");
    // }
    // uart_send_str(u8toax(~data.bytes[3], str));
    // uart_send_str(u8toax(~data.bytes[2], str));
    // uart_send_str(u8toax(~data.bytes[1], str));
    // uart_send_str(u8toax(~data.bytes[0], str));
    // uart_send_str("\n\r");
    // uart_send_str(u32toax(data.dword, str));
    // uart_send_str("\n\r");

    data.dword = 0;
  }

  // uart_send_str(u8toax(dt, str));
  // uart_send_str("\n\r");
}

inline void exint1(void) { uart_send_str("\n\r"); }

#ifdef LOW
void __ex0(void) __interrupt(0) { exint0(); }
void __ex1(void) __interrupt(2) { exint1(); }
#endif