#include <stdio.h>
#include <stdlib.h>

struct DNode {
  int value;
  struct DNode *prev;
  struct DNode *next;
};

struct DNode *dnode_create(int value);

void dlist_print(const struct DNode *head);
void dlist_destroy(struct DNode *head);

int main(void) {
  struct DNode *d_list = dnode_create(10);

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

void dlist_print(const struct DNode *head) {
  while (head != NULL) {
    printf("%d -> ", head->value);
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

