
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAMESIZE 16
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
  contacts->data = calloc(INIT_CAP, CONTACT_SIZE);
}

void contacts_read(Contacts *contacts) {
  size_t len =
      fread(contacts->data, CONTACT_SIZE, INIT_CAP, fopen("data", "a+"));
  contacts->len = len;
}

void contacts_write(Contacts *contacts) {
  fwrite(contacts->data, CONTACT_SIZE, contacts->len, fopen("data", "w"));
}

size_t find(Contact *data, char *name, size_t index, size_t step) {
  if (!step)
    return index;
  int cmp = strcmp(data[index].name, name);
  if (!cmp)
    return index;
  if (cmp > 0)
    return find(data, name, index + step, step >> 1);
  return find(data, name, index - step, step >> 1);
}

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
}

void contacts_del(Contacts *contacts, char *name) {
  size_t len = contacts->len;
  Contact *data = contacts->data;
  for (size_t i = 0; i < len; ++i) {
    if (!strcmp(data[i].name, name)) {
      contacts->len--;
      memcpy(data + i, data + i + 1, (len - i)*sizeof(Contacts));
      return;
    }
  }
}

void printcontacts(Contacts *contacts) {
  for (int i = 0; i < contacts->len; ++i)
    printf("%s:%lu\n", contacts->data[i].name, contacts->data[i].num);
}

int main(int argc, char **argv) {
  Contacts contacts;
  contacts_init(&contacts);
  contacts_read(&contacts);
  // contacts_add(&contacts, "a", 346);
  // contacts_add(&contacts, "adf", 15346);
  // contacts_add(&contacts, "sdf", 4346);
  // contacts_add(&contacts, "asf", 123546);
  // contacts_add(&contacts, "asdf", 54346);
  contacts_del(&contacts, "adf");
  printcontacts(&contacts);
  contacts_write(&contacts);
}
