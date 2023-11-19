#ifndef LINKEDLIST_C
#define LINKEDLIST_C

#include <stdlib.h>

#ifndef ElementType
#define ElementType void *
#endif

typedef struct ForwardList ForwardList;
struct ForwardList {
  ElementType element;
  ForwardList *next;
};

ForwardList *flist_new(ElementType value) {
  ForwardList *node = malloc(sizeof(ForwardList));
  node->element = value;
  node->next = NULL;
  return node;
}

void flist_insert(ForwardList *node, ElementType value) {
  ForwardList *newnode = malloc(sizeof(ForwardList));
  newnode->element = value;
  newnode->next = node->next;
  node->next = newnode;
}

void flist_delete(ForwardList *node) {
  ForwardList *delnode = node->next;
  node->next = delnode->next;
  free(delnode);
}

typedef struct LinkedList LinkedList;
struct LinkedList {
  ElementType element;
  LinkedList *prev, *next;
};

LinkedList *llist_new(ElementType value) {
  LinkedList *node = malloc(sizeof(LinkedList));
  node->element = value;
  node->next = node->prev = NULL;
  return node;
}

void llist_insert(LinkedList *node, ElementType value) {
  LinkedList *newnode = malloc(sizeof(LinkedList));
  newnode->element = value;
  newnode->prev = node;
  newnode->next = node->next;
  if (node->next)
    node->next->prev = newnode;
  node->next = newnode;
}

void llist_delete(LinkedList *node) {
  LinkedList *delnode = node->next;
  node->next = delnode->next;
  if (delnode->next)
    delnode->next->prev = node;
  free(delnode);
}

#endif
