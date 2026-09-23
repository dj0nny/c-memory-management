#include <stdio.h>

struct MiscStruct {
  char letter;
  int number;
  int number_2;
  char letter_2;
};

int main(void) {
  int value = 0x12345678;
  unsigned char *ptr = (unsigned char *)&value;

  printf("Address: %p, value: %02X\n", (void *)ptr, ptr[0]);
  printf("Address: %p, value: %02X\n", (void *)(ptr + 1), ptr[1]);
  printf("Address: %p, value: %02X\n", (void *)(ptr + 2), ptr[2]);
  printf("Address: %p, value: %02X\n", (void *)(ptr + 3), ptr[3]);

  struct MiscStruct ms = {.letter = 'a', .number = 10, .number_2 = -4, .letter_2 = 'q'};
  unsigned char *s_ptr = (unsigned char *)&ms;

  printf("Address: %p, value: %02X\n", (void *)s_ptr, s_ptr[0]);
  printf("Address: %p, value: %02X\n", (void *)(s_ptr + 1), s_ptr[1]);
  printf("Address: %p, value: %02X\n", (void *)(s_ptr + 2), s_ptr[2]);
  printf("Address: %p, value: %02X\n", (void *)(s_ptr + 3), s_ptr[3]);


  
  return 0;
}