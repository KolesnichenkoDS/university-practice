#include <stdio.h>
#include <math.h>

int powi(int x, int n) {
  return (int) pow((double) x, (double) n);
}

int main() {
  int x;
  printf("Введите число: ");
  scanf("%d", &x);
  int n = (int) floor(log10(x)) + 1;
  int digits[n];

  printf("Цифры:");
  for (int i = 0; i < n; i++) {
    digits[i] = (int) floor(x / pow(10, n - i - 1)) % 10;
    printf(" %d", digits[i]);
  }
  printf("\n");
}