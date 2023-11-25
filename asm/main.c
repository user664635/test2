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
    f32x2 a = {3,4};
  //   f16 a = *(f16 *)&tmp;
//   printi16(_popcnt32(a));
    printf("%f\n",hypot(a[0],a[1]));
    printf("%.30f",sin(a[1]));

  //   printu128(*(u128 *)&a);
}