#include <stdio.h>

void generic_transform(void *array, size_t array_size, size_t element_size, void (*transform)(void *element, void *context), void *context);
void square_int(void *element, void *context);

int main(void) {
  int numbers[] = {1, 2, 3, 4};
  generic_transform(numbers, sizeof(numbers) / sizeof(*numbers), sizeof(int), square_int, NULL);

  for (size_t i = 0; i < (sizeof(numbers) / sizeof(*numbers)); ++i)
    printf("%d ", *(numbers + i));

  return 0;
}

void square_int(void *element, void *context) {
  (void) context;

  int *value = element;
  *value *= *value; 
}

void generic_transform(void *array, size_t array_size, size_t element_size, void (*transform)(void *element, void *context), void *context) {
  for (size_t i = 0; i < array_size; ++i) {
    unsigned char *current_element = (unsigned char *) array + (i * element_size);
    transform(current_element, context);
  }
}