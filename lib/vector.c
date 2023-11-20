#ifndef VECTOR_C
#define VECTOR_C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// typedef struct {
//   double x, y;
// } vec2;

#ifndef ElementType
#define ElementType void *
#endif

typedef struct Vector Vector;
struct Vector {
  ElementType *data;
  size_t len, cap;
};

void vector_init(Vector *vector, size_t cap) {
  vector->cap = cap;
  vector->len = 0;
  vector->data = malloc(cap * sizeof(ElementType));
}

void vector_realloc(Vector *vector, size_t cap) {
  vector->cap = cap;
  vector->data = realloc(vector->data, cap * sizeof(ElementType));
}

void vector_push(Vector *vector, ElementType element) {
  vector->data[vector->len++] = element;
}

ElementType vector_pop(Vector *vector) { return vector->data[--vector->len]; }

void vector_insert(Vector *vector, size_t index, ElementType element) {
  memmove(vector->data + index + 1, vector->data + index,
          (vector->len++ - index) * sizeof(ElementType));
  vector->data[index] = element;
}

void vector_delete(Vector *vector, size_t index) {
  memcpy(vector->data + index, vector->data + index + 1,
         (vector->len-- - index) * sizeof(ElementType));
}

// debug
void print_vector(Vector *vector, void print_element(ElementType)) {
  for (size_t i = 0; i < vector->len; ++i)
    print_element(vector->data[i]);
  puts("");
}

#endif