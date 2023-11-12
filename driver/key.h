#ifndef KEY_H
#define KEY_H

#include "../type.h"

#ifndef KEY
static volatile u8 KEY;
#endif

inline u16 key16(void) {
  u8 key[2];
  KEY = 0b11111110, key[0] = KEY >> 4;
  KEY = 0b11111101, key[0] |= KEY & 0xf0;
  KEY = 0b11111011, key[1] = KEY >> 4;
  KEY = 0b11110111, key[1] |= KEY & 0xf0;
  return *(u16 *)key;
}

#endif