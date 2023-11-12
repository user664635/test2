#ifndef KEY_H
#define KEY_H

#include "../type.h"

#ifndef KEY
static volatile u8 KEY;
#endif

inline u16 key16(void) {
  Byte2 key;
  KEY = 0b11111110, key.bytes[0] = KEY >> 4;
  KEY = 0b11111101, key.bytes[0] |= KEY & 0xf0;
  KEY = 0b11111011, key.bytes[1] = KEY >> 4;
  KEY = 0b11110111, key.bytes[1] |= KEY & 0xf0;
  return key.word;
}

#endif