#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct String {
  char *value;
  size_t length;
};

int main(void) {
  struct String *original = malloc(sizeof(struct String));

  if (original == NULL)
    return 1;

  original->length = 5;
  original->value = malloc(sizeof(char) * (original->length + 1));

  if (original->value == NULL) {
    free(original);
    return 1;
  }

  strcpy(original->value, "Hello");

  struct String *copy = malloc(sizeof(struct String));

  if (copy == NULL) {
    free(original->value);
    free(original);
    return 1;
  }

  *copy = *original; // shallow copy, assign a copy (address) the address of original

  free(original->value); // create a dangling pointer
  free(original);

  printf("%s\n", copy->value);

  free(copy);

  return 0;
}