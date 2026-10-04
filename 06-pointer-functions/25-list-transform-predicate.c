#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct ReplaceContext {
  const char *new_string;
  const char *searched_sting;
};

struct Data {
  char *string;
};

struct DataNode {
  struct Data value;
  struct DataNode *next;
};

struct DataNode *create_node(char *value);
bool push_back(struct DataNode **head, char *value);
bool dlist_replace_if(struct DataNode *head, bool (*predicate)(const struct Data *data, const void *context), bool (*replace)(struct Data *data, const void *context), const void *context);
bool string_equals(const struct Data *data, const void *context);
bool string_replace(struct Data *data, const void *context);

void print_list(const struct DataNode *head);
void dlist_destroy(struct DataNode *head, void (*destroy_data)(struct Data *data));
void destroy_data(struct Data *data);

int main(void) {
  struct DataNode *list = NULL;
  struct ReplaceContext context = {.new_string = "Welcome", .searched_sting = "Hello"};

  push_back(&list, "Hello");
  push_back(&list, "World!");
  push_back(&list, "How");
  push_back(&list, "do");
  push_back(&list, "you");
  push_back(&list, "feel");
  push_back(&list, "today?");

  print_list(list);

  if (dlist_replace_if(list, string_equals, string_replace, &context))
    printf("String replaced.\n");
  else
    printf("Failed to replace the string\n");

  print_list(list);
  dlist_destroy(list, destroy_data);

  return 0;
}

struct DataNode *create_node(char *value) {
  struct DataNode *new_node_data = malloc(sizeof(struct DataNode));

  if (new_node_data == NULL)
    return NULL;

  char *temp_string = malloc(sizeof(char) * (strlen(value) + 1));

  if (temp_string == NULL) {
    free(new_node_data);
    return NULL;
  }

  new_node_data->value.string = temp_string;

  memcpy(new_node_data->value.string, value, sizeof(char) * (strlen(value) + 1));
  new_node_data->next = NULL;

  return new_node_data;
}

bool push_back(struct DataNode **head, char *value) {
  struct DataNode *new_data_node = create_node(value);

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

bool dlist_replace_if(struct DataNode *head, bool (*predicate)(const struct Data *data, const void *context), bool (*replace)(struct Data *data, const void *context), const void *context) {
  while (head != NULL) {
    if (predicate(&(head->value), context))
      if (!replace(&(head->value), context))
        return false;

    head = head->next;
  }

  return true;
}

bool string_equals(const struct Data *data, const void *context) {
  const struct ReplaceContext *replace_target = (const struct ReplaceContext *) context;

  return strcmp(data->string, replace_target->searched_sting) == 0;  
}

bool string_replace(struct Data *data, const void *context) {
  const struct ReplaceContext *replace_target = (const struct ReplaceContext *) context;
  
  char *new_string = malloc(sizeof(char) * (strlen(replace_target->new_string) + 1));

  if (new_string == NULL)
    return false;

  free(data->string);
  data->string = new_string;
  memcpy(data->string, replace_target->new_string, sizeof(char) * (strlen(replace_target->new_string) + 1));

  return true;
}

void dlist_destroy(struct DataNode *head, void (*destroy_data)(struct Data *data)) {
  while (head != NULL) {
    struct DataNode *next = head->next;
    destroy_data(&(head->value));
    free(head);
    head = next;
  }

  printf("List destroyed.\n");
}


void destroy_data(struct Data *data) {
  free(data->string);
}

void print_list(const struct DataNode *head) {
  while (head != NULL) {
    printf("%s -> ", head->value.string);    
    head = head->next;
  }
  printf("NULL\n");
}