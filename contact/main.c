#include "contacts.c"
#include <stdio.h>

int main(int argc, char **argv) {
  puts("This is a contacts app");
  // init
  Contacts contacts;
  contacts_init(&contacts);
  char *filename, str[16];
  if (argc > 1) {
    filename = argv[1];
    contacts_read(&contacts, filename);
  }

  // loop
  while (1) {
    puts("Command (? for help):");
    switch (getchar()) {
    case 'a':
      puts("Name?");
      break;
    case '?':
      puts("a\tadd contact\n"
           "d\tdelete a contact by name\n"
           "f\tfind contacts by name\n"
           "o\topen a file\n"
           "p\tprint all contacts\n"
           "q\tquit\n"
           "w\twrite to a file\n"
           "?\tprint this page\n");
      break;
    case 'q':
      goto exit;
      return 0;
    case EOF:
      goto exit;
      return 0;
    }
    while (getchar() - 10)
      ;
  }

exit:
  puts("Exiting...");
  // contacts_add(&contacts, "a", 346);
  // contacts_add(&contacts, "adf", 15346);
  // contacts_del(&contacts, "adf");
  // printcontacts(&contacts);
  // contacts_find(&contacts, "ad");
  // contacts_write(&contacts, filename);
}
