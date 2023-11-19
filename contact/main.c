#include "contacts.c"

int main(int argc, char **argv) {
  Contacts contacts;
  contacts_init(&contacts);
  char *filename;
  if (argc > 1) {
    filename = argv[1];
    contacts_read(&contacts, filename);
  }
  // contacts_add(&contacts, "a", 346);
  // contacts_add(&contacts, "adf", 15346);
  // contacts_add(&contacts, "sdf", 4346);
  // contacts_add(&contacts, "asf", 123546);
  // contacts_add(&contacts, "asdf", 54346);
  // contacts_del(&contacts, "adf");
  // printcontacts(&contacts);
  contacts_query(&contacts, "ad");
  contacts_write(&contacts, filename);
}
