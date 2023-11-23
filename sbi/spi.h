#ifndef SPI_H
#define SPI_H

#include "../lib/def.h"

#ifndef SPI
static volatile u8 SCLK, MOSI, MISO, CS;
#endif

inline void spi_start(void) {
  SCLK = 0;
  CS = 0;
}

inline void spi_stop(void) { CS = 1; }

inline void spi_send_bit(u8 bit) {
  MOSI = bit;
  SCLK = 1;
  SCLK = 0;
}

inline u8 spi_recv_bit(void){
    SCLK = 1;
    SCLK = 0;
    return MISO;
}

inline void spi_send_byte(u8 byte){
    spi_send_bit(byte & 0x80);
    spi_send_bit(byte & 0x40);
    spi_send_bit(byte & 0x20);
    spi_send_bit(byte & 0x10);
    spi_send_bit(byte & 0x08);
    spi_send_bit(byte & 0x04);
    spi_send_bit(byte & 0x02);
    spi_send_bit(byte & 0x01);
}
inline u8 spi_recv_byte(void) {
    bit8 byte;
    byte.b7 = spi_recv_bit();
    byte.b6 = spi_recv_bit();
    byte.b5 = spi_recv_bit();
    byte.b4 = spi_recv_bit();
    byte.b3 = spi_recv_bit();
    byte.b2 = spi_recv_bit();
    byte.b1 = spi_recv_bit();
    byte.b0 = spi_recv_bit();
    return *(u8*)&byte;
}
#endif