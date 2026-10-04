#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
  int value;
  struct Node *next;
};

struct Node *create_node(int value);

bool push_back(struct Node **head, int value);
bool greater_than(const struct Node *head, void *context);
bool is_even(const struct Node *head, void *context);
bool is_odd(const struct Node *head, void *context);

size_t list_count_if(const struct Node* head, bool (*predicate)(const struct Node *node, void *context), void *context);

void print_list(const struct Node *head);
void destroy_list(struct Node *head);

int main(void) {
  struct Node *list = NULL;

  push_back(&list, 10);
  push_back(&list, 25);
  push_back(&list, -1);
  push_back(&list, 30);
  push_back(&list, 7);
  push_back(&list, 42);
  push_back(&list, 67);

  int target = 20;
  printf("There are %zu elements greater than %d.\n", list_count_if(list, greater_than, &target), target);
  printf("There are %zu even elements.\n", list_count_if(list, is_even, &target), NULL);
  printf("There are %zu odd elements.\n", list_count_if(list, is_odd, &target), NULL);

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

bool greater_than(const struct Node *head, void *context) {
  int target = *(int *) context;

  return head->value > target;
}

bool is_even(const struct Node *head, void *context) {
  (void) context;

  return head->value % 2 == 0;
}

bool is_odd(const struct Node *head, void *context) {
  (void) context;

  return head->value % 2 != 0;
}

size_t list_count_if(const struct Node* head, bool (*predicate)(const struct Node *node, void *context), void *context) {
  size_t predicate_counter = 0;

  while (head != NULL) {
    if (predicate(head, context))
      ++predicate_counter;
    head = head->next;
  }

  return predicate_counter;
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