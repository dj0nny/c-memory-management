#include <stdio.h>

#define SIZE 5

void for_each(int *array, size_t size, void (*callback)(int *value, void *context), void *context);
void multiply_by(int *value, void *context);
void print_array(int *array, size_t size);

int main(void) {
  int numbers[SIZE] = {1, 2, 3, 4, 5};

  int factor = 3;

  for_each(numbers, SIZE, multiply_by, &factor);

  print_array(numbers, SIZE);

  return 0;
}

void multiply_by(int *value, void *context) {
  int factor = *(int *)context;
  *value *= factor;
}

void for_each(int *array, size_t size, void (*callback)(int *value, void *context), void *context) {
  for (size_t i = 0; i < size; ++i)
    callback(array + i, context);
}

void print_array(int *array, size_t size) {
  for (size_t i = 0; i < size; ++i)
    printf("%d ", *(array + i));
}