#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Buffer {
  char *data;
  size_t size;
};

int main(void) {
  struct Buffer *a = malloc(sizeof(struct Buffer));

  if (a == NULL)
    return 1;

  a->size = 6;
  a->data = malloc(a->size * sizeof(char));

  if (a->data == NULL) {
    free(a);
    return 1;
  }

  strcpy(a->data, "Hello");

  struct Buffer *b = malloc(sizeof(struct Buffer));

  if (b == NULL) {
    free(a->data);
    free(a);
    return 1;
  }

  // shallow copy
  b->data = a->data;
  b->size = a->size;  

  free(a->data); // produced a dangling pointer 
  free(a);

  printf("%s\n", b->data); // undefined behavior

  free(b);

  return 0;
}