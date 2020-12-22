// Сортировка пузырьком

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
  int n;
  printf("Введите размер массива: ");
  scanf("%d", &n);
  int arr[n];
  for (int i = 0; i < n; i++) {
    printf("Введите %d-й элемент массива: ", i + 1);
    scanf("%d", arr + i);
  }

  sort(arr, n);

  printf("Результат: ");
  for (int i = 0; i < n; i++) {
    printf(" %d", arr[i]);
  }
}