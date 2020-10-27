#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846264338327950288
#endif

int main() {
  double a, b, y;
  scanf("%lf", &a);
  scanf("%lf", &b);
  scanf("%lf", &y);

  if (y >= M_PI * 2) {
    fprintf(stderr, "Angle should not be more or equal than PI * pr2 (180 degrees).");
    return 1;
  }

  if (y <= 0) {
    fprintf(stderr, "Angle should be a positive number.");
    return 1;
  }

  printf("%lf", a * b * sin(y) / 2);
  return 0;
}