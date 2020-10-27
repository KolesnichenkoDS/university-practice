#include <stdio.h>

int numberLength(int x) {
  if (x < 0) return numberLength(-x) + 1;
  if (x < 10) return 1;
  return numberLength(x / 10) + 1;
}

int main() {
  int numbers[20];
  int sum = 0;
  int maxLength = 0;
  printf("Введите двадцать целых чисел, по одному в строке:\n");
  for (int i = 0; i < 20; i++) {
    printf("[%d]: ", i + 1);
    scanf("%d", &numbers[i]);
    int l = numberLength(numbers[i]);
    if (l > maxLength) maxLength = l;
    sum += numbers[i];
  }
  printf("Введённые числа:");
  for (int i = 0; i < 20; i++) {
    if (i != 0) printf(",");
    printf(" [%d] %d", i + 1, numbers[i]);
  }
  getchar();
  printf("\nНажмите ENTER, чтобы вывести числа столбиком.");
  getchar();
  printf("\n");
  for (int i = 0; i < 20; i++) {
    int l = numberLength(numbers[i]);
    for (int j = 0; j < maxLength - l; j++) printf(" ");
    printf("%d\n", numbers[i]);
  }
  printf("----------\n");
  printf("Сумма: %d", sum);

  return 0;
}