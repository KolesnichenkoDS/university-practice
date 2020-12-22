#include <stdio.h>

int numberLength(double x) {
  if (x < 0) return numberLength(-x) + 1;
  if (x < 10) return 4;
  return numberLength(x / 10) + 1;
}

int main() {
  double numbers[20];
  double sum = 0;
  int maxLength = 0;
  printf("Введите двадцать дробных чисел, по одному в строке:\n");
  for (int i = 0; i < 20; i++) {
    printf("[%d]: ", i + 1);
    scanf("%lf", &numbers[i]);
    int l = numberLength(numbers[i]);
    if (l > maxLength) maxLength = l;
    sum += numbers[i];
  }
  printf("Введённые числа:");
  for (int i = 0; i < 20; i++) {
    if (i != 0) printf(",");
    printf(" [%d] %.2f", i + 1, numbers[i]);
  }
  printf("\n");
  for (int i = 0; i < 20; i++) {
    int l = numberLength(numbers[i]);
    for (int j = 0; j < maxLength - l; j++) printf(" ");
    printf("%.2f\n", numbers[i]);
  }
  printf("----------\n");
  printf("Сумма: %.2f\n", sum);

  return 0;
}