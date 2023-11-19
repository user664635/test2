#include "contacts.c"
#include <stdio.h>

int main(int argc, char **argv) {
  puts("This is a contacts app");
  // init
  Contacts contacts;
  contacts_init(&contacts);
  char *filename, str[NAMESIZE];
  int unsaved = 0;
  if (argc > 1) {
    filename = argv[1];
    contacts_read(&contacts, filename);
  }

  // loop
  while (1) {
    puts("Command (? for help):");
    str[0] =  'q';
    fgets(str, NAMESIZE, stdin);
    switch (str[0]) {
    case 'a':
      puts("Name?");
      fgets(str, NAMESIZE, stdin);
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
    }
    // while (getchar() - 10)
    //   ;
  }

exit:
  if (unsaved)
    puts("Warning: file is not saved");
  puts("Exiting...");
  // contacts_add(&contacts, "a", 346);
  // contacts_add(&contacts, "adf", 15346);
  // contacts_del(&contacts, "adf");
  // printcontacts(&contacts);
  // contacts_find(&contacts, "ad");
  // contacts_write(&contacts, filename);
}
