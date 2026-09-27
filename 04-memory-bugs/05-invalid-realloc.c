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

  numbers = realloc(numbers, sizeof(int) * (SIZE * 2)); // wrong, use a temp variable

  if (numbers == NULL) {
    // the original address is lost -> memory leak
    printf("Reallocation failed\n");
    return 1;
  }

  p = numbers;

  for (int i = 0; p < (numbers + (SIZE * 2)); ++p, ++i)
    *p = i;

  free(numbers);

  return 0;
}