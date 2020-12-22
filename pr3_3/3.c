#include <stdio.h>

/*
 * Даны целые числа m и n, где 0<=m<=n. Вычислить рекурсивно число сочетаний по формуле:
 */

int c(int m, int n) {
  if (m == 0) return 1;
  if (m == n) return 1;

  return c(m, n - 1) + c(m - 1, n - 1);
}

int main() {
  int m, n;
  printf("Введите числа m, n (через пробел): ");
  scanf("%d %d", &m, &n);
  printf("c(m, n) = %d", c(m, n));
}