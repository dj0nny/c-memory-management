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

void print_deleted_node(int value);
void destroy_list_with(struct Node *head, void (*destroy_value)(int));
void print_list(const struct Node *head);

int main(void) {
  struct Node *list = NULL;

  push_back(&list, 5);
  push_back(&list, 10);
  push_back(&list, 15);
  push_back(&list, 20);
  push_back(&list, 25);
  push_back(&list, 30);

  destroy_list_with(list, print_deleted_node);

  return 0;
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

void print_deleted_node(int value) {
  printf("%d -> ", value);
}

void destroy_list_with(struct Node *head, void (*destroy_value)(int)) {
  while (head != NULL) {
    struct Node *next = head->next;
    destroy_value(head->value);
    free(head);
    head = next;
  }
  printf("NULL\n");
}