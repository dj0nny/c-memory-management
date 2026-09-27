#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int main(void) {
  int *numbers = malloc(SIZE * sizeof(int));

  if (numbers == NULL)
    return 1;

  for (size_t i = 0; i <= SIZE; ++i) // out of range
    numbers[i] = (int) i;

  printf("%d\n", numbers[5]); // undefined behaviour

  free(numbers);

  return 0;
}