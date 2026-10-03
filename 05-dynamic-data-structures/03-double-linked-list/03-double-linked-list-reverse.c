#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct DNode {
  int value;
  struct DNode *prev;
  struct DNode *next;
};

struct DNode *dnode_create(int value);

bool dlist_push_back(struct DNode **head, int value);
bool dlist_remove(struct DNode **head, int value);


void dlist_reverse(struct DNode **head);
void dlist_print(const struct DNode *head);
void dlist_destroy(struct DNode *head);

int main(void) {
  struct DNode *d_list = NULL;

  dlist_push_back(&d_list, 0);
  dlist_push_back(&d_list, 10);
  dlist_push_back(&d_list, 20);
  dlist_push_back(&d_list, 30);
  dlist_push_back(&d_list, 40);
  dlist_push_back(&d_list, 50);

  dlist_reverse(&d_list);

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


bool dlist_push_back(struct DNode **head, int value) {
  struct DNode *new_dnode = dnode_create(value);

  if (new_dnode == NULL)
    return false;

  if ((*head) == NULL) {
    *head = new_dnode;
    return true;
  }

  struct DNode *current = *head;

  while (current->next != NULL)
    current = current->next;

  current->next = new_dnode;
  new_dnode->prev = current;

  return true;
}

void dlist_reverse(struct DNode **head) {
  struct DNode *previous_dnode = NULL;
  struct DNode *current_dnode = (*head);
  struct DNode *next_dnode;

  while (current_dnode != NULL) {
    next_dnode = current_dnode->next;
    previous_dnode = current_dnode->prev;

    current_dnode->next = previous_dnode;
    current_dnode->prev = next_dnode;

    current_dnode = next_dnode;
  }

  *head = previous_dnode;
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