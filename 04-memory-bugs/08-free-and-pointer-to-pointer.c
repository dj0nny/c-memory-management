#include <stdio.h>
#include <stdlib.h>

void safe_free(void **ptr);

int main(void) {
  int *number = malloc(sizeof(int));
  
  if (number == NULL)
    return 1;

  *number = 42;

  safe_free((void **) &number); // pass the address

  printf("%p\n", (void *)number);

  return 0;
}

void safe_free(void **ptr) { // must be **void for edit the original pointer
  free(*ptr);
  *ptr = NULL;
}