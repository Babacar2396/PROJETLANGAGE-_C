#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 20

int count_valid_numbers(char numbers[MAX_LEN]) {
  int valid_count = 0;
  int count = strlen(numbers);
    int len = strlen(numbers);
    if (len != 9) return 0;
    if (numbers[0] != '7' ||
    (numbers[1] != '5' && numbers[1] != '6' && numbers[1] != '7' && numbers[1] != '8' && numbers[1] != '0'))
    valid_count++;
  return valid_count;
}

int main() {
  char numbers[100][MAX_LEN];
  int count = 0;
  printf("Entrer un nombre separer par des espaces (max 100):\n");
  char c = getchar();
  int i = 0, j = 0;
  while (c != '\n') {
    if (isspace(c)) {
      if (j > 0) {
        numbers[count][j] = '\0';
        count++;
        j = 0;
      }
    } else {
      numbers[count][j++] = c;
    }
    c = getchar();
  }
  if (j > 0) {
    numbers[count][j] = '\0';
    count++;
  }
  int valid_count = count_valid_numbers(numbers);
  printf("Valid numbers: \n");
  for (int i = 0; i < count; i++) {
    int len = strlen(numbers[i]);
    if (len != 9) continue;
    count = count_valid_numbers(numbers[i]);
  printf("Invalid numbers: \n");
  for (int i = 0; i < count; i++) {
    int len = strlen(numbers[i]);
    if (len == 9 && (numbers[i][0] == '7' && (numbers[i][1] == '5' || numbers[i][1] == '6' || numbers[i][1] == '7' || numbers[i][1] == '7' || numbers[i][1] == '0'))) continue;
    printf("%s\n", numbers[i]);
  }
  printf("Number of valid numbers: %d\n", count);
  printf("Number of invalid numbers: %d\n", count - valid_count);
  return 0;
}
}