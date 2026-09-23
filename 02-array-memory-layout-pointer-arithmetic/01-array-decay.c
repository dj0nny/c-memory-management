#include <stdio.h>

#define SIZE 10

void print_array(int *numbers, size_t size);

int main(void) {
  int numbers[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int *p_numbers = numbers;

  print_array(numbers, SIZE);
  print_array(p_numbers, SIZE);

  return 0;
}

void print_array(int *numbers, size_t size) {
  for (int *p = numbers; p < (numbers + size); ++p)
    printf("%d ", *p);

  printf("\n");
}