#include <stdio.h>
#include <stdlib.h>

struct Node {
  int value;
  struct Node *next;
};

struct Node *node_create(int value);

void node_destroy(struct Node *node);
void print_list(struct Node *node);

int main(void) {
  struct Node *list = node_create(10);
  list->next = node_create(20);
  list->next->next = node_create(30);

  print_list(list);

  node_destroy(list);

  return 0;
}

struct Node *node_create(int value) {
  struct Node *node = malloc(sizeof(*node));

  if (node == NULL)
    return NULL;

  node->value = value;
  node->next = NULL;

  return node;
}

void node_destroy(struct Node *node) {
  while (node != NULL) {
    struct Node *next = node->next;
    free(node);
    node = next;
  }
}

void print_list(struct Node *node) {
  for (struct Node *p_node = node; p_node != NULL; p_node = p_node->next)
    printf("%d -> ", p_node->value);

  printf("NULL");
}