#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
  int value;
  struct Node *next;
};

struct Node *create_node(int value);

bool push_back(struct Node **head, int value);
bool list_equal(const struct Node *head_1, const struct Node *head_2);

void print_list(const struct Node *head);
void list_clear(struct Node **head);

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

  print_list(list);
  list_clear(&list);
  print_list(list);

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
    return NULL;

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

void print_list(const struct Node *head) {
  while (head != NULL) {
    printf("%d -> ", head->value);
    head = head->next;
  }

  printf("NULL\n");
}

void deallocate_list(struct Node *head) {
  while (head != NULL) {
    struct Node *next = head->next;
    free(head);
    head = head->next;
  }
}

void list_clear(struct Node **head) {
  while (*head != NULL) {
    struct Node *next = (*head)->next;
    free(*head);
    *head = next;
  }
}