#include <stdio.h>

#define SIZE 5

struct Person {
  char name[50];
  int age;
};

void int_print_address(int *numbers);
void double_print_address(double *d_numbers);
void struct_print_address(struct Person *people);

int main(void) {
  int numbers[SIZE] = {0, 1, 2, 3, 4};

  printf("/********** INT ARRAY **********\\\n");
  int_print_address(numbers);

  double d_numbers[SIZE] = {1.114, -0.114, 9, 5.7, 3.14};
  printf("\n/********** DOUBLE ARRAY **********\\\n");
  double_print_address(d_numbers);

  struct Person people[SIZE] = {{"John", 21}, {"Karen", 11}, {"Philip", 54}, {"Lucy", 18}, {"Max", 27}};
  printf("\n/********** STRUCT ARRAY **********\\\n");
  struct_print_address(people);


  return 0;
}

void int_print_address(int *numbers) {
  printf("Address: %p\n", numbers);
  printf("Address: %p\n", numbers + 1);
  printf("Difference (bytes): %td\n", (char *)(numbers + 1) - (char *)numbers);
  printf("Address: %p\n", numbers + 2);
  printf("Address: %p\n", numbers + 3);
  printf("Address: %p\n", numbers + 4);
}

void double_print_address(double *d_numbers) {
  printf("Address: %p\n", d_numbers);
  printf("Address: %p\n", d_numbers + 1);
  printf("Difference (bytes): %td\n", (char *)(d_numbers + 1) - (char *)d_numbers);
  printf("Address: %p\n", d_numbers + 2);
  printf("Address: %p\n", d_numbers + 3);
  printf("Address: %p\n", d_numbers + 4);
}

void struct_print_address(struct Person *people) {
  printf("Address: %p\n", people);
  printf("Address: %p\n", people + 1);
  printf("Difference (bytes): %td\n", (char *)(people + 1) - (char *)people);
  printf("Address: %p\n", people + 2);
  printf("Address: %p\n", people + 3);
  printf("Address: %p\n", people + 4);
}