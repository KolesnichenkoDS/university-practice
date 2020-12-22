#include <stdio.h>
#include <math.h>

int main() {
  double a, b, c;
  printf("Введите коэффициент a: ");
  scanf("%lf", &a);
  printf("Введите коэффициент b: ");
  scanf("%lf", &b);
  printf("Введите коэффициент c: ");
  scanf("%lf", &c);

  if (a == 0) {
    if (b == 0 && c == 0) {
      printf("x — любое комплексное число\n");
      return 0;
    }

    if (b == 0 && c != 0) {
      printf("нет корней\n");
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