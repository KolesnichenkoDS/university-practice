#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

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

bool isPalindrome(int x) {
  char *s = toBase(x, 10);
  int len = strlen(s);
  for (int i = 0; i < len; i++) {
    if (s[i] != s[len - i - 1]) {
      return false;
    }
  }
  return true;
}

int main() {
  int x;
  printf("Введите число: ");
  scanf("%d", &x);
  if (isPalindrome(x)) {
    printf("%d является палиндромом\n", x);
  } else {
    printf("%d не является палиндромом\n", x);
  }
}