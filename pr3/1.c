#include <stdio.h>

int main() {
  int k, x;
  scanf("%d", &x);
  k = x / 100 % 10;
  printf("k = %d\n", k);
}