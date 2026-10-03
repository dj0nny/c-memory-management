#include <stdio.h>


int add(int x, int y);
int subtract(int x, int y);
int multiply(int x, int y);

int apply_operation(int (*operation)(int, int), int x, int y);

int main(void) {
  printf("Sum: %d\n", apply_operation(add, 10, 5));
  printf("Difference: %d\n", apply_operation(subtract, 10, 5));
  printf("Product: %d\n", apply_operation(multiply, 10, 5));

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

int apply_operation(int (*operation)(int, int), int x, int y) {
  return operation(x, y);
}