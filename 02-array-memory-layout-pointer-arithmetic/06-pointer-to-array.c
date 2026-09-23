#include <stdio.h>

#define N_SIZE 3
#define M_SIZE 4

void print_matrix(const int (*matrix)[M_SIZE], size_t rows);

int main(void) {
  int matrix[N_SIZE][M_SIZE] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};

  int (*p_matrix)[M_SIZE] = matrix;

  print_matrix(p_matrix, N_SIZE);


  return 0;
}

void print_matrix(const int (*matrix)[M_SIZE], size_t rows) {
  for (const int (*p)[M_SIZE] = matrix; p < matrix + rows; ++p) {
    for (const int *row_ptr = *p; row_ptr < *p + M_SIZE; ++row_ptr)
      printf("%d ", *row_ptr);
    printf("\n");
  }
}