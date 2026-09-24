#include <stdio.h>
#include <stdlib.h>

void print_string(const char* s, size_t size);

int main(void) {
  printf("Enter the string length: ");
  int size;
  scanf("%d", &size);

  int c;
  while ((c = getchar()) != '\n' && c != EOF);

  if (size > 0) {
    char *p_str = malloc(sizeof(char) * (size + 1));

    if (p_str != NULL) {
      printf("Enter the string: ");
      char *p = p_str;

      while (p < (p_str + size)) {
        int ch = fgetc(stdin);

        if (ch == EOF || ch == '\n')
          break;

        *p = (char) ch;
        ++p;
      }

      *p = '\0';
  
      print_string(p_str, size);
  
      free(p_str);

    } else
      printf("Cannot allocate memory");

  } else
    printf("Invalid size");

  return 0;
}

void print_string(const char* s, size_t size) {
  while (*s != '\0') {
    printf("%c", *s);
    ++s;
  }
}