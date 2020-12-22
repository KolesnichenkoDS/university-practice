#include <stdio.h>

int digitsSum(x) {
  if (x < 0) return digitsSum(-x);

  int sum = 0;
  while (x > 0) {
    sum += x % 10;
    x /= 10;
  }
  return sum;
}

int main() {
  int x;
  printf("Введите целое число: ");
  scanf("%d", &x);
  printf("Сумма цифр: %d", digitsSum(x));
}