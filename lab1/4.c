#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

const char *intToBinary(long x) {
  char *b = malloc(sizeof(char));
  b[0] = '\0';

  while (x > 0) {
    char *b1 = concat(x & 1 ? "1" : "0", b);
    free(b);
    b = b1;
    x >>= 1;
  }

  return b;
}

int diff(long n1, long n2) {
  int res = 0, k;
  long j = 1;
  for (k = 0; k < 32; k++) {
    if ((j & n1) != (j & n2))
      res++;
    j = j << 1;
  }
  return res;
}

int main() {
  long n1, n2;
  printf("Введите два целых числа (через пробел): ");
  scanf("%ld %ld", &n1, &n2);
  printf("n1    = %64s\n", intToBinary(n1));
  printf("n2    = %64s\n", intToBinary(n2));
  printf("n1^n2 = %64s\n", intToBinary(n1 ^ n2));
  printf("Расстояние между n1 и n2: %d\n", diff(n1, n2));

  return 0;
}