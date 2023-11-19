#ifndef VECTOR_C
#define VECTOR_C

#include <stdlib.h>

#ifndef ElementType
#define ElementType void *
#endif

typedef struct Vector Vector;
struct Vector {
  ElementType *element;
  size_t len, cap;
};

#endif