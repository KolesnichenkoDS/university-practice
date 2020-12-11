#include <stdio.h>
#include <stdbool.h>

void sort(int *arr, int size) {
  bool isSorted = false;
  while (!isSorted) {
    isSorted = true;
    for (int i = 0; i < size - 1; i++) {
      if (arr[i] > arr[i + 1]) {
        isSorted = false;
        int x = arr[i];
        int y = arr[i + 1];
        arr[i] = y;
        arr[i + 1] = x;
        break;
      }
    }
  }
}

int main() {
  int n, m;
  printf("Введите размеры двух массивов (через пробел): ");
  scanf("%d %d", &n, &m);
  int arr[n + m];
  printf("Введите элементы первого массива (каждый на отдельной строке):\n");
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    arr[i] = x;
  }
  printf("Введите элементы второго массива (каждый на отдельной строке):\n");
  for (int i = n; i < n + m; i++) {
    int x;
    scanf("%d", &x);
    arr[i] = x;
  }

  sort(arr, n + m);

  printf("Результат:");
  for (int i = 0; i < n + m; i++) printf(" %d", arr[i]);
  printf("\n");

  return 0;
}