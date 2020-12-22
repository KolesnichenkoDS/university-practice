#include <stdio.h>

void numbersPlural(int x) {
  if (x == 1) printf("number");
  else printf("numbers");
}

int main() {
  double a, b, c, d;
  scanf("%lf", &a);
  scanf("%lf", &b);
  scanf("%lf", &c);
  scanf("%lf", &d);

  int posCount = 0,
      negCount = 0;

  if (a > 0) posCount++; else if (a < 0) negCount++;
  if (b > 0) posCount++; else if (b < 0) negCount++;
  if (c > 0) posCount++; else if (c < 0) negCount++;
  if (d > 0) posCount++; else if (d < 0) negCount++;

  printf("Got %d positive ", posCount);
  numbersPlural(posCount);
  printf(" and %d negative ", negCount);
  numbersPlural(negCount);
  printf(".\n");
  return 0;
}