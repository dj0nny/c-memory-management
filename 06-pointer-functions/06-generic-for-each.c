#include <stdio.h>

#define SIZE 5

void generic_for_each(void *numbers, size_t array_size, size_t element_size, void (*callback)(void *element, void *context), void *context);
void multiply_value_int(void *element, void *context);
void multiply_value_double(void *element, void *context);
void print_int(void *element, void *context);
void print_double(void *element, void *context);

int main(void) {
  int numbers[SIZE] = {1, 2, 3, 5, 6};
  int context = 3;

  generic_for_each(numbers, SIZE, sizeof(int), multiply_value_int, &context);
  generic_for_each(numbers, SIZE, sizeof(int), print_int, NULL);

  printf("\n");

  double d_numbers[SIZE] = {2.1, -1.1447, -0.114, 5.0, 1.114e03};
  double d_context= 0.7114;

  generic_for_each(d_numbers, SIZE, sizeof(double), multiply_value_double, &d_context);
  generic_for_each(d_numbers, SIZE, sizeof(double), print_double, NULL);

  return 0;
}

void generic_for_each(void *numbers, size_t array_size, size_t element_size, void (*callback)(void *element, void *context), void *context) {
  for (size_t i = 0; i < array_size; ++i)
    callback((unsigned char *) numbers + (i * element_size), context);
}

void multiply_value_int(void *element, void *context) {
  int context_value = *(int *)context;
  *(int *)element *= context_value;
}

void multiply_value_double(void *element, void *context) {
  double d_context_value = *(double *)context;
  *(double *)element *= d_context_value;
}

void print_int(void *element, void *context) {
  printf("%d ", *(int *) element);
}

void print_double(void *element, void *context) {
  printf("%lf ", *(double *) element);
}