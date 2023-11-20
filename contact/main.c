#include "contacts.c"
#include <stdio.h>

int main(int argc, char **argv) {
  puts("This is a contacts app");
  // init
  Vector contacts;
  contacts_init(&contacts);
  char *filename, name[NAMESIZE], str[128];
  int unsaved = 0;
  uint64_t num;
  if (argc > 1) {
    filename = argv[1];
    contacts_read(&contacts, filename);
  }

  // loop
  while (1) {
    puts("Command (? for help):");
    str[0] = 0;
    scanf("%s", str);
    switch (str[0]) {

    // add contact
    case 'a':
      puts("Name?");
      scanf("%s", name);
      puts("Phone number?");
      scanf("%lu", &num);
      contacts_add(&contacts, name, num);
      unsaved = 1;
      break;

    // delete contact
    case 'd':
      puts("Name?");
      scanf("%s", name);
      contacts_del(&contacts, name);
      unsaved = 1;
      break;

    // find contact
    case 'f':
      puts("Name?");
      scanf("%s", name);
      contacts_find(&contacts, name);
      break;

    // open file
    case 'o':
      if (unsaved)
        puts("Warning: file is not saved");
      puts("File name?");
      str[0] = 0;
      scanf("%s", str);
      if (str[0]) {
        contacts_read(&contacts, str);
        unsaved = 0;
      } else
        puts("No file name,skipping reading file...");
      break;

    // print contacts
    case 'p':
      printcontacts(&contacts);
      break;

    // quit
    case 'q':
      goto exit;

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
    case 0:
      goto exit;

    // debug operation
    case 'l':
      printf("%lu\n", contacts.len);
      scanf("%lu", &num);
      contacts.len = num;
      break;

    case 'c':
      printf("%lu\n", contacts.cap);
    }
  }

exit:
  if (unsaved)
    puts("Warning: file is not saved");
  puts("Exiting...");
}
