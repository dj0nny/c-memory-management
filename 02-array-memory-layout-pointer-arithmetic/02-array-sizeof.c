#include <stdio.h>

#define SIZE 10

void print_array(int *number);

int main(void) {
  int numbers[SIZE] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  printf("Size array: %zu bytes\n", sizeof(numbers));
  printf("Size array element: %zu bytes\n", sizeof(numbers[0]));
  printf("Size array (size element x size): %zu bytes\n", sizeof(numbers[0]) * SIZE);

  print_array(numbers);

  return 0;
}

void print_array(int *number) {
  printf("Size array (pointer) in function: %zu bytes\n", sizeof(number));
  printf("Size first element: %zu bytes", sizeof(*number));
}