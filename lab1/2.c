#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static const char digits[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

char* concat(char* left, char* right) {
  char* s = malloc(sizeof(char) * strlen(left) + strlen(right) + 1);
  s[0] = '\0';
  strcat(s, left);
  strcat(s, right);
  return s;
}

char* concatFree(char* left, char* right) {
  char* s = concat(left, right);
  free(left);
  free(right);
  return s;
}

char* toBase(long x, int base) {
  if (x == 0) return "0";
  if (x < 0) {
    char* mx = toBase(-x, base);
    char* minus = malloc(sizeof(char) * 2);
    minus[0] = '-';
    minus[1] = '\0';
    return concatFree(minus, mx);
  }
  char* s = malloc(sizeof(char) * 2);
  s[0] = digits[x % base];
  s[1] = '\0';
  if (x / base == 0) return s;
  return concatFree(toBase(x / base, base), s);
}

int main() {
  long input;
  printf("Введите десятичное целое число: ");
  scanf("%ld", &input);
  printf("В двоичном представлении %ld = %s\n", input, toBase(input, 2));
  printf("В восьмеричном представлении %ld = %s\n", input, toBase(input, 8));
  printf("В шестандцатеричном представлении %ld = %s\n", input, toBase(input, 16));

  return 0;
}