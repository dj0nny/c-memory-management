#include <stdio.h>

void swap(int *a, int *b);

int main(void) {
  printf("Enter the first number: ");
  int number_1;
  scanf("%d", &number_1);

  printf("Enter the first number: ");
  int number_2;
  scanf("%d", &number_2);

  swap(&number_1, &number_2);

  printf("Swap: %d, %d", number_1, number_2);

  return 0;
}

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}