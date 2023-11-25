#include "../lib/bench.c"
#include "../lib/mmath.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* // u128 fib(long n) { return SQRT1_5 * (powl(PHI, n) - powl(PHI1, n)); }
  // const u8 a = logu8(10);

int main(void) {
  // u8 tmp = 1;
  // f80 i = *(f80 *)&tmp;
  f80 i = 1e-4800l;
  for (; i < INFINITY ; i *= 5)
  {

    printf("%Le:",(f80)i);
    // printf80(i);
    printi16n(lgf80(i));
    // putchar(':');
  }
  // printu128(fib(180));
  // u16 i = 0;
  // do
  //   printf16n(*(f16 *)&i);
  // while (++i);
} */

static inline u32 builtinpopcount(u32 x) { return __builtin_popcount((u16)x); }
static inline u32 popcount(u32 x) { return popcountu16(x); }
int main(void) { benchu32cmp(popcount, builtinpopcount); }
