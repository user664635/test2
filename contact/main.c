#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  uint64_t num;
  char name[16];
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
  Contact *data = calloc(INIT_CAP, CONTACT_SIZE);
  size_t len = fread(data, CONTACT_SIZE, INIT_CAP, fopen("data", "r"));
  contacts->data = data;
  contacts->cap = INIT_CAP;
  contacts->len = len;
}

void contacts_write(Contacts *contacts) {
  fwrite(contacts->data, CONTACT_SIZE, contacts->len, fopen("data", "w"));
}

void contacts_add(Contacts *contacts, char *name, uint64_t num) {
  Contact contact = {.num = num};
  strcpy(contact.name, name);
  contacts->data[contacts->len++] = contact;
}

void printcontacts(Contacts *contacts) {
  for (int i = 0; i < contacts->len; ++i)
    printf("%s:%lu\n", contacts->data[i].name, contacts->data[i].num);
}

int main(void) {
  Contacts contacts;
  contacts_read(&contacts);
  printcontacts(&contacts);
  contacts_init(&contacts);
//   contacts_add(&contacts, "asdf", 12354346);
  contacts_write(&contacts);
}