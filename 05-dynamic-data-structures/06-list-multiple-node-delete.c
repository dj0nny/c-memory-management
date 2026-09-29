#include <stdio.h>
#include <stdlib.h>

struct Node {
  int value;
  struct Node *next;
};

struct Node *create_node(int value);

void print_list(const struct Node *node);
void free_list(const struct Node *node);

size_t list_remove_all(struct Node **head, int value);

int main(void) {
  struct Node *list = create_node(20);

  list->next =create_node(20);
  list->next->next =create_node(20);
  list->next->next->next =create_node(30);

  printf("Deleted %d nodes.", list_remove_all(&list, 20));

  print_list(list);
  free_list(list);

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

size_t list_remove_all(struct Node **head, int value) {
  size_t deleted_items = 0;

  struct Node *previous = NULL;
  struct Node *current = *head;

  while (current != NULL) {
    if (current->value == value) {
      if (previous == NULL)
        *head = current->next;
      else
        previous->next = current->next;

      free(current);
      ++deleted_items;

      if (previous == NULL)
        current = *head;
      else
        current = previous->next;
    } else {
      previous = current;
      current = current->next;
    }
  }

  return deleted_items;

}