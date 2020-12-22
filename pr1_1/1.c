#include <stdio.h>
#include <math.h>

int main() {
  double a, b, c;
  scanf("%lf", &a);
  scanf("%lf", &b);
  scanf("%lf", &c);

  if (a == 0) {
    if (b == 0 && c == 0) {
      printf("x is any complex number\n");
      return 0;
    }

    if (b == 0 && c != 0) {
      printf("\n");
      return 0;
    }

    printf("%lf\n", c / b);
    return 0;
  }

  double d = b * b - 4 * a * c;

  if (d < 0) {
    printf("%lf ± %lf * i\n", -b / 2 / a, sqrt(-d) / 2 / a);
    return 0;
  }

  if (d == 0) {
    printf("%lf\n", -b / 2 / a);
    return 0;
  }

  printf("%lf ± %lf\n", -b / 2 / a, sqrt(d) / 2 / a);
  return 0;
}