#ifndef LINKEDLIST_C
#define LINKEDLIST_C

#include <stdlib.h>

#ifndef ElementType
#define ElementType int
#endif

typedef struct SingleLinkedList SingleLinkedList;

struct SingleLinkedList {
  ElementType element;
  SingleLinkedList *next;
};

void sllist_insert(SingleLinkedList *node, ElementType value) {
  SingleLinkedList *newnode = malloc(sizeof(SingleLinkedList));
  newnode->element = value;
  newnode->next = node->next;
  node->next = newnode;
}

void sllist_delete(SingleLinkedList *node) {
  SingleLinkedList *delnode = node->next;
  node->next = delnode->next;
  free(delnode);
}

#endif