#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
  int value;
  struct Node *next;
};

struct Node *create_node(int value);
void list_deallocate(struct Node *head);
void list_print(const struct Node *head);

bool push_back(struct Node **head, int value);
bool list_insert_at(struct Node **head, size_t index, int value);

int main(void) {
  struct Node *list = NULL;

  push_back(&list, 10);
  push_back(&list, 20);
  push_back(&list, 30);
  push_back(&list, 40);
  push_back(&list, 50);

  size_t pos = 0;
  int value = 0;

  if (list_insert_at(&list, pos, value))
    printf("Insert node at position %zu.\n", pos);
  else
    printf("Operation failed.\n");
  
  value = -10;
  if (list_insert_at(&list, pos, value))
    printf("Insert node at position %zu.\n", pos);
  else
    printf("Operation failed.\n");

  value = 99;
  pos = 2;
  if (list_insert_at(&list, pos, value))
    printf("Insert node at position %zu.\n", pos);
  else
    printf("Operation failed.\n");
  
  value = 99;
  pos = 67;
  if (list_insert_at(&list, pos, value))
    printf("Insert node at position %zu.\n", pos);
  else
    printf("Operation failed.\n");

  list_print(list);
  list_deallocate(list);

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

void list_deallocate(struct Node *head) {
  while (head != NULL) {
    struct Node *next = head->next;
    free(head);
    head = head->next;
  }
}

void list_print(const struct Node *head) {
  while (head != NULL) {
    printf("%d -> ", head->value);
    head = head->next;
  }

  printf("NULL\n");
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

bool list_insert_at(struct Node **head, size_t index, int value) {
  struct Node *new_node = create_node(value);

  if (new_node == NULL || *head == NULL)
    return false;

  if (index == 0) {
    new_node->next = *head;
    *head = new_node;

    return true;
  }

  struct Node *current = (*head);

  while ((index - 1) > 0 && current != NULL) {
    --index;
    current = current->next;
  }

  if (current == NULL)
    return false;

  new_node->next = current->next;
  current->next = new_node;
  
  return true;

}