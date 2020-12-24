#include <stdio.h>
#include <stdlib.h>

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
  int m, ii, n;

  printf("Введите размер матрицы: ");
  scanf("%d", &m);

  int matrix[m][m];

  printf("Не отсортированная матрица:\n");
  for (int i = 0; i < m * 4 - 1 + 4; i++) printf("-");
  printf("\n");
  for (int i = 0; i < m; i++) {
    printf("|");
    for (int j = 0; j < m; j++) {
      matrix[i][j] = rand() % 101;
      printf(" %-3d", matrix[i][j]);
    }
    printf(" ");
    printf("|\n");
  }
  for (int i = 0; i < m * 4 - 1 + 4; i++) printf("-");
  printf("\n\n");

  for (int i = 0; i < m; i++) sort(matrix[i], m);

  printf("Отсортированная матрица:\n");
  for (int i = 0; i < m * 4 - 1 + 4; i++) printf("-");
  printf("\n");
  for (int i = 0; i < m; i++) {
    printf("|");
    for (int j = 0; j < m; j++) {
      printf(" %-3d", matrix[i][j]);
    }
    printf(" ");
    printf("|\n");
  }
  for (int i = 0; i < m * 4 - 1 + 4; i++) printf("-");
  printf("\n");

  printf("Введите номер строки: ");
  scanf("%d", &n);

  printf("Введите номер минимума: ");
  scanf("%d", &ii);

  printf("%d-й минимум %d-й строки: %d", ii, n, matrix[n][ii]);
}