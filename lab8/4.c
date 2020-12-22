// Сортировка вставками

#include <stdio.h>

void sort(int *arr, int size) {
  for (int i = 1; i < size; i++) {
    int x = arr[i];
    int j;
    for (j = i; j > 0 && arr[j - 1] > x; j--) {
      arr[j] = arr[j - 1];
    }
    arr[j] = x;
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