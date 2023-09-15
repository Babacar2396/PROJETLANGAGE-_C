#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100

struct Student {
  char name[50];
  char surname[50];
  char phone[15];
  char class[10];
  float average;
};

void displayAll(struct Student students[], int size) {
  for (int i = 0; i < size; i++) {
    printf("Name: %s\n", students[i].name);
    printf("Surname: %s\n", students[i].surname);
    printf("Phone: %s\n", students[i].phone);
    printf("Class: %s\n", students[i].class);
    printf("Average: %.2f\n", students[i].average);
    printf("\n");
  }
}

void sortAndDisplay(struct Student students[], int size) {
  for (int i = 0; i < size - 1; i++) {
    for (int j = i + 1; j < size; j++) {
      if (students[i].average < students[j].average) {
        struct Student temp = students[i];
        students[i] = students[j];
        students[j] = temp;
      }
    }
  }
  displayAll(students, size);
}

void searchByCriteria(struct Student students[], int size) {
  int choice;
  char searchTerm[50];
  printf("Search by:\n");
  printf("1. Name\n");
  printf("2. Surname\n");
  printf("3. Phone\n");
  printf("4. Class\n");
  scanf("%d", &choice);
  switch (choice) {
    case 1:
      printf("Enter name: ");
      scanf("%s", searchTerm);
      for (int i = 0; i < size; i++) {
        if (strcmp(students[i].name, searchTerm) == 0) {
          printf("Name: %s\n", students[i].name);
          printf("Surname: %s\n", students[i].surname);
          printf("Phone: %s\n", students[i].phone);
          printf("Class: %s\n", students[i].class);
          printf("Average: %.2f\n", students[i].average);
          printf("\n");
        }
      }
      break;
    case 2:
      printf("Enter surname: ");
      scanf("%s", searchTerm);
      for (int i = 0; i < size; i++) {
        if (strcmp(students[i].surname, searchTerm) == 0) {
          printf("Name: %s\n", students[i].name);
          printf("Surname: %s\n", students[i].surname);
          printf("Phone: %s\n", students[i].phone);
          printf("Class: %s\n", students[i].class);
  printf("Average: %.2f\n", students[i].average);
          printf("\n");
        }
      }
      break;
    case 3:
      printf("Enter phone: ");
      scanf("%s", searchTerm);
      for (int i = 0; i < size; i++) {
        if (strcmp(students[i].phone, searchTerm) == 0) {
          printf("Name: %s\n", students[i].name);
          printf("Surname: %s\n", students[i].surname);
          printf("Phone: %s\n", students[i].phone);
          printf("Class: %s\n", students[i].class);
          printf("Average: %.2f\n", students[i].average);
          printf("\n");
        }
      }
      break;
    case 4:
      printf("Enter class: ");
      scanf("%s", searchTerm);
      for (int i = 0; i < size; i++) {
        if (strcmp(students[i].class, searchTerm) == 0) {
          printf("Name: %s\n", students[i].name);
          printf("Surname: %s\n", students[i].surname);
          printf("Phone: %s\n", students[i].phone);
          printf("Class: %s\n", students[i].class);
          printf("Average: %.2f\n", students[i].average);
          printf("\n");
        }
      }
      break;
    default:
      printf("Invalid choice\n");
      break;
  }
}

void modifyStudent(struct Student students[], int size) {
  char phone[15];
  float average;
  printf("Enter phone: ");
  scanf("%s", phone);
  for (int i = 0; i < size; i++) {
    if (strcmp(students[i].phone, phone) == 0) {
      printf("Enter new average: ");
      scanf("%f", &average);
      students[i].average = average;
      break;
    }
  }
}

int main() {
  struct Student students[MAX_STUDENTS];
  int size = 0;
  int choice;
  while (1) {
    printf("\n");
    printf("Menu:\n");
    printf("1. Afficher Tout\n");
    printf("2. Trier et Afficher par odre\n");
    printf("3. Rechercher selon un critere\n");
    printf("4. MModification de note\n");
    printf("5. Sortir\n");
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        displayAll(students, size);
        break;
      case 2:
        sortAndDisplay(students, size);
        break;
      case 3:
        searchByCriteria(students, size);
        break;
      case 4:
        modifyStudent(students, size);
        break;
      case 5:
        exit(0);
      default:
        printf("Invalid choice\n");
        break;
    }
  }
  return 0;
}
