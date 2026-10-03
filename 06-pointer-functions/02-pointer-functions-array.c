#include <stdio.h>
#include <stdlib.h>

#define SIZE 4

int add(int x, int y);
int subtract(int x, int y);
int multiply(int x, int y);
int divide(int x, int y);

int apply_operations(int (**operations)(int, int), size_t operation_count, size_t index, int a, int b);

int main(void) {
  int (*operations[SIZE])(int, int) = {add, subtract, multiply, divide};

  printf("Sum: %d\n", apply_operations(operations, SIZE, 0, 10, 5));
  printf("Difference: %d\n", apply_operations(operations, SIZE, 1, 10, 5));
  printf("Product: %d\n", apply_operations(operations, SIZE, 2, 10, 5));
  printf("Quotient: %d\n", apply_operations(operations, SIZE, 3, 10, 5));

  return 0;
}

int add(int x, int y) {
  return x + y;
}

int subtract(int x, int y) {
  return x - y;
}

int multiply(int x, int y) {
  return x * y;
}

int divide(int x, int y) {
  if (y != 0)
    return x / y;

  printf("Cannot divide by 0");
  exit(EXIT_FAILURE);
}

int apply_operations(int (**operations)(int, int), size_t operation_count, size_t index, int a, int b) {
  if (index < operation_count)
    return (*(operations + index))(a, b);

  exit(EXIT_FAILURE);
}