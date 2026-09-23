#include <stdio.h>

int main(void) {
  int number = 67;
  int *p_number = &number;
  int **pp_number = &p_number;

  printf("Variable value: %d\n", number);
  printf("Variable address: %p\n", p_number);
  printf("Variable value (def): %d\n", *p_number);
  printf("Ddouble pointer address: %p\n", pp_number);
  printf("Variable double pointer value (def): %d\n\n", **pp_number);
  
  **pp_number = 77;
  
  printf("Variable value: %d\n", number);
  printf("Variable address: %p\n", p_number);
  printf("Variable value (def): %d\n", *p_number);
  printf("Ddouble pointer address: %p\n", pp_number);
  printf("Variable double pointer value (def): %d\n\n", **pp_number);

  return 0;
}