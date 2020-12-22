#include <stdio.h>
#include <math.h>

double f(double x) {
  return pow(x + 1, 2) * sqrt(log10(x));
}

double integral_tr(double a, double b, int n) {
  double sum = (f(b) + f(a)) / 2;
  double h = (b - a) / n;
  for (int i = 1; i < n; i++) {
    sum += f(a + i * h);
  }
  return sum * h;
}

double integral_si(double a, double b, int n) {
  double sum = f(a) + f(b);
  double h = (b - a) / n;
  for (int i = 1; i < n; i++) {
    if (i % 2) {
      sum += 4 * f(a + i * h);
    } else {
      sum += 2 * f(a + i * h);
    }
  }
  return sum * h / 3;
}

int main() {
  double a = 2;
  double b = 10;
  int n = 100;
  printf("I1 = %lf, I2 = %lf", integral_tr(a, b, n), integral_si(a, b, n));
}