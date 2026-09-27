#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int main(void) {
  int *numbers = malloc(sizeof(int) * SIZE);

  if (numbers == NULL)
    return 1;

  int *p = numbers;

  for (int i = 0; p < (numbers + SIZE); ++p, ++i)
    *p = i;

  numbers = malloc(sizeof(int) * (SIZE * 2)); // lost pointer, memory leak

  if (numbers == NULL)
    return 1;

  for (int *p = numbers; p < (numbers + (SIZE * 2)); ++p)
    printf("%d ", *p);

  free(numbers);

  return 0;
}