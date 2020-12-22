// Сортировка выбором

#include <stdio.h>

void sort(int *arr, int size) {
  for (int i = 0; i < size - 2; i++) {
    int least = i;
    for (int j = i + 1; j < size - 1; j++) {
      if (arr[j] < arr[least]) {
        least = j;
      }
    }
    int tmp = arr[i];
    arr[i] = arr[least];
    arr[least] = tmp;
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