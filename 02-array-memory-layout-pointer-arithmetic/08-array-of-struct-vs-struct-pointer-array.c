#include <stdio.h>

#define SIZE 3

struct Person {
  char name[50];
  int age;
};

void print_array_of_struct(struct Person *people, size_t size);
void print_array_pointers_of_struct(struct Person **people, size_t size);

int main(void) {
  /************* POINTER TO STRUCT **************/
  struct Person person_1 = {.name = "John", .age = 24};
  struct Person *p_person_1 = &person_1;

  printf("Name: %s, age %d\n\n", p_person_1->name, p_person_1->age);

  /************* ARRAY OF STRUCT **************/
  struct Person person_2 = {.name = "Melody", .age = 18 };
  struct Person person_3 = {.name = "Lucy", .age = 33};

  struct Person people[SIZE] = {person_1, person_2, person_3};

  print_array_of_struct(people, SIZE);

  /************* ARRAY OF POINTERS OF STRUCT **************/

  struct Person *p_person_2 = &person_2;
  struct Person *p_person_3 = &person_3;

  struct Person *sp_people[SIZE] = {p_person_1, p_person_2, p_person_3};

  print_array_pointers_of_struct(sp_people, SIZE);

  return 0;
}

void print_array_of_struct(struct Person *people, size_t size) {
  for (struct Person *p = people; p < (people + size); ++p)
    printf("Name: %s, age %d\n", p->name, p->age);

  printf("\n");
}

void print_array_pointers_of_struct(struct Person **people, size_t size) {
  for (struct Person **p = people; p < (people + size); ++p)
    printf("Name: %s, age %d\n", (*p)->name, (*p)->age);
}