#include <stdio.h>
#include <stdbool.h>

size_t generic_count(const void *array, size_t array_size, size_t element_size, bool (*predicate)(const void *element, void *context), void *context);
bool is_greater_than_int(const void *value, void *context);

int main(void) {
  int numbers[] = {10, -20, 7, -1, 3, -11, 71};
  int target = 20;

  size_t counter = generic_count(numbers, sizeof(numbers) / sizeof(*numbers), sizeof(int), is_greater_than_int, &target);
  printf("There are %zu numbers greater than %d.", counter, target);

  return 0;
}

bool is_greater_than_int(const void *value, void *context) {
  const int current_value = *(const int *) value;
  int target = *(int *) context;

  return current_value > target;
}

size_t generic_count(const void *array, size_t array_size, size_t element_size, bool (*predicate)(const void *element, void *context), void *context) {
  size_t counter = 0;

  for (size_t i = 0; i < array_size; ++i) {
    const unsigned char *current_value = ((const unsigned char *) array + (i * element_size));
    
    if (predicate(current_value, context))
      ++counter;
  }

  return counter;
}