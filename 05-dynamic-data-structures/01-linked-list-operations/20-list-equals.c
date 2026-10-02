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
void deallocate_list(struct Node *head);

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

  struct Node *list_2 = NULL;
  push_back(&list_2, 10);
  push_back(&list_2, 20);
  push_back(&list_2, 30);

  if (list_equal(NULL, NULL))
    printf("The lists are equal.\n");
  else
    printf("The list are not equal.\n");

  if (list_equal(list, list))
    printf("The lists are equal.\n");
  else
    printf("The list are not equal.\n");

  if (list_equal(list, NULL))
    printf("The lists are equal.\n");
  else
    printf("The list are not equal.\n");

  if (list_equal(list, list_2))
    printf("The lists are equal.\n");
  else
    printf("The list are not equal.\n");

  deallocate_list(list_2);
  deallocate_list(list);

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

bool list_equal(const struct Node *head_1, const struct Node *head_2) {
  while (head_1 != NULL && head_2 != NULL){
    if (head_1->value != head_2->value)
      return false;

    head_1 = head_1->next;
    head_2 = head_2->next;
  }

  if (head_1 == NULL && head_2 == NULL)
    return true;

  return false;
}