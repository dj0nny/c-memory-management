#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct FilterContext {
  int min_value;
};

struct Node {
  int value;
  struct Node *next;
};

struct Node *create_node(int value);

bool push_back(struct Node **head, int value);
size_t list_transform_if(struct Node *head, bool (*predicate)(const struct Node *node, const void *context), void (*transform)(struct Node *node, const void *context), const void *context);
bool greater_than_or_equal(const struct Node *node, const void *context);
void double_value(struct Node *node, const void *context);

void print_list(const struct Node *head);
void destroy_list(struct Node *head);

int main(void) {
  struct Node *list = NULL;
  struct FilterContext filter = {.min_value = 10};

  push_back(&list, 10);
  push_back(&list, 25);
  push_back(&list, -1);
  push_back(&list, 30);
  push_back(&list, 7);
  push_back(&list, 42);
  push_back(&list, 67);

  printf("Transformed %zu nodes.\n", list_transform_if(list, greater_than_or_equal, double_value, &filter));

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

size_t list_transform_if(struct Node *head, bool (*predicate)(const struct Node *node, const void *context), void (*transform)(struct Node *node, const void *context), const void *context) {
  size_t transform_counter = 0;

  while (head != NULL) {
    if (predicate(head, context)) {
      transform(head, context);
      ++transform_counter;
    }
    head = head->next;
  }

  return transform_counter;
}

bool greater_than_or_equal(const struct Node *node, const void *context) {
  const struct FilterContext *filter_target = (const struct FilterContext *) context;

  return node->value >= filter_target->min_value;
}

void double_value(struct Node *node, const void *context) {
  (void) context;

  node->value *= 2;
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