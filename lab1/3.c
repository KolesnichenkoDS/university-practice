#include <stdio.h>
#include <math.h>

int powi(int x, int n) {
  return pow(x, n);
}

int main() {
  long n;
  int i;
  printf("Введите число: ");
  scanf("%ld", &n);
  printf("Введите позицию цифры (справа налево начиная с нуля): ");
  scanf("%d", &i);
  printf("В %d-й позиции стоит цифра %ld", i, (n % powi(10, i + 1) - n % powi(10, i)) / powi(10, i));

  return 0;
}