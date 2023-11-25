#include "../lib/bench.c"
#include "../lib/mmath.h"
#include <stdlib.h>
#include <string.h>

int main(void) {
  union {f16 f;u16 u;} i;

  // printu128(powu64(5,5));
  for (i.u = 1;i.u;++i.u){
    printf16(i.f);
    printf("\t%e\n",(f64)i.f);
  }
}