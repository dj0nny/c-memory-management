#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
  int value;
  struct Node *next;
};

struct Node *create_node(int value);

int double_value(int value);
bool push_back(struct Node **head, int value);

void map_list(struct Node *head, int (*map_value)(int));
void print_list(const struct Node *head);
void clear_list(struct Node **head);

int main(void) {
  struct Node *list = NULL;

  push_back(&list, 5);
  push_back(&list, 10);
  push_back(&list, 15);
  push_back(&list, 20);
  push_back(&list, 25);
  push_back(&list, 30);

  print_list(list);

  map_list(list, double_value);

  print_list(list);

  clear_list(&list);

  return 0;
}

int double_value(int value) {
  return value * 2;
}

struct Node *create_node(int value) {
  struct Node *new_node = malloc(sizeof(struct Node));

  if (new_node == NULL)
    return NULL;

  new_node->value = value;
  new_node->next = NULL;

  return new_node;
}

void map_list(struct Node *head, int (*map_value)(int)) {
  while (head != NULL) {
    head->value = map_value(head->value);
    head = head->next;
  }
}

bool push_back(struct Node **head, int value) {
  struct Node *new_node = create_node(value);

  if (new_node == NULL)
    return false;

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

void clear_list(struct Node **head) {
  while (*head != NULL) {
    struct Node *next = (*head)->next;
    free(*head);
    *head = next;
  }
}