#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
  int value;
  struct Node *next;
};

void push_front(struct Node **list, int value);
void print_list(const struct Node *list);
void destroy_list(struct Node *list);

bool list_pop_back(struct Node **head, int *out_value);

int main(void) {
  struct Node *list = NULL;

  push_front(&list, 10);

  int pop_value;
  if (list_pop_back(&list, &pop_value))
    printf("You pop out: %d\n", pop_value);

  print_list(list);

  struct Node *list_2 = NULL;


  push_front(&list_2, 10);
  push_front(&list_2, 20);
  push_front(&list_2, 30);
  push_front(&list_2, 40);

  if (list_pop_back(&list_2, &pop_value))
    printf("You pop out: %d\n", pop_value);
  if (list_pop_back(&list_2, &pop_value))
    printf("You pop out: %d\n", pop_value);
  if (list_pop_back(&list_2, &pop_value))
    printf("You pop out: %d\n", pop_value);
  
  print_list(list_2);

  destroy_list(list_2);
  destroy_list(list);

  return 0;
}

void push_front(struct Node **list, int value) {
  struct Node *new_node = malloc(sizeof(struct Node));

  if (new_node != NULL) {
    new_node->value = value;
    new_node->next = *list;
    *list = new_node;
  } else
    printf("Cannot allocate the node.\n");
}

void print_list(const struct Node *list) {
  while (list != NULL) {
    printf("%d -> ", list->value);
    list = list->next;
  }

  printf("NULL\n");
}

void destroy_list(struct Node *list) {
  while (list != NULL) {
    struct Node *next = list->next;
    free(list);
    list = next;
  }
}

size_t list_size(const struct Node *list) {
  size_t list_size = 0;

  while (list != NULL) {
    ++list_size;
    list = list->next;
  }

  return list_size;
}

bool list_pop_back(struct Node **head, int *out_value) {
  if (*head == NULL)
    return false;

  if ((*head)->next == NULL) {
    *out_value = (*head)->value;
    free(*head);
    *head = NULL;
    return true;
  }

  struct Node *current = *head;

  while (current->next->next != NULL)
    current = current->next;

  *out_value = current->next->value;
  free(current->next);
  current->next = NULL;

  return true;
}