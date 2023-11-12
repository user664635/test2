#include <8052.h>
#include <stdint.h>

static const uint8_t map[] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07,
                              0x7f, 0x6f, 0x77, 0x7c, 0x39, 0x5e, 0x79, 0x71};
static uint8_t delay = 0;

void hexmap(uint32_t x, uint8_t y[]) {
  y[0] = map[x & 0xf], y[1] = map[(x >> 4) & 0xf], y[2] = map[(x >> 8) & 0xf],
  y[3] = map[(x >> 12) & 0xf], y[4] = map[(x >> 16) & 0xf],
  y[5] = map[(x >> 20) & 0xf], y[6] = map[(x >> 24) & 0xf],
  y[7] = map[(x >> 28) & 0xf];
}

void nixiedisplay(uint8_t x[]) {
  P2 = 0, P0 = x[0], P0 = 0, P2 = 4, P0 = x[1], P0 = 0, P2 = 8, P0 = x[2],
  P0 = 0, P2 = 12, P0 = x[3], P0 = 0, P2 = 16, P0 = x[4], P0 = 0, P2 = 20,
  P0 = x[5], P0 = 0, P2 = 24, P0 = x[6], P0 = 0, P2 = 28, P0 = x[7], P0 = 0;
}

static inline void leddisplay(register uint8_t x, register uint8_t y) {
  P3_4 = y & 1, P3_6 = 1, P3_6 = 0, P3_4 = y & 2, P3_6 = 1, P3_6 = 0,
  P3_4 = y & 4, P3_6 = 1, P3_6 = 0, P3_4 = y & 8, P3_6 = 1, P3_6 = 0,
  P3_4 = y & 16, P3_6 = 1, P3_6 = 0, P3_4 = y & 32, P3_6 = 1, P3_6 = 0,
  P3_4 = y & 64, P3_6 = 1, P3_6 = 0, P3_4 = y & 128, P3_6 = 1, P3_6 = 0,
  P0 = ~x, P3_5 = 1, P3_5 = 0;
}

#define display(x)                                                             \
  do {                                                                         \
    P2 = 0;                                                                    \
    while (x) {                                                                \
      P0 = map[x & 0xf];                                                       \
      x >>= 4;                                                                 \
      P0 = 0;                                                                  \
      P2 += 4;                                                                 \
    }                                                                          \
  } while (0)

// static inline void displayu16(uint16_t y[]){
//     uint16_t x;
//     P2 = 0,x = y[0];tmp
//     P2 = 16,x = y[1];tmp
// }

void lcdwdata(uint8_t Data) {
  P2 = 64;
  P0 = Data;
  P2_7 = 1;
  P2_7 = 0;
}

void lcdwcmd(uint8_t Command) {
  P2 = 0;
  P0 = Command;
  P2_7 = 1;
  uint8_t delay = 20;
  while (--delay)
    ;
  P2_7 = 0;
}

void cleardisplay(void) { lcdwcmd(1); }

void lcdinit(void) {
  lcdwcmd(0b00111000);
  lcdwcmd(0b00001111);
  lcdwcmd(0b00000110);
}

void lcdshowstr(char *str) {
  lcdwcmd(0xc0);
  while (*str)
    lcdwdata(*str++);
}
