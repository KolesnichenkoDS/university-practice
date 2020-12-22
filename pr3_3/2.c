#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <math.h>

static const char digits[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

char *concat(char *left, char *right) {
  char *s = malloc(sizeof(char) * strlen(left) + strlen(right) + 1);
  s[0] = '\0';
  strcat(s, left);
  strcat(s, right);
  return s;
}

char *concatFree(char *left, char *right) {
  char *s = concat(left, right);
  free(left);
  free(right);
  return s;
}

char *toBase(u_int16_t x, int base) {
  if (x == 0)
    return "0";
  if (x < 0) {
    char *mx = toBase(-x, base);
    char *minus = malloc(sizeof(char) * 2);
    minus[0] = '-';
    minus[1] = '\0';
    return concatFree(minus, mx);
  }
  char *s = malloc(sizeof(char) * 2);
  s[0] = digits[x % base];
  s[1] = '\0';
  if (x / base == 0)
    return s;
  return concatFree(toBase(x / base, base), s);
}

char *toBinary(u_int16_t x) {
  char *s = toBase(x, 2);
  while (strlen(s) < 16) {
    char *zero = malloc(sizeof (char) * 2);
    zero[0] = '0';
    zero[1] = '\0';
    s = concatFree(zero, s);
  }
  return s;
}

char *makeRange(uint8_t start, uint8_t end) {
  char *s = malloc(100);
  for (int i = 0; i < 100; i++) s[i] = ' ';
  s[99] = '\0';
  s[start] = '^';
  for (int i = start + 1; i < end; i++) s[i] = '.';
  s[end] = '^';

  return s;
}

/*
 * Заменить в целочисленной переменной x n бит, начиная с позиции p, n старшими инвертированными битами целочисленной переменной y.
 *
 * x = 0010 1011 1010 0010
 *        ^....^
 *
 * y = 1001 0110 0101 1110
 *~y = 0110 1001 1010 0001
 *     ^....^
 *
 * n = 5
 * p = 3
 *
 * r = 0010 1101 1010 0010
 */

int main() {
  u_int16_t x, y, n, p;
  printf("Введите числа x, y, n, p (через пробел): ");
  scanf("%hu %hu %hu %hu", &x, &y, &n, &p);
  printf(" x = 0b%s\n"
         "       %s\n"
         " y = 0b%s\n"
         "~y = 0b%s\n"
         "       %s\n",
         toBinary(x),
         makeRange(p, p + n - 1),
         toBinary(y),
         toBinary(~y),
         makeRange(0, n - 1)
  );
  char *sx = toBinary(x);
  char *sny = toBinary(~y);
  for (int i = 0; i < n; i++) {
    sx[p + i] = sny[i];
  }
  uint16_t r = 0;
  for (int i = 0; i < 16; i++) {
    if (sx[15 - i] == '1') r += pow(2, i);
  }
  printf(" r = 0b%s\n"
         " r = %hu",
         sx,
         r);
}