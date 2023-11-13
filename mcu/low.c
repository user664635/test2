#include "../math.c"
#include <8052.h>

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

void init(void) {
  EA = 1;
  SM1 = 1;
  PCON |= 0x80;
  TMOD = 0x21;
  TR1 = TR0 = 1;
  TL1 = TH1 = 0xff;

  ET0 = 1;
  EX0 = EX1 = 1;
  IT0 = IT1 = 1;
}

static Byte2 t20,t21;
static char str[20];

void exint0(void) __interrupt(0) {
  t21.bytes[0] = TL0;
  t21.bytes[1] = TH0;
  uart_send_str(u16toax(t21.word - t20.word , str));
  t20.word = t21.word;
  uart_send_str("\n\r");
}
void exint1(void) __interrupt(2) { uart_send_str("exint1\n\r"); }