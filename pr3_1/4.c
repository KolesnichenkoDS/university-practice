#include <stdio.h>
#include <math.h>

double abs_value(double x) {
  return x > 0 ? x : -x;
}

double s_i(double x, int i) {
  return pow(-1.0, i) * x * (2.0 * i - 1.0) / pow(2.0 * i + 1.0, 2.0);
}

int main() {
  double eps, x;
  printf("Enter eps: ");
  scanf("%lf", &eps);
  printf("Enter x: ");
  scanf("%lf", &x);
  double s = 0;
  double s_i_current;
  for (int i = 1;; i++) {
    s_i_current = s_i(x, i);
    s += s_i_current;
    printf("s[%d] = %lf, s = %lf\n", i, s_i_current, s);
    if (abs_value(s_i_current) < eps) break;
  }
  printf("Result: %lf", s);
}