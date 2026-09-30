#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
  int value;
  struct Node *next;
};

struct Node *node_create(int value);
void list_destroy(struct Node *head);
void list_print(const struct Node *head);

bool list_push_front(struct Node **head, int value);
bool list_push_back(struct Node **head, int value);

bool list_pop_front(struct Node **head, int *out_value);
bool list_pop_back(struct Node **head, int *out_value);

bool list_remove(struct Node **head, int value);

const struct Node *list_find(const struct Node *head, int value);

size_t list_size(const struct Node *head);

int main(void) {
  struct Node *list = NULL;

  if (list_push_front(&list, 10))
    list_print(list);

  if (list_push_back(&list, 20))
    list_print(list);

  if (list_push_back(&list, 30))
    list_print(list);

  if (list_push_back(&list, 40))
    list_print(list);

  if (list_push_front(&list, 0))
    list_print(list);


  int searched_value = 50;
  const struct Node *found_node = list_find(list, searched_value);
  if (found_node != NULL)
    printf("Value %d found.\n", searched_value);
  else  
    printf("Value %d not found.\n", searched_value);

  searched_value = 20;
  found_node = list_find(list, searched_value);
  if (found_node != NULL)
    printf("Value %d found.\n", searched_value);
  else  
    printf("Value %d not found.\n", searched_value);

  printf("The list size is: %zu\n", list_size(list));

  int list_head_value;
  if (list_pop_front(&list, &list_head_value))
    printf("Head value: %d\n", list_head_value);

  int list_tail_value;
  if (list_pop_back(&list, &list_tail_value))
    printf("Tail value: %d\n", list_tail_value);

  list_print(list);

  int value_to_delete = 20;
  if (list_remove(&list, value_to_delete))
    printf("Node with value %d removed.\n", value_to_delete);

  value_to_delete = 10;
  if (list_remove(&list, value_to_delete))
    printf("Node with value %d removed.\n", value_to_delete);

  list_print(list);
  printf("The list size is: %zu\n", list_size(list));

  list_destroy(list);

  return 0;
}

struct Node *node_create(int value) {
  struct Node *new_node = malloc(sizeof(struct Node));

  if (new_node == NULL)
    return NULL;

  new_node->value = value;
  new_node->next = NULL;

  return new_node;
}

void list_destroy(struct Node *head) {
  while (head != NULL) {
    struct Node *next = head->next;
    free(head);
    head = next;
  }
}

bool list_push_front(struct Node **head, int value) {
  struct Node *new_node = node_create(value);

  if (new_node == NULL)
    return false;

  new_node->next = *head;
  *head = new_node;

  return true;
}

bool list_push_back(struct Node **head, int value) {
  struct Node *new_node = node_create(value);

  if (new_node == NULL)
    return false;

  if ((*head) == NULL) {
    *head = new_node;
    return true;
  }

  struct Node *current = *head;
 
  while (current->next != NULL)
    current = current->next;

  current->next = new_node;
 
  return true;
}

bool list_pop_front(struct Node **head, int *out_value) {
  if (*head == NULL)
    return false;

  struct Node *next = (*head)->next;
  *out_value = (*head)->value;
  free(*head);
  *head = next;

  return true; 
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

bool list_remove(struct Node **head, int value) {
  if (*head == NULL)
    return false;

  if ((*head)->value == value) {
    struct Node *next = (*head)->next;
    free(*head);
    *head = next;

    return true;
  }

  struct Node *previous = *head;
  struct Node *current = (*head)->next;

  while (current != NULL) {
    if (current->value == value) {
      previous->next = current->next;
      free(current);
      return true;
    }

    previous = current;
    current = current->next;
  }

  return false;
}

size_t list_size(const struct Node *head) {
  size_t size = 0;

  while (head != NULL) {
    ++size;
    head = head->next;
  }

  return size;
}

const struct Node *list_find(const struct Node *head, int value) {
  if (head == NULL)
    return NULL;

  if (head->value == value)
    return head;

  const struct Node *current = head->next;

  while (current != NULL) {
    if (current->value == value)
      return current;
    
    current = current->next;
  }

  return NULL;
}

void list_print(const struct Node *head) {
  while (head != NULL) {
    printf("%d -> ", head->value);
    head = head->next;
  }

  printf("NULL\n");
}