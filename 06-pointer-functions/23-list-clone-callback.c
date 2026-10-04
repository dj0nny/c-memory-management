#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Data {
  char *name;
};

struct DataNode {
  struct Data data;
  struct DataNode *next;
};

struct DataNode *create_node(const char *name);
bool push_back(struct DataNode **head, char *name);
struct DataNode *dlist_clone(const struct DataNode *head, bool (*clone_data)(struct Data *dest, const struct Data *src));
bool clone_data(struct Data *dest, const struct Data *src);

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
  
  struct DataNode *clone_list = dlist_clone(list, clone_data);
  print_list(clone_list);
  
  dlist_destroy(clone_list, destroy_data);
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

struct DataNode *dlist_clone(const struct DataNode *head, bool (*clone_data)(struct Data *dest, const struct Data *src)) {
  if (head == NULL)
    return NULL;

  struct DataNode *temp_clone_list_head = NULL;
  struct DataNode *temp_clone_list_tail = NULL;
  
  while (head != NULL) {
   struct DataNode *new_data_node = malloc(sizeof(struct DataNode));

    if (new_data_node == NULL) {
      dlist_destroy(temp_clone_list_head, destroy_data);
      return NULL;
    }

    if (clone_data(&(new_data_node->data), &(head->data))) {
      new_data_node->next = NULL;

      if (temp_clone_list_head == NULL) {
        temp_clone_list_head = new_data_node;
        temp_clone_list_tail = new_data_node;
      } else {
        temp_clone_list_tail->next = new_data_node;
        temp_clone_list_tail = new_data_node;
      }

      head = head->next;
    } else {
      free(new_data_node);
      dlist_destroy(temp_clone_list_head, destroy_data);
      return NULL;
    }
    
  }

  return temp_clone_list_head;
}

bool clone_data(struct Data *dest, const struct Data *src) {
  char *string_name = malloc(sizeof(char) * (strlen(src->name) + 1));

  if (string_name == NULL)
    return false;

  memcpy(string_name, src->name, sizeof(char) * (strlen(src->name) + 1));

  dest->name = string_name;

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