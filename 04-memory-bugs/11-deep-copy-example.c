#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define SIZE 5

struct String {
  char *value;
  size_t length;
};

bool string_copy(struct String *dest, const struct String *src);

int main(void) {
  struct String *source = malloc(sizeof(struct String));

  if (source == NULL)
    return 1;

  source->value = malloc(sizeof(char) * (SIZE + 1));

  if (source->value == NULL) {
    free(source);
    source = NULL;
    return 1;
  }

  strcpy(source->value, "Hello");
  source->length = SIZE;

  struct String *destination = malloc(sizeof(struct String));

  if (destination == NULL) {
    free(source->value);
    free(source);
    source = NULL;
    return 1;
  }

  if (string_copy(destination, source)) {
    printf("Source string value: %s, length: %zu\n", source->value, source->length);
    printf("Destination string value: %s, length: %zu", destination->value, destination->length);

    free(destination->value);
    free(destination);
  } else {
    printf("Deep copy failed");
    free(destination);
  }
  
  free(source->value);
  free(source);
  destination = NULL;
  source = NULL;

  return 0;
}

bool string_copy(struct String *dest, const struct String *src) {
  char *p_temp_cpy = malloc(sizeof(char) * (src->length + 1));

  if (p_temp_cpy == NULL)
    return false;

  strcpy(p_temp_cpy, src->value);
  dest->value = p_temp_cpy;
  dest->length = src->length;

  return true;
}