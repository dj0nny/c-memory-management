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
const struct Node *list_find_if(struct Node *head,bool (*predicate)(const struct Node *node, const void *context), const void *context);
bool greater_than(const struct Node *node, const void *context);

void print_list(const struct Node *head);
void destroy_list(struct Node *head);

int main(void) {
  struct Node *list = NULL;
  const struct FilterContext context = {.min_value = 60};
  
  push_back(&list, 10);
  push_back(&list, 25);
  push_back(&list, -1);
  push_back(&list, 30);
  push_back(&list, 7);
  push_back(&list, 42);
  push_back(&list, 67);

  const struct Node *found_node = list_find_if(list, greater_than, &context); // cannot change the returned value

  if (found_node != NULL) {
    printf("Node found %d.\n", found_node->value);
    found_node->value = 50; // cannot do it
    printf("Node value changed %d\n", found_node->value);
  }
  else
    printf("Node not found.\n");

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

const struct Node *list_find_if(struct Node *head, bool (*predicate)(const struct Node *node, const void *context), const void *context) {
  while (head != NULL) {
    if (predicate(head, context))
      return head;
    
    head = head->next;
  }

  return NULL;
}

bool greater_than(const struct Node *node, const void *context) {
  const struct FilterContext *target = (const struct FilterContext *) context;

  return node->value > target->min_value;
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