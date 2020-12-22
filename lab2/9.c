#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define BUFFER_SIZE 4096

int strsum(char *str) {
  int sum = 0;
  int len = (int) strlen(str);
  for (int i = 0; i < len; i++) {
    if (str[i] != ' ') sum += tolower(str[i]);
  }
  return sum;
}

int compare(char *left, char *right) {
  int suml = strsum(left);
  int sumr = strsum(right);
  if (suml > sumr) return 1;
  if (suml < sumr) return -1;
  return 0;
}

int main() {
  char left[BUFFER_SIZE];
  char right[BUFFER_SIZE];
  printf("Введите первую строку: ");
  fgets(left, BUFFER_SIZE, stdin);
  printf("Введите вторую строку: ");
  fgets(right, BUFFER_SIZE, stdin);
  printf("Результат: %d", compare(left, right));
}