#include "print.h"
#include <assert.h>
#include <time.h>

#define G 1000000000
#define N 1000000
#define N0 10

static inline void benchu32(u32 func(u32)) {
  srand(time(NULL));
  u32 *array, sum = 0;
  u64 dt;
  usize i;
  struct timespec t0, t1;
  // init array
  array = malloc(N * sizeof(u32));
  i = 0;
  while (i < N) {
    array[i++] = rand();
  }
  puts("init");

  // measure iterate time
  i = 0;
  clock_gettime(CLOCK_REALTIME, &t0);
  while (i < N)
    sum += array[i++];
  clock_gettime(CLOCK_REALTIME, &t1);
  dt = (t1.tv_sec - t0.tv_sec) * G + t1.tv_nsec - t0.tv_nsec;

  // measure bench time
  i = 0;
  clock_gettime(CLOCK_REALTIME, &t0);
  while (i < N)
    sum += func(array[i++]);
  clock_gettime(CLOCK_REALTIME, &t1);
  printu32n(sum);
  printu64n((t1.tv_sec - t0.tv_sec) * G + t1.tv_nsec - t0.tv_nsec - dt);
}

static inline void benchu32cmp(u32 func1(u32), u32 func2(u32)) {
  u32 *array, sum = 0, sum1, sum2;
  u64 dt, dt1, dt2;
  usize i;
  struct timespec t0, t1;
  srand(time(NULL));
  dt1 = dt2 = 0;
  // init array
  array = malloc(N * sizeof(u32));
  printsn("init");
  for (usize j = 1; j <= N0; ++j) {
    prints("iter:");
    printu64n(j);
    i = 0;
    while (i < N) {
      array[i++] = rand();
    }

    // measure iterate time
    i = 0;
    clock_gettime(CLOCK_REALTIME, &t0);
    while (i < N)
      sum += array[i++];
    clock_gettime(CLOCK_REALTIME, &t1);
    sum1 = sum2 = sum;
    dt = (t1.tv_sec - t0.tv_sec) * G + t1.tv_nsec - t0.tv_nsec;

    // measure bench time 1
    i = 0;
    clock_gettime(CLOCK_REALTIME, &t0);
    while (i < N)
      sum1 += func1(array[i++]);
    clock_gettime(CLOCK_REALTIME, &t1);
    dt1 += (t1.tv_sec - t0.tv_sec) * G + t1.tv_nsec - t0.tv_nsec - dt;

    // measure bench time 2
    i = 0;
    clock_gettime(CLOCK_REALTIME, &t0);
    while (i < N)
      sum2 += func2(array[i++]);
    clock_gettime(CLOCK_REALTIME, &t1);
    dt2 += (t1.tv_sec - t0.tv_sec) * G + t1.tv_nsec - t0.tv_nsec - dt;

    assert(sum1 == sum2);

    // rebench
    i = 0;
    while (i < N) {
      array[i++] = rand();
    }
    //  measure iterate time
    i = 0;
    clock_gettime(CLOCK_REALTIME, &t0);
    while (i < N)
      sum += array[i++];
    clock_gettime(CLOCK_REALTIME, &t1);
    sum1 = sum2 = sum;
    dt = (t1.tv_sec - t0.tv_sec) * G + t1.tv_nsec - t0.tv_nsec;

    // measure bench time 2
    i = 0;
    clock_gettime(CLOCK_REALTIME, &t0);
    while (i < N)
      sum2 += func2(array[i++]);
    clock_gettime(CLOCK_REALTIME, &t1);
    dt2 += (t1.tv_sec - t0.tv_sec) * G + t1.tv_nsec - t0.tv_nsec - dt;

    // measure bench time 1
    i = 0;
    clock_gettime(CLOCK_REALTIME, &t0);
    while (i < N)
      sum1 += func1(array[i++]);
    clock_gettime(CLOCK_REALTIME, &t1);
    dt1 += (t1.tv_sec - t0.tv_sec) * G + t1.tv_nsec - t0.tv_nsec - dt;

    assert(sum1 == sum2);
  }
  printu64n(dt1);
  printu64n(dt2);
}
