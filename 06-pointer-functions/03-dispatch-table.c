#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 4

enum OperationCode {
  OP_ADD,
  OP_SUBTRACT,
  OP_MULTIPLY,
  OP_DIVIDE
};

int add(int x, int y);
int subtract(int x, int y);
int multiply(int x, int y);
int divide(int x, int y);

bool read_numbers(int *number_1, int *number_2);
bool execute_operation(enum OperationCode op_code, int a, int b, int *op_result);

int main(void) {
  int number_1;
  int number_2;

  read_numbers(&number_1, &number_2);

  int op_result;
  if (execute_operation(OP_ADD, number_1, number_2, &op_result))
    printf("Sum: %d\n", op_result);
  if (execute_operation(OP_SUBTRACT, number_1, number_2, &op_result))
    printf("Difference: %d\n", op_result);
  if (execute_operation(OP_MULTIPLY, number_1, number_2, &op_result))
    printf("Product: %d\n", op_result);
  if (execute_operation(OP_DIVIDE, number_1, number_2, &op_result))
    printf("Quotient: %d\n", op_result);
  if (execute_operation(-1, number_1, number_2, &op_result))
    printf("Quotient: %d\n", op_result);

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

bool read_numbers(int *number_1, int *number_2) {
  printf("Enter the first number: ");
  scanf("%d", number_1);
  printf("Enter the second number: ");
  scanf(" %d", number_2);
}

bool execute_operation(enum OperationCode op_code, int a, int b, int *op_result) {
  if (op_code < OP_ADD || op_code > OP_DIVIDE)
    return false;

  int (*operations[SIZE])(int, int) = {add, subtract, multiply, divide};

  *op_result = (*(operations + op_code))(a, b);

  return true;
}