#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
  int value;
  struct Node *next;
};

struct Node *create_node(int value);

void print_list(struct Node *node);
void destroy_node(struct Node *node);

bool list_push_front(struct Node **head, int value);

int main(void) {
  struct Node *list = create_node(10);

  list->next = create_node(20);
  list->next->next = create_node(30);
  list->next->next->next = create_node(40);

  if (list_push_front(&list, 0))
    printf("Node added in front.\n");
  else
    printf("Cannot add the node.\n");
  
    if (list_push_front(&list, -10))
    printf("Node added in front.\n");
  else
    printf("Cannot add the node.\n");
 
  if (list_push_front(&list, -20))
    printf("Node added in front.\n");
  else
    printf("Cannot add the node.\n");

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

void print_list(struct Node *list) {
  for (struct Node *p_node = list; p_node != NULL; p_node = p_node->next)
    printf("%d -> ", p_node->value);

  printf("NULL\n");
}

void destroy_node(struct Node *node) {
  while (node != NULL) {
    struct Node *next = node->next;
    free(node);
    node = next;
  }
}

bool list_push_front(struct Node **head, int value) {
  struct Node *node = create_node(value);

  if (node == NULL)
    return false;

  node->next = *head;
  *head = node;

  return true;
}