#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  uint64_t num;
  char name[16];
} Contact;

typedef struct {
  Contact *data;
  size_t len, cap;
} Contacts;

#define INIT_CAP 128
Contacts contacts_init(void) {
  Contacts contacts;
  contacts.cap = INIT_CAP;
  contacts.len = 0;
  contacts.data = calloc(INIT_CAP, sizeof(Contact));
  return contacts;
}

void contacts_read(Contacts contacts) {
  size_t len = fread(contacts.data, sizeof(Contact), -1, fopen("data", "r"));
  contacts.len = len;
}

void contacts_write(Contacts contacts) {
  fwrite(contacts.data, sizeof(Contact), contacts.len, fopen("data", "w"));
}

void contacts_add(Contacts contacts,char *name,uint64_t num){
    Contact contact = {.num = num};
    strcpy(contact.name, name);
    contacts.data[contacts.len++] = contact;
}

void printcontacts(Contacts contacts) {
  for (int i = 0; i < contacts.len; ++i)
    printf("%s:%lu\n", contacts.data[i].name, contacts.data[i].num);
}

int main(void) {
  Contacts contacts = contacts_init();
  contacts_read(contacts);
  printcontacts(contacts);
  contacts_add(contacts, "asdf", 12354346);
  contacts_write(contacts);
}