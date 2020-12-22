// Сортировка перемешиванием

#include <stdio.h>

void sort(int *arr, int size) {
  int buff;
  int control = size;
  int left = 0;
  int right = size - 1;
  do {
    for (int i = left; i < right; i++) {
      if (arr[i] > arr[i + 1]) {
        buff = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = buff;
        control = i;
      }
    }
    right = control;
    for (int i = right; i > left; i--) {
      if (arr[i] < arr[i - 1]) {
        buff = arr[i];
        arr[i] = arr[i - 1];
        arr[i - 1] = buff;
        control = i;
      }
    }
    left = control;
  } while (left < right);
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