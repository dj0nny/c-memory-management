#include <stdio.h>
#include <stdbool.h>

const void *generic_find(const void *array, size_t array_size, size_t element_size, bool (*predicate)(const void *element, void *context), void *context);
bool equal_int(const void *element, void *context);

int main(void) {
  int numbers[] = {10, 20, 35, 40};
  int target = 35;

  const int *found_element = (const int *) generic_find(numbers, sizeof(numbers) / sizeof(*numbers), sizeof(int), equal_int, &target);

  if (found_element != NULL)
    printf("Found element: %d", *found_element);
  else
    printf("Element not found");

  return 0;
}

const void *generic_find(const void *array, size_t array_size, size_t element_size, bool (*predicate)(const void *element, void *context), void *context) {
  for (size_t i = 0; i < array_size; ++i) {
   const unsigned char *current_element = ((const unsigned char *) array + (i * element_size));

    if (predicate(current_element, context))
      return current_element;
  }

  return NULL;
}

bool equal_int(const void *element, void *context) {
  int value = *(const int *) element;
  int target = *(int *) context;

  return value == target;
}