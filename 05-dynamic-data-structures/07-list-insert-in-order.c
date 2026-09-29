#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
  int value;
  struct Node *next;
};

struct Node *create_node(int value);

void print_list(const struct Node *node);
void free_list(const struct Node *node);

bool list_insert_sorted(struct Node **head, int value);

int main(void) {
  // struct Node *list = create_node(10);

  // list->next =create_node(20);
  // list->next->next =create_node(30);
  // list->next->next->next =create_node(40);
  // list->next->next->next->next =create_node(50);

  struct Node *list_1 = NULL;

  if (list_insert_sorted(&list_1, 10))
    print_list(list_1);

  free_list(list_1);

  struct Node *list_2 = create_node(10);

  if (list_insert_sorted(&list_2, 5))
    print_list(list_2);

  if (list_insert_sorted(&list_2, 7))
    print_list(list_2);

  if (list_insert_sorted(&list_2, 50))
    print_list(list_2);

  free_list(list_2);

  return 0;
}

struct Node *create_node(int value) {
  struct Node *node = malloc(sizeof(struct Node));

  if (node == NULL)
    return NULL;

  node->value = value;
  node->next = NULL;
}

void print_list(const struct Node *node) {
  for (const struct Node *p_node = node; p_node != NULL; p_node = p_node->next)
    printf("%d -> ", p_node->value);

  printf("NULL\n");
}

void free_list(const struct Node *node) {
  while (node != NULL) {
    struct Node *next = node->next;
    free((void *) node);
    node = next;
  }
}

bool list_insert_sorted(struct Node **head, int value) {
  struct Node *new_node = create_node(value);

  if (new_node != NULL) {
    if (*head == NULL) {
      *head = new_node;

      return true;
    }

    if (new_node->value < (*head)->value) {
      new_node->next = *head;
      *head = new_node;

      return true;
    }

    struct Node *previous = *(head);
    struct Node *current = (*head)->next;

    while (current != NULL) {
      if (new_node->value < current->value) {
        new_node->next = previous->next;
        previous->next = new_node;
      
        return true;
      }

      previous = current;
      current = current->next;
    }

    if (current == NULL) {
      previous->next = new_node;
      return true;
    }
  }

  return false;
}