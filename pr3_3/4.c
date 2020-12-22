#include <stdio.h>

// x2n+1/(2n+1)!

double abs_value(double x) {
  return x > 0 ? x : -x;
}

int fac(int n) {
  if (n <= 0) return 1;
  return fac(n - 1) * n;
}

double s_i(double x, int i) {
  return x * (2 * i + 1) / ((double) fac(2 * i + 1));
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