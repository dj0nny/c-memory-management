#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
  int value;
  struct Node *next;
};

bool is_even(int a);

bool push_back(struct Node **head, int value);
size_t list_remove_if(struct Node **head, bool (*predicate)(int));

struct Node *create_node(int value);
struct Node *move_list(struct Node **head);

void print_list(const struct Node *head);
void clear_list(struct Node **head);


int main(void) {
  struct Node *list = NULL;
  
  push_back(&list, 0);
  push_back(&list, 5);
  push_back(&list, 10);
  push_back(&list, 15);
  push_back(&list, 20);
  push_back(&list, 25);
  push_back(&list, 30);
  push_back(&list, 35);
  push_back(&list, 40);
  push_back(&list, 45);
  push_back(&list, 50);

  print_list(list);

  printf("Deleted %zu nodes.\n", list_remove_if(&list, is_even));

  print_list(list);
  
  clear_list(&list);

  return 0;
}

bool is_even(int a) {
  return a % 2 == 0;
}

struct Node *create_node(int value) {
  struct Node *new_node = malloc(sizeof(struct Node));

  if (new_node == NULL)
    return NULL;

  new_node->value = value;
  new_node->next = NULL;

  return new_node;
}

size_t list_remove_if(struct Node **head, bool (*predicate)(int)) {
  size_t deleted_node = 0;

  if (*head == NULL)
    return deleted_node;

  while (*head != NULL && predicate((*head)->value)) {
    struct Node *next = (*head)->next;
    free(*head);
    *head = next;

    ++deleted_node;
  }

  struct Node *previous = (*head);
  struct Node *current = (*head)->next;

  while (current != NULL) {
    if (predicate(current->value)) {
      ++deleted_node;
      if (current->next != NULL) {
        previous->next = current->next;
        free(current);
        current = previous->next;
      } else {
        free(current);
        previous->next = NULL;
        return deleted_node;
      }
    } else {
      previous = current;
      current = current->next;
    }
  }

  return deleted_node;
}

bool push_back(struct Node **head, int value) {
  struct Node *new_node = create_node(value);

  if (new_node == NULL)
    return false;

  if (*head == NULL) {
    *head = new_node;

    return true;
  }

  struct Node *current = (*head);

  while (current->next != NULL)
    current = current->next;

  current->next = new_node;

  return true;
}


void print_list(const struct Node *head) {
  while (head != NULL) {
    printf("%d -> ", head->value);
    head = head->next;
  }

  printf("NULL\n");
}

void clear_list(struct Node **head) {
  while (*head != NULL) {
    struct Node *next = (*head)->next;
    free(*head);
    *head = next;
  }
}