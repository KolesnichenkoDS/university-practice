#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define BUFFER_SIZE 4096

int main() {
  char s[BUFFER_SIZE];
  printf("Введите строку: ");
  fgets(s, BUFFER_SIZE, stdin);
  int len = (int) strlen(s);
  bool isLastSpace = false;
  printf("Строка без лишних пробелов: ");
  for (int i = 0; i < len; i++) {
    if (s[i] == ' ') {
      if (!isLastSpace) {
        printf("%c", s[i]);
      }
      isLastSpace = true;
    } else {
      printf("%c", s[i]);
      isLastSpace = false;
    }
  }
}