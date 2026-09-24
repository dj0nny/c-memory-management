#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct String {
  char *value;
  size_t length;
};

bool create_string(struct String *p_string);
size_t allocate_string_value(char **pp_s_value);
bool deep_copy(struct String* string_1, struct String* string_2);
bool copy_string_value(char *pp_s_value_1, char *pp_s_value_2);

int main(void) {
  struct String string;

  if (create_string(&string)) {
    printf("String value: %s\n", string.value);
    printf("String length: %d\n\n", string.length);
  }

  struct String string_2;

  if (deep_copy(&string, &string_2)) {
    printf("Deep copy with success.\n");
    string_2.value[0] = 'X';
    printf("String value: %s\n", string.value);
    printf("String value: %s\n", string_2.value);

  }

  return 0;
}

bool create_string(struct String *p_string) {
  char *p_string_value = malloc(sizeof(char));

  if (p_string_value == NULL) {
    printf("Cannot allocate memory");
    return false;
  }

  p_string->value = p_string_value;

  size_t str_length = allocate_string_value(&(p_string->value));

  if (str_length != 0) {
    printf("String allocated successfully\n");
    p_string->length = str_length;
    return true;
  }

  return false;
}

size_t allocate_string_value(char **pp_s_value) {
  printf("Insert the string value: ");

  int ch;
  size_t string_length = 0;

  while ((ch = getchar()) != '\n' && ch != EOF) {
    ++string_length;

    char *temp_p_s_value = realloc(*pp_s_value, sizeof(char) * (string_length + 1));

    if (temp_p_s_value == NULL) {
      printf("Cannot reallocate memory");
      free(*pp_s_value);
      *pp_s_value = NULL;
      return 0;
    }

    *pp_s_value = temp_p_s_value;

    *(*pp_s_value + (string_length - 1)) = (char) ch;
  }

  if (*pp_s_value != NULL)
    *(*pp_s_value + string_length) = '\0';

  return string_length;
}


bool deep_copy(struct String* string_1, struct String* string_2) {
  string_2->length = string_1->length;

  string_2->value = malloc(sizeof(char) * (string_2->length + 1));

  if (string_2->value == NULL) {
    printf("Cannot allocate memory");
    return false;
  }

  return copy_string_value(string_1->value, string_2->value);
}

bool copy_string_value(char *p_s_value_1, char *p_s_value_2) {
  while (*p_s_value_1 != '\0') {
    *p_s_value_2 = *p_s_value_1;
    
    ++p_s_value_2;
    ++p_s_value_1;
  }

  *p_s_value_2 = '\0';

  return true;
}

