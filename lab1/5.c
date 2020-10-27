#include <stdio.h>

long reverse(long x) {
  if (x < 0) return -reverse(-x);
  long res = 0;
  while (x > 0) {
    res = res * 10 + x % 10;
    x /= 10;
  }
  return res;
}

int main() {
  long x;
  printf("Введите целое число: ");
  scanf("%ld", &x);
  printf("Это число справа налево: %ld\n", reverse(x));

  return 0;
}