#include "contacts.c"
#include <stdio.h>

int main(int argc, char **argv) {
  puts("This is a contacts app");
  // init
  Contacts contacts;
  contacts_init(&contacts);
  char *filename, name[NAMESIZE], op, str[128];
  int unsaved = 0;
  uint64_t num;
  if (argc > 1) {
    filename = argv[1];
    contacts_read(&contacts, filename);
  }

  // loop
  while (1) {
    puts("Command (? for help):");
    op = getchar();
    switch (op) {
      // add contact
    case 'a':
      puts("Name?");
      scanf("%s", name);
      puts("Phone number?");
      scanf("%lu", &num);
      contacts_add(&contacts, name, num);
      unsaved = 1;
      break;
      // print contacts
    case 'p':
      printcontacts(&contacts);
      break;
    // write file
    case 'w':
      puts("File name?");
      str[0] = 0;
      scanf("%s", str);
      if (str[0]) {
        contacts_write(&contacts, str);
        unsaved = 0;
      } else
        puts("No file name,skipping writing file...");
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
    case EOF:
      goto exit;
    }
    // while (getchar() - 10)
    //   ;
  }

exit:
  if (unsaved)
    puts("Warning: file is not saved");
  puts("Exiting...");
  // contacts_del(&contacts, "adf");
  // printcontacts(&contacts);
  // contacts_find(&contacts, "ad");
  // contacts_write(&contacts, filename);
}
