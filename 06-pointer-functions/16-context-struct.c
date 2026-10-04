#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct FilterContext {
  int min;
  int max;
};

struct Node {
  int value;
  struct Node *next;
};

struct Node *create_node(int value);

bool push_back(struct Node **head, int value);
bool is_in_range(const struct Node *head, const void *range_target);

size_t list_count_range(const struct Node *head, bool (*predicate)(const struct Node *head, const void *context), const void *context);

void print_list(const struct Node *head);
void destroy_list(struct Node *head);

int main(void) {
  struct Node *list = NULL;
  const struct FilterContext range = {.min = 15, .max = 50};

  push_back(&list, 10);
  push_back(&list, 25);
  push_back(&list, -1);
  push_back(&list, 30);
  push_back(&list, 7);
  push_back(&list, 42);
  push_back(&list, 67);

  printf("The list node between %d and %d are: %zu\n", range.min, range.max, list_count_range(list, is_in_range, &range));

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

size_t list_count_range(const struct Node *head, bool (*predicate)(const struct Node *head, const void *context), const void *context) {
  size_t predicate_counter = 0;

  while (head != NULL) {
    if (predicate(head, context))
      ++predicate_counter;

    head = head->next;
  }

  return predicate_counter;
}

bool is_in_range(const struct Node *head, const void *range_target) {
  const struct FilterContext *filter = (const struct FilterContext *) range_target;

  return (head->value >= filter->min) && (head->value <= filter->max);
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