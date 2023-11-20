
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAMESIZE 24
typedef struct {
  uint64_t num;
  char name[NAMESIZE];
} Contact;

#define ElementType Contact
#include "../lib/vector.c"

#define INIT_CAP 128
void contacts_init(Vector *contacts) { vector_init(contacts, INIT_CAP); }

void contacts_read(Vector *contacts, char *filename) {
  vector_read(contacts, filename);
}

void contacts_write(Vector *contacts, char *filename) {
  vector_write(contacts, filename);
}

void contacts_add(Vector *contacts, char *name, uint64_t num) {
  Contact tmp = {.num = num};
  strcpy(tmp.name, name);
  vector_push(contacts, tmp);
}

void contacts_del(Vector *contacts, char *name) {
  size_t len = contacts->len;
  Contact *data = contacts->data;
  for (size_t i = 0; i < len; ++i) {
    if (!strcmp(data[i].name, name)) {
      vector_delete_unsafe(contacts, i);
      return;
    }
  }
}

void contacts_find(Vector *contacts, char *name) {
  // size_t len = contacts->len;
  // Contact *data = contacts->data;
  // for (size_t i = 0; i < len; ++i) {
  //   if (!strncmp(data[i].name, name, strlen(name))) {
  //     printf("%s:%lu\n", data[i].name, data[i].num);
  //   }
  // }
}

void printcontacts(Vector *contacts) {
  for (int i = 0; i < contacts->len; ++i)
    printf("%s:%lu\n", contacts->data[i].name, contacts->data[i].num);
}