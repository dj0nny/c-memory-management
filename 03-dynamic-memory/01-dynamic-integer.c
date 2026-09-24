#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool check_allocation(int *p);

int main(void) {
  int *p_int = malloc(sizeof(int));

  if (check_allocation(p_int)) {
    printf("Insert a number: ");
    scanf("%d", p_int);
    printf("Number %d allocated successfully!\n", *p_int);
  } else
    printf("Cannot allocate memory.");


  free(p_int);
  printf("Memory deallocated");

  return 0;
}

bool check_allocation(int *p) {
  return p != NULL;
}