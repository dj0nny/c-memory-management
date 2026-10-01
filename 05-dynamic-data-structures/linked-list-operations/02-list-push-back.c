#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
  int value;
  struct Node *next;
};

struct Node *node_create(int value);

bool list_push_back(struct Node **head, int value);

void node_destroy(struct Node *node);
void print_list(struct Node *node);
void destroy_node(struct Node *node);

int main(void) {
  struct Node *list = node_create(10);
  list->next = node_create(20);
  list->next->next = node_create(30);
  list->next->next->next = node_create(40);

  if (list_push_back(&list, 50))
    printf("Node added to the list.\n");
  else
    printf("Fail to add the node.\n");

  if (list_push_back(&list, 60))
    printf("Node added to the list.\n");
  else
    printf("Fail to add the node.\n");

  if (list_push_back(&list, 70))
    printf("Node added to the list.\n");
  else
    printf("Fail to add the node.\n");

  print_list(list);
  destroy_node(list);

  struct Node *list_2 = NULL;

  if (list_push_back(&list_2, 10))
    printf("Node added to the list.\n");
  else
    printf("Fail to add the node.\n");
  if (list_push_back(&list_2, 20))
    printf("Node added to the list.\n");
  else
    printf("Fail to add the node.\n");
  if (list_push_back(&list_2, 30))
    printf("Node added to the list.\n");
  else
    printf("Fail to add the node.\n");

  print_list(list_2);
  destroy_node(list_2);

  return 0;
}

struct Node *node_create(int value) {
  struct Node *node = malloc(sizeof(struct Node));

  if (node == NULL)
    return NULL;

  node->value = value;
  node->next = NULL;
  
  return node;
}

void print_list(struct Node *node) {
  for (struct Node *p_node = node; p_node != NULL; p_node = p_node->next)
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

bool list_push_back(struct Node **head, int value) {
  struct Node *node = node_create(value);

  if (node == NULL)
    return false;

  if (*head == NULL)
    *head = node;
  else {
    struct Node *p_node = *head;

    while (p_node->next != NULL)
      p_node = p_node->next;

    p_node->next = node;
  }


  return true;
}