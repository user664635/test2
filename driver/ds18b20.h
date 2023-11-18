#ifndef _DS18B20_H_
#define _DS18B20_H_

#include "../sbi/1wire.h"
#include "../type.h"

#define gett(out, DQ)                                                          \
  do {                                                                         \
    wire1_init(DQ);                                                            \
    wire1_send_byte(0xcc, DQ);                                                 \
    wire1_send_byte(0x44, DQ);                                                 \
    wire1_init(DQ);                                                            \
    wire1_send_byte(0xcc, DQ);                                                 \
    wire1_send_byte(0xbe, DQ);                                                 \
    uint8_t tmpl = 0, tmph = 0;                                                     \
    wire1_recv_byte(tmph, DQ);                                                 \
    wire1_recv_byte(tmpl, DQ);                                                 \
    out = tmph | tmpl << 8;                                                    \
  } while (0)

#endif