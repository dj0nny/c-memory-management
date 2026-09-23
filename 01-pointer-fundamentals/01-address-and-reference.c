#include <stdio.h>

int main(void) {
  int number = 67;
  int *p_number = &number;

  printf("Variable value: %d\n", number);
  printf("Variable address: %p\n", p_number);
  printf("Variable value (def): %d\n\n", *p_number);
  
  *p_number = 77;

  printf("Variable value: %d\n", number);
  printf("Variable address: %p\n", p_number);
  printf("Variable value (def): %d", *p_number);

  return 0;
}