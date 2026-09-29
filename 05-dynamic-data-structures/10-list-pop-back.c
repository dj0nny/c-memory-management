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
  push_front(&list, 20);
  push_front(&list, 30);
  push_front(&list, 40);
  
  print_list(list);

  int pop_value;
  if (list_pop_back(&list, &pop_value))
    printf("You pop out: %d", pop_value);

  destroy_list(list);

  return 0;
}

void push_front(struct Node **list, int value) {
  struct Node *new_node = malloc(sizeof(struct Node));

  if (new_node != NULL) {
    new_node->value = value;
    new_node->next = NULL;
    
    new_node->next = (*list);
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

}