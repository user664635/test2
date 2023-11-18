#ifndef WIRE1_H
#define WIRE1_H

#define delay(t) for (register uint8_t i = t; --i;)

#define wire1_init(DQ)                                                         \
  do {                                                                         \
    DQ = 1, DQ = 0;                                                            \
    delay(240);                                                                \
    DQ = 1;                                                                    \
    delay(240);                                                                \
  } while (0)

#define wire1_send_bit(bit, DQ)                                                \
  do {                                                                         \
    DQ = 1, DQ = 0, DQ = bit;                                                  \
    delay(40);                                                                 \
  } while (0)

#define wire1_recv_bit(out, p, DQ)                                             \
  do {                                                                         \
    DQ = 1, DQ = 0, DQ = 1;                                                    \
    delay(10);                                                                 \
    out |= DQ << p;                                                            \
    delay(30);                                                                 \
  } while (0)

#define wire1_send_byte(byte, DQ)                                              \
  do {                                                                         \
    wire1_send_bit(byte & 0x01, DQ);                                           \
    wire1_send_bit(byte & 0x02, DQ);                                           \
    wire1_send_bit(byte & 0x04, DQ);                                           \
    wire1_send_bit(byte & 0x08, DQ);                                           \
    wire1_send_bit(byte & 0x10, DQ);                                           \
    wire1_send_bit(byte & 0x20, DQ);                                           \
    wire1_send_bit(byte & 0x40, DQ);                                           \
    wire1_send_bit(byte & 0x80, DQ);                                           \
  } while (0)

#define wire1_recv_byte(out, DQ)                                               \
  do {                                                                         \
    wire1_recv_bit(out, 0, DQ);                                                \
    wire1_recv_bit(out, 1, DQ);                                                \
    wire1_recv_bit(out, 2, DQ);                                                \
    wire1_recv_bit(out, 3, DQ);                                                \
    wire1_recv_bit(out, 4, DQ);                                                \
    wire1_recv_bit(out, 5, DQ);                                                \
    wire1_recv_bit(out, 6, DQ);                                                \
    wire1_recv_bit(out, 7, DQ);                                                \
  } while (0)

#endif