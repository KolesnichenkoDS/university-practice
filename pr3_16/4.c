#include <stdio.h>
#include <math.h>

double abs_value(double x) {
  return x > 0 ? x : -x;
}

double x_i(int i) {
  return pow(1 + 1 / (double) i, i);
}

int main() {
  double eps;
  printf("Введите эпсилон (погрешность): ");
  scanf("%lf", &eps);
  double x_previous = 0;
  double x_current = 0;
  for (int i = 1;; i++) {
    x_previous = x_current;
    x_current = x_i(i);
    printf("%lf\n", x_current);
    if (abs_value(x_current - x_previous) < eps) break;
  }
  printf("Результат: %lf", x_current);
}