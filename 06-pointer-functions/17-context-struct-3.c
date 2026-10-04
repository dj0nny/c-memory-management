#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct MultiplyContext {
  int factor;
};

struct Node {
  int value;
  struct Node *next;
};

struct Node *create_node(int value);

bool push_back(struct Node **head, int value);
void list_transform(struct Node *head, void (*transform)(struct Node *node, void *context), void *context);
void multiply_node(struct Node *node, void *context);

void print_list(const struct Node *head);
void destroy_list(struct Node *head);

int main(void) {
  struct Node *list = NULL;
  struct MultiplyContext context_factor = {.factor = 3};

  push_back(&list, 10);
  push_back(&list, 25);
  push_back(&list, -1);
  push_back(&list, 30);
  push_back(&list, 7);
  push_back(&list, 42);
  push_back(&list, 67);

  print_list(list);

  list_transform(list, multiply_node, &context_factor);

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

void list_transform(struct Node *head, void (*transform)(struct Node *node, void *context), void *context) {
  while (head != NULL) {
    transform(head, context);
    head = head->next;
  }
}

void multiply_node(struct Node *node, void *context) {
  struct MultiplyContext *target_context = (struct MultiplyContext *) context;

  node->value *= target_context->factor;
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
    head = next;
  }
}