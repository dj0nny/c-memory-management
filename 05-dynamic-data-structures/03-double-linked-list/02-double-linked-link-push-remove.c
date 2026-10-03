#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct DNode {
  int value;
  struct DNode *prev;
  struct DNode *next;
};

struct DNode *dnode_create(int value);

bool dlist_push_front(struct DNode **head, int value);
bool dlist_push_back(struct DNode **head, int value);
bool dlist_remove(struct DNode **head, int value);

void dlist_print(const struct DNode *head);
void dlist_destroy(struct DNode *head);


int main(void) {
  struct DNode *d_list = NULL;

  dlist_push_front(&d_list, 10);
  dlist_push_front(&d_list, 0);
  dlist_push_front(&d_list, -5);

  dlist_push_back(&d_list, 20);
  dlist_push_back(&d_list, 30);
  dlist_push_back(&d_list, 40);

  dlist_remove(&d_list, -5);
  dlist_remove(&d_list, 0);
  dlist_remove(&d_list, 20);
  dlist_remove(&d_list, 40);

  dlist_print(d_list);
  dlist_destroy(d_list);

  return 0;
}

struct DNode *dnode_create(int value) {
  struct DNode *new_dnode = malloc(sizeof(struct DNode));

  if (new_dnode == NULL)
    return NULL;

  new_dnode->value = value;
  new_dnode->prev = NULL;
  new_dnode->next = NULL;

  return new_dnode;
}

bool dlist_push_front(struct DNode **head, int value) {
  struct DNode *new_dnode = dnode_create(value);

  if (new_dnode == NULL)
    return false;

  if (*head == NULL) {
    *head = new_dnode;
    return true;
  }

  new_dnode->next = *head;
  (*head)->prev = new_dnode;
  *head = new_dnode;

  return true;
}

bool dlist_push_back(struct DNode **head, int value) {
  struct DNode *new_dnode = dnode_create(value);

  if (new_dnode == NULL)
    return false;

  if (*head == NULL) {
    *head = new_dnode;
    return true;
  }

  struct DNode *current = (*head);

  while (current->next != NULL)
    current = current->next;

  current->next = new_dnode;
  new_dnode->prev = current;

  return true;
}

bool dlist_remove(struct DNode **head, int value) {
  if (*head == NULL)
    return false;

  if ((*head)->value == value) {
    struct DNode *next = (*head)->next;
    free(*head);
    if (next != NULL)
      next->prev = NULL;
    
    *head = next;

    return true;
  }

  struct DNode *dnode_previous = *head;
  struct DNode *dnode_current = (*head)->next;

  while (dnode_current->next != NULL) {
    if (dnode_current->value == value) {
      struct DNode *dnode_next = dnode_current->next;
      dnode_previous->next = dnode_next;
      dnode_next->prev = dnode_previous;
      free(dnode_current);

      return true;
    }

    dnode_previous = dnode_current;
    dnode_current = dnode_current->next;
  }

  if (dnode_current->value == value) {
    dnode_previous->next = NULL;
    free(dnode_current);
    return true;
  }

  return false;
}



void dlist_print(const struct DNode *head) {
  printf("NULL <-> ");
  while (head != NULL) {
    printf("%d <-> ", head->value);
    head = head->next;
  }

  printf("NULL\n");
}

void dlist_destroy(struct DNode *head) {
  while (head != NULL) {
    struct DNode *next = head->next;
    free(head);
    head = next;
  }
}