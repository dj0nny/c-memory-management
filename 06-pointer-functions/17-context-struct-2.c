#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct StatsContext {
  int sum;
  size_t even_numbers;
  size_t odd_numbers;
};

struct Node {
  int value;
  struct Node *next;
};

struct Node *create_node(int value);

bool push_back(struct Node **head, int value);
void list_for_each(const struct Node *head, void (*callback)(const struct Node *node, void *context), void *context);
void compute_stats(const struct Node *head, void *context);

void print_list(const struct Node *head);
void destroy_list(struct Node *head);

int main(void) {
  struct Node *list = NULL;
  struct StatsContext stats;

  push_back(&list, 10);
  push_back(&list, 25);
  push_back(&list, -1);
  push_back(&list, 30);
  push_back(&list, 7);
  push_back(&list, 42);
  push_back(&list, 67);

  list_for_each(list, compute_stats, &stats);

  printf("The sum of the elements is: %d.\n", stats.sum);
  printf("There are %zu even numbers.\n", stats.even_numbers);
  printf("There are %zu odd numbers.\n", stats.odd_numbers);

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

void list_for_each(const struct Node *head, void (*callback)(const struct Node *node, void *context), void *context) {
  while (head != NULL) {
    callback(head, context);
    head = head->next;
  }
}

void compute_stats(const struct Node *head, void *context) {
  struct StatsContext *stats = (struct StatsContext *) context;
  
  stats->sum += head->value;

  if (head->value % 2 == 0)
    ++(stats->even_numbers);
  else
    ++(stats->odd_numbers);
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