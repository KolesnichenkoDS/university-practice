#include <stdio.h>

int main() {
  double x;
  printf("Введите дробное число: ");
  scanf("%lf", &x);
  printf("Первая цифра дробной части: %d", ((int) (x * 10)) % 10);

  return 0;
}