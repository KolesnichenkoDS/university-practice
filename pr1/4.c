#include <stdio.h>

int main() {
  double x, y;
  scanf("%lf", &x);
  scanf("%lf", &y);

  if (y <= 0 && y >= -3.0 / 2 * x - 6 && y >= 3.0 / 2 * x - 6)
    printf("true\n");
  else
    printf("false\n");

  return 0;
}