#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

struct Data {
  char *name;
};

struct DataNode {
  struct Data data;
  struct DataNode *next;
};

struct DataNode *create_node(const char *name);
bool push_back(struct DataNode **head, char *name);
bool dlist_map(struct DataNode *head, bool (*map_data)(struct Data *data, const void *context), const void *context);
bool uppercase_data(struct Data *data, const void *context);

void print_list(const struct DataNode *head);
void dlist_destroy(struct DataNode *head, void (*destroy_data)(struct Data *data));
void destroy_data(struct Data *data);

int main(void) {
  struct DataNode *list = NULL;

  push_back(&list, "Hello");
  push_back(&list, "world!");
  push_back(&list, "How");
  push_back(&list, "do");
  push_back(&list, "you");
  push_back(&list, "feel");
  push_back(&list, "today?");
  print_list(list);

  if (dlist_map(list, uppercase_data, NULL))
    printf("List mapped.\n");
  else
    printf("Failed to map list.\n");

  print_list(list);
  dlist_destroy(list, destroy_data);

  return 0;
}

struct DataNode *create_node(const char *name) {
  struct DataNode *new_node = malloc(sizeof(struct DataNode));

  if (new_node == NULL)
    return NULL;

  char *name_string = malloc(sizeof(char) * (strlen(name) + 1));

  if (name_string == NULL) {
    free(new_node);
    return NULL;
  }

  new_node->data.name = name_string;

  memcpy(new_node->data.name, name, sizeof(char) * (strlen(name) + 1));

  new_node->next = NULL;

  return new_node;
}

bool dlist_map(struct DataNode *head, bool (*map_data)(struct Data *data, const void *context), const void *context) {
  while (head != NULL) {
    if (!map_data(&(head->data), context))
      return false;
    head = head->next;
  }

  return true;
}

bool uppercase_data(struct Data *data, const void *context) {
  (void) context;

  size_t str_len = strlen(data->name);

  if (str_len == 0)
    return false;

  for (size_t i = 0; i < str_len; ++i)
    data->name[i] = (char) toupper((unsigned char) data->name[i]);

  return true;
}

bool push_back(struct DataNode **head, char *name) {
  struct DataNode *new_data_node = create_node(name);

  if (new_data_node == NULL)
    return false;

  if (*head == NULL) {
    *head = new_data_node;

    return true;
  }

  struct DataNode *current = *head;

  while (current->next != NULL)
    current = current->next;

  current->next = new_data_node;

  return true;
}

void dlist_destroy(struct DataNode *head, void (*destroy_data)(struct Data *data)) {
  while (head != NULL) {
    struct DataNode *next = head->next;
    destroy_data(&(head->data));
    free(head);
    head = next;
  }

  printf("List destroyed.\n");
}

void destroy_data(struct Data *data) {
  free(data->name);
}

void print_list(const struct DataNode *head) {
  while (head != NULL) {
    printf("%s -> ", head->data.name);    
    head = head->next;
  }
  printf("NULL\n");
}