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
  TR1 = 1;
  TL1 = TH1 = 0xff;
  TR0 = 1;
  ET0 = 1;
  IT0 = 1;
  EX0 = 1;
}