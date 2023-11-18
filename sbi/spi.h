#ifndef SPI_H
#define SPI_H

#include "../type.h"

#ifndef SPI
static volatile uint8_t SCLK, MOSI, MISO, CS;
#endif

inline void spi_start(void) {
  SCLK = 0;
  CS = 0;
}

inline void spi_stop(void) { CS = 1; }

inline void spi_send_bit(uint8_t bit) {
  MOSI = bit;
  SCLK = 1;
  SCLK = 0;
}

inline uint8_t spi_recv_bit(void){
    SCLK = 1;
    SCLK = 0;
    return MISO;
}

inline void spi_send_byte(uint8_t byte){
    spi_send_bit(byte & 0x80);
    spi_send_bit(byte & 0x40);
    spi_send_bit(byte & 0x20);
    spi_send_bit(byte & 0x10);
    spi_send_bit(byte & 0x08);
    spi_send_bit(byte & 0x04);
    spi_send_bit(byte & 0x02);
    spi_send_bit(byte & 0x01);
}
inline uint8_t spi_recv_byte(void) {
    Bit8 byte;
    byte.bits.b7 = spi_recv_bit();
    byte.bits.b6 = spi_recv_bit();
    byte.bits.b5 = spi_recv_bit();
    byte.bits.b4 = spi_recv_bit();
    byte.bits.b3 = spi_recv_bit();
    byte.bits.b2 = spi_recv_bit();
    byte.bits.b1 = spi_recv_bit();
    byte.bits.b0 = spi_recv_bit();
    return byte.byte;
}
#endif