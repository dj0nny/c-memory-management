#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
  int value;
  struct Node *next;
};

struct Node *create_node(int value);

bool push_back(struct Node **head, int value);

void list_for_each(struct Node *head, void (*callback)(struct Node *node, void *context), void *context);
void add_to_value(struct Node *node, void *context);
void print_list(const struct Node *head);
void destroy_list(struct Node *head);

int main(void) {
  struct Node *list = NULL;

  push_back(&list, 10);
  push_back(&list, 20);
  push_back(&list, 30);
  push_back(&list, 40);
  push_back(&list, 50);

  int context_target = 2;
  list_for_each(list, add_to_value, &context_target);

  print_list(list);
  destroy_list(list);

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

void list_for_each(struct Node *head, void (*callback)(struct Node *node, void *context), void *context) {
  while (head != NULL) {
    callback(head, context);
    head = head->next;
  }
}

void add_to_value(struct Node *node, void *context) {
  int target = *(int *) context;
  node->value += target;
}

void print_list(const struct Node *head) {
  while (head != NULL) {
    printf("%d ", head->value);
    head = head->next;
  }
}

void destroy_list(struct Node *head) {
  while (head != NULL) {
    struct Node *next = head->next;
    free(head);
    head = next;
  }
}