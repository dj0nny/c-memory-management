#include <stdio.h>
#include <stdlib.h>

int *create_number(void);

int main(void) {
  int *number = create_number();

  if (number == NULL)
    return 1;

  printf("%d\n", *number);

  return 0;
}

int *create_number(void) {
  int *number = malloc(sizeof(int));

  if (number == NULL)
    return NULL;

  *number = 67;

  free(number); // generate a dangling pointer

  return number;
}