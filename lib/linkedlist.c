#ifndef LINKEDLIST_C
#define LINKEDLIST_C

#include <stdlib.h>

#ifndef ElementType
#define ElementType void *
#endif

typedef struct SingleLinkedList SingleLinkedList;

struct SingleLinkedList {
  ElementType element;
  SingleLinkedList *next;
};

SingleLinkedList *sllist_new(ElementType value) {
  SingleLinkedList *node = malloc(sizeof(SingleLinkedList));
  node->element = value;
  node->next = 0;
  return node;
}

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

typedef struct LinkedList LinkedList;

struct LinkedList {
  ElementType element;
  LinkedList *prev, *next;
};

LinkedList *llist_new(ElementType value) {
  LinkedList *node = malloc(sizeof(LinkedList));
  node->element = value;
  node->next = node->prev = 0;
  return node;
}

void llist_insert(LinkedList *node, ElementType value) {
  LinkedList *newnode = malloc(sizeof(LinkedList));
  newnode->element = value;
  newnode->prev = node;
  LinkedList *tmp = node->next;
  newnode->next = tmp;
  if (tmp)
    tmp->prev = newnode;
  node->next = newnode;
}

void llist_delete(LinkedList *node) {
  LinkedList *delnode = node->next;
  delnode->prev = node;
  node->next = delnode->next;
  free(delnode);
}

#endif
