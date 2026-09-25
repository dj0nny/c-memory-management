#include <stdio.h>
#include <stdlib.h>

struct String {
  char *value;
  size_t length;
};

struct String *create_string(const char *text);
void destroy_string(struct String *string);
struct String *transfer_ownership(struct String **string);

size_t allocate_string_value(char **pp_s_value, const char *text);

int main(void) {
  struct String *s_1 = create_string("Hello dynamic memory");

  if (s_1 == NULL) {
    printf("Failed to create a string");
    return 1;
  }
  
  printf("String: %s\n", s_1->value);
  printf("String length: %d\n", s_1->length);

  
  struct String *s_2 = transfer_ownership(&s_1);

  if (s_2 == NULL) {
    printf("Ownership transfer failed.\n");
    return 1;
  }

  if (s_1 == NULL)
    printf("s1 is NULL\n");

  printf("String: %s\n", s_2->value);
  printf("String length: %zu\n", s_2->length);

  destroy_string(s_2);

  return 0;
}

struct String *create_string(const char *text) {
  if (text == NULL)
    return NULL;

  struct String *string = malloc(sizeof(struct String));

  if (string == NULL) {
    printf("Cannot allocate memory for struct String.\n");
    return NULL;
  }

  string->value = malloc(sizeof(char));

  if (string->value == NULL) {
    printf("Cannot allocate memory for string value.\n");
    free(string);
    return NULL;
  }

  size_t string_size = allocate_string_value(&(string->value), text);

  if (string_size == 0 && *text != '\0') {
    printf("Failed to allocate the string.\n");
    free(string->value);
    free(string);
    return NULL;
  }

  string->length = string_size;

  return string;
}

size_t allocate_string_value(char **pp_s_value, const char *text) {
  size_t temp_string_length = 0;

  while (*text != '\0') {
    ++temp_string_length;

    char *temp = realloc(*pp_s_value, sizeof(char) * (temp_string_length + 1));

    if (temp == NULL) {
      printf("Cannot reallocate memory\n");
      free(*pp_s_value);
      *pp_s_value = NULL;
      return 0;
    }

    *pp_s_value = temp;

    *(*pp_s_value + (temp_string_length - 1)) = *text;

    ++text;
  }

  *(*pp_s_value + temp_string_length) = '\0'; 

  return temp_string_length;
}

struct String *transfer_ownership(struct String **string) {
  if (string == NULL)
    return NULL;

  struct String *transfer_string = *string;

  *string = NULL;
  return transfer_string;
}

void destroy_string(struct String *string) {
  free(string->value);
  free(string);

  printf("String deallocated\n");
}
