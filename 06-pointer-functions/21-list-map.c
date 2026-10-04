#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct MapContext {
  int factor;
};

struct Node {
  int value;
  struct Node *next;
};

struct Node *create_node(int value);

bool push_back(struct Node **head, int value);
void list_map(struct Node *head, void (*map)(struct Node *node, const void *context), const void *context);
void multiply_by_factor(struct Node *node, const void *context);

void print_list(const struct Node *head);
void destroy_list(struct Node *head);

int main(void) {
  struct Node *list = NULL;
  const struct MapContext map_context = {.factor = 5};
  
  push_back(&list, 10);
  push_back(&list, 25);
  push_back(&list, -1);
  push_back(&list, 30);
  push_back(&list, 7);
  push_back(&list, 42);
  push_back(&list, 67);

  print_list(list);
  
  list_map(list, multiply_by_factor, &map_context);

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

void list_map(struct Node *head, void (*map)(struct Node *node, const void *context), const void *context) {
  while (head != NULL) {
    map(head, context);
    head = head->next;
  }
}

void multiply_by_factor(struct Node *node, const void *context) {
  struct MapContext *map_value = (struct MapContext *) context;

  node->value *= map_value->factor;
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