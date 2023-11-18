

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  uint64_t num;
  char name[16];
} Contact;

typedef struct{
  Contact *data;
  size_t len,cap;
} Contacts;

void printcontacts(Contact *x, size_t n) {
  for (int i = 0; i < n; ++i)
    printf("%s:%lu\n", x[i].name, x[i].num);
}

int main(void){
      Contact *contacts = calloc(n, sizeof(Contact));
  printf("%lu\n", fread(contacts, sizeof(Contact), n, fopen("data", "r")));
  printcontacts(contacts, n);
  strcpy(contacts[0].name, "bbb");
  contacts[0].num = 163467;

  printf("%lu\n", fwrite(contacts, sizeof(Contact), n, fopen("data", "w")));
}