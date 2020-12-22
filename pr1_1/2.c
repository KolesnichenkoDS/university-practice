#include <stdio.h>
#include <math.h>

int main() {
  double x, y;
  scanf("%lf", &x);
  scanf("%lf", &y);

  printf("%lf\n", (1 + sqrt(x + 1)) / cos(12 * y - 4));
  return 0;
}