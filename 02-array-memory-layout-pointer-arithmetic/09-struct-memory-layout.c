#include <stdio.h>

struct MiscStruct {
  char letter;
  int number;
  double d_number;
  char string[10];
};

int main(void) {
  printf("Size of struct: %zu\n", sizeof(struct MiscStruct));
  
  struct MiscStruct ms = {.letter = 'a', .number = 10, .d_number = 3.14, .string = "Hello"};
  printf("Size of variable of type struct: %zu\n\n", sizeof(ms));

  printf("Address of field letter: %p\n", &(ms.letter));
  printf("Address of field number: %p\n", &(ms.number));
  printf("Address of field d_number: %p\n", &(ms.d_number));
  printf("Address of field string[10]: %p\n\n", &(ms.string));

  printf("Distance (in bytes) number - letter: %td\n", (char *)&(ms.number) - (char *)&(ms.letter));
  printf("Distance (in bytes) d_number - number: %td\n", (char *)&(ms.d_number) - (char *)&(ms.number));
  printf("Distance (in bytes) string - d_number: %td\n", (char *)&(ms.string) - (char *)&(ms.d_number));
  printf("Distance (in bytes) string - number: %td\n", (char *)&(ms.string) - (char *)&(ms.number));


  return 0;
}