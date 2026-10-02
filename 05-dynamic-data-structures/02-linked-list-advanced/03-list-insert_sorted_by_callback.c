#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
  int value;
  struct Node *next;
};

int compare_ascending(int a, int b);

bool push_back(struct Node **head, int value);
bool list_insert_sorted_by(struct Node **head, int value, int (*compare)(int, int));

struct Node *create_node(int value);
struct Node *move_list(struct Node **head);

void print_list(const struct Node *head);
void clear_list(struct Node **head);


int main(void) {
  struct Node *list = NULL;
  
  push_back(&list, 10);
  push_back(&list, 20);
  push_back(&list, 30);
  push_back(&list, 40);
  push_back(&list, 50);
  push_back(&list, 60);
  push_back(&list, 70);
  push_back(&list, 80);

  list_insert_sorted_by(&list, 0, compare_ascending);  
  list_insert_sorted_by(&list, -10, compare_ascending);  
  print_list(list);
  list_insert_sorted_by(&list, 15, compare_ascending);  
  list_insert_sorted_by(&list, 15, compare_ascending);  
  list_insert_sorted_by(&list, 35, compare_ascending);  
  list_insert_sorted_by(&list, 90, compare_ascending);  
  list_insert_sorted_by(&list, -20, compare_ascending);  
  list_insert_sorted_by(&list, 55, compare_ascending);  
  list_insert_sorted_by(&list, 150, compare_ascending);  

  print_list(list);
  
  clear_list(&list);

  return 0;
}

int compare_ascending(int a, int b) {
  return a - b;
}

struct Node *create_node(int value) {
  struct Node *new_node = malloc(sizeof(struct Node));

  if (new_node == NULL)
    return NULL;

  new_node->value = value;
  new_node->next = NULL;

  return new_node;
}

bool list_insert_sorted_by(struct Node **head, int value, int (*compare)(int, int)) {
  struct Node *new_node = create_node(value);

  if (new_node == NULL)
    return false;

  if (*head == NULL) {
    *head = new_node;
    return true;
  }

  if ((*compare)(new_node->value, (*head)->value) <= 0) {
    new_node->next = *head;
    *head = new_node;

    return true;
  }

  struct Node *previous = *head;
  struct Node *current = (*head)->next;

  while (current != NULL) {
    if ((*compare)(new_node->value, current->value) <= 0) {
      previous->next = new_node;
      new_node->next = current;
      return true;
    }

    previous = current;
    current = current->next;
  }

  previous->next = new_node;

  return true;
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