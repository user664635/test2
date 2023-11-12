#ifndef _KEY_H_
#define _KEY_H_

#define key16(out, KEY)                                                        \
  do {                                                                         \
    KEY = 0b11111110, out = KEY >> 4;                                          \
    KEY = 0b11111101, out |= KEY & 0xf0;                                       \
    KEY = 0b11111011, out |= KEY >> 4 << 8;                                    \
    KEY = 0b11110111, out |= KEY >> 4 << 12;                                   \
  } while (0)

#endif