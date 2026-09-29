#include <stdio.h>
#include <stdlib.h>

struct Node {
  int value;
  struct Node *next;
};

struct Node *create_node(int value);
const struct Node *search_node(const struct Node *node, int value);

void print_list(struct Node *node);
void destroy_node(struct Node *node);

int main(void) {
  struct Node *list = create_node(10);

  list->next = create_node(20);
  list->next->next = create_node(30);
  list->next->next->next = create_node(40);
  list->next->next->next->next = create_node(50);

  const struct Node *found_node = search_node(list, 30);

  if (found_node != NULL)
    printf("Node found: %d\n", found_node->value);
  else
    printf("Node not found\n");

  found_node = search_node(list, -40);

  if (found_node != NULL)
    printf("Node found: %d\n", found_node->value);
  else
    printf("Node not found\n");

  print_list(list);
  destroy_node(list);

  return 0;
}

struct Node *create_node(int value) {
  struct Node *node = malloc(sizeof(struct Node));

  if (node == NULL)
    return NULL;

  node->value = value;
  node->next = NULL;

  return node;
}

const struct Node *search_node(const struct Node *head, int value) {
  if (head == NULL)
    return NULL;

  for (const struct Node *p_node = head; p_node != NULL; p_node = p_node->next)
    if (value == p_node->value)
      return p_node;

  return NULL;
}

void print_list(struct Node *node) {
  for (const struct Node *p_node = node; p_node != NULL; p_node = p_node->next)
    printf("%d -> ", p_node->value);

  printf("NULL\n");
}

void destroy_node(struct Node *node) {
  while (node != NULL) {
    struct Node *next = node;
    free(node);
    node = next;
  }
}