#include <stdio.h>

void print_array_of_pointers(int **ptrs, size_t size);
void print_array_of_strings(char **words, size_t size);

void print_words(char *word);

#define SIZE 5
#define WORDS 3

int main(void) {
  int *ptrs[SIZE];

  /********** ASSIGN THE POINTERS TO THE ARRAY **********/

  int number_1 = 5;
  int *p_number_1 = &number_1;

  *ptrs = p_number_1;
  
  int number_2 = -10;
  int *p_number_2 = &number_2;
  
  *(ptrs + 1) = p_number_2;

  int number_3 = 67;
  int *p_number_3 = &number_3;

  *(ptrs + 2) = p_number_3;

  int number_4 = 147;
  int *p_number_4 = &number_4;

  *(ptrs + 3) = p_number_4;

  int number_5 = 9847;
  int *p_number_5 = &number_5;

  *(ptrs + 4) = p_number_5;

  print_array_of_pointers(ptrs, SIZE);
  
  *p_number_3 = 67;
  *p_number_1 = 67;
  
  print_array_of_pointers(ptrs, SIZE);

  char *words[WORDS];

  /********** ASSIGN THE STRINGS (ARRAY OF CHAR) TO THE ARRAY **********/

  char word_1[] = "Hello world!";
  
  *words = word_1;
  
  char word_2[] = "Hello C!";

  *(words + 1) = word_2;

  char word_3[] = "Hello pointers!";

  *(words + 2) = word_3;
  
  print_array_of_strings(words, WORDS);

  return 0;
}

void print_array_of_pointers(int **ptrs, size_t size) {
  for (int **p = ptrs; p < (ptrs + size); ++p)
    printf("%d ", **p);
  
  printf("\n");
}

void print_array_of_strings(char **words, size_t size) {
  for (char **p = words; p < (words + size); ++p) {
    print_words(*p);
    printf("\n");
  }
}

void print_words(char *word) {
  char *p_word = word;

  while (*p_word != '\0') {
    printf("%c", *p_word);
    ++p_word;
  }
}