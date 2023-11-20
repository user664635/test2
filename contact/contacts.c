
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

// void contacts_expand(Vector *contacts) {
//   vector_real
//   size_t cap = contacts->cap <<= 1;
//   contacts->data = realloc(contacts->data, cap * CONTACT_SIZE);
// }

void contacts_read(Vector *contacts, char *filename) {
  vector_read(contacts, filename);
}

void contacts_write(Vector *contacts, char *filename) {
  vector_write(contacts,filename);
}

void contacts_add(Contacts *contacts, char *name, uint64_t num) {
  Contact contact = {.num = num};
  strcpy(contact.name, name);
  contacts->data[contacts->len++] = contact;
  if (contacts->len == contacts->cap)
    contacts_expand(contacts);
}

void contacts_del(Contacts *contacts, char *name) {
  size_t len = contacts->len;
  Contact *data = contacts->data;
  for (size_t i = 0; i < len; ++i) {
    if (!strcmp(data[i].name, name)) {
      contacts->len--;
      memcpy(data + i, data + i + 1, (len - i) * CONTACT_SIZE);
      return;
    }
  }
}

void contacts_find(Contacts *contacts, char *name) {
  size_t len = contacts->len;
  Contact *data = contacts->data;
  for (size_t i = 0; i < len; ++i) {
    if (!strncmp(data[i].name, name, strlen(name))) {
      printf("%s:%lu\n", data[i].name, data[i].num);
    }
  }
}

void printcontacts(Contacts *contacts) {
  for (int i = 0; i < contacts->len; ++i)
    printf("%s:%lu\n", contacts->data[i].name, contacts->data[i].num);
}