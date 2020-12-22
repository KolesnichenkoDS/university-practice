// Сортировка расчёской

#include <stdio.h>
#include <stdbool.h>

#define FACTOR 1.247330950103979

void sort(int *arr, int size) {
  int step = size;
  bool swapped = true;
  while (step >= 1 || swapped) {
    step = (int) ((double)step / FACTOR);
    swapped = false;
    for (int i = 0; i + step < size; i++) {
      if (arr[i] > arr[i + step]) {
        swapped = true;
        int tmp = arr[i];
        arr[i] = arr[i + step];
        arr[i + step] = tmp;
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