#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
  int value;
  struct Node *next;
};

struct Node *create_node(int value);
bool push_back(struct Node **head, int value);

void print_list(const struct Node *head);
void destroy_list(struct Node *head);

const struct Node *list_find_last(const struct Node *head, int value);

int main(void) {
  struct Node *list = NULL;

  push_back(&list, 10);
  push_back(&list, 20);
  push_back(&list, 30);
  push_back(&list, 10);
  push_back(&list, 50);
  push_back(&list, 10);
  push_back(&list, 60);

  int searched_value = 10;
  const struct Node *last_node_with_value = list_find_last(list, 10);
  if (last_node_with_value != NULL)
    printf("The address of the last node with value %d is %p.\n", searched_value, &last_node_with_value);
  else
    printf("Operation failed.\n");

  print_list(list);
  destroy_list(list);

  return 0;
}

const struct Node *list_find_last(const struct Node *head, int value) {
  const struct Node *last_found_node = NULL;
  
  while (head != NULL) {
    if (head->value == value)
      last_found_node = head;
    
    head = head->next;
  }

  return last_found_node;
}

struct Node *create_node(int value) {
  struct Node *new_node = malloc(sizeof(struct Node));

  if (new_node == NULL)
    return NULL;

  new_node->value = value;
  new_node->next = NULL;

  return new_node;
}

bool push_back(struct Node **head, int value) {
  struct Node *new_node = create_node(value);

  if (new_node == NULL)
    return NULL;

  if (*head == NULL) {
    *head = new_node;
    
    return true;
  }

  struct Node *current = *head;

  while (current->next != NULL)
    current = current->next;

  current->next = new_node;

  return true;
}

void print_list(const struct Node *head) {
  while (head != NULL) {
    printf("%d -> ", head->value);
    head = head->next;
  }

  printf("NULL\n");
}

void destroy_list(struct Node *head) {
  while (head != NULL) {
    struct Node *next = head->next;
    free(head);
    next = head;
  }
}