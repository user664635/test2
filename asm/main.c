#include "../lib/mmath.h"
#include "../lib/print.h"

int main(void) {
  //   u32 a = 1233;
  //   printu32(a);
  //   asm("movq 	(%rbx), %rsi\n\t"
  //       "movl	    $51, %edi \n\t"
  //       "callq	putc@PLT");

  //   asm("movq 	(%rbx), %rsi\n\t"
  //       "movl	    $51, %edi \n\t"
  //       "callq	putc@PLT");
  //   asm("movq 	(%rbx), %rsi\n\t"
  //       "movl	    $51, %edi \n\t"
  //       "callq	putc@PLT");
  //   asm("movq 	(%rbx), %rsi\n\t"
  //       "movl	    $51, %edi \n\t"
  //       "callq	putc@PLT");
  // f128 a = 4,b = 4;
  //   f64x2 a = {3,4};
  u8 tmp = 1;
  f16 a = *(f16 *)&tmp;
  printi16(__builtin_log10f(a));
  //   printf("%f",__builtin_hypot(a[0],a[1]));
  //   printu128(*(u128 *)&a);
}