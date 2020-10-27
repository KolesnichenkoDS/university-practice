#include <stdio.h>

int main() {
  double t, p, x, y;
  scanf("%lf", &t);
  scanf("%lf", &p);
  scanf("%lf", &x);
  scanf("%lf", &y);

  printf(x >= t && x <= p ? "true\n" : "false\n");
  return 0;
}