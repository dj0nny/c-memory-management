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

bool remove_node(struct Node **head, int value);

int main(void) {
  struct Node *list = create_node(10);

  list->next = create_node(20);
  list->next->next = create_node(30);
  list->next->next->next = create_node(40);

  if (remove_node(&list, 10))
    printf("Node removed\n");
  else
    printf("Failed to remove the node\n");

  if (remove_node(&list, 30))
    printf("Node removed\n");
  else
    printf("Failed to remove the node\n");


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

bool remove_node(struct Node **head, int value) {
  if (*head == NULL)
    return false;

  if ((*head)->value == value) {
    struct Node *next = (*head)->next;
    free(*head);
    *head = next;
    return true;
  }

  struct Node *prev = *head;
  struct Node *current = (*head)->next;

  while (current != NULL) {
    if (current->value == value) {
      prev->next = current->next;
      free(current);
      return true;
    }

    prev = current;
    current = current->next;
  }

  return false;
}