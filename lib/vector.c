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

void vector_push_unsafe(Vector *vector, ElementType element) {
  vector->data[vector->len++] = element;
}

ElementType vector_pop_unsafe(Vector *vector) {
  return vector->data[--vector->len];
}

void vector_insert_unsafe(Vector *vector, size_t index, ElementType element) {
  memmove(vector->data + index + 1, vector->data + index,
          (vector->len++ - index) * sizeof(ElementType));
  vector->data[index] = element;
}

void vector_delete_unsafe(Vector *vector, size_t index) {
  memcpy(vector->data + index, vector->data + index + 1,
         (vector->len-- - index) * sizeof(ElementType));
}

void vector_read(Vector *vector, char *filename) {
  FILE *file = fopen(filename, "a+");
  fseek(file, 0, SEEK_END);
  size_t len = ftell(file) / sizeof(ElementType);
  rewind(file);
  if (vector->len <= len) {
    vector_realloc(vector, len << 1);
  }
  fread(vector->data, sizeof(ElementType), len, file);
  vector->len = len;
}

void vector_write(Vector *vector, char *filename) {
  FILE *file = fopen(filename, "w");
  fwrite(vector->data, sizeof(ElementType), vector->len, file);
  fclose(file);
}

// void vector_find(Vector *vector,)

// debug
void print_vector(Vector *vector, void print_element(ElementType)) {
  for (size_t i = 0; i < vector->len; ++i)
    print_element(vector->data[i]);
  puts("");
}

#endif