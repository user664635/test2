
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAMESIZE 24
typedef struct {
  uint64_t num;
  char name[NAMESIZE];
} Contact;

#define CONTACT_SIZE sizeof(Contact)
typedef struct {
  Contact *data;
  size_t len, cap;
} Contacts;

#define INIT_CAP 128
void contacts_init(Contacts *contacts) {
  contacts->cap = INIT_CAP;
  contacts->len = 0;
  contacts->data = malloc(INIT_CAP * CONTACT_SIZE);
}

void contacts_expand(Contacts *contacts) {
  size_t cap = contacts->cap <<= 1;
  contacts->data = realloc(contacts->data, cap * CONTACT_SIZE);
}

void contacts_read(Contacts *contacts, char *filename) {
  FILE *file = fopen(filename, "a+");
  fseek(file, 0, SEEK_END);
  size_t len = ftell(file) / CONTACT_SIZE;
  fseek(file, 0, SEEK_SET);
  fread(contacts->data, CONTACT_SIZE, len, file);
  contacts->len = len;
}

void contacts_write(Contacts *contacts, char *filename) {
  FILE *file = fopen(filename, "w");
  fwrite(contacts->data, CONTACT_SIZE, contacts->len, file);
  fclose(file);
}

// size_t find(Contact *data, char *name, size_t index, size_t step) {
//   if (!step)
//     return index;
//   int cmp = strcmp(data[index].name, name);
//   if (!cmp)
//     return index;
//   if (cmp > 0)
//     return find(data, name, index + step, step >> 1);
//   return find(data, name, index - step, step >> 1);
// }

// void contacts_add(Contacts *contacts, char *name, uint64_t num) {
//   Contact contact = {.num = num}, *data = contacts->data;
//   strcpy(contact.name, name);

//   size_t len = contacts->len++, index = --len, step = len >> 1;
//   index = find(data,name,index,step);
//   memcpy(data + index + 1, data + index, len - index -1);

//   data[index] = contact;
// }

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