#include <stdio.h>

/*
 * Найти  минимальный элемент матрицы С (размер m*n), и поменять его местами с первым элементом.
 */

int main() {
  int m, n;
  printf("Введите размеры сторон матрицы (через пробел): ");
  scanf("%d %d", &m, &n);
  int c[m][n];
  int min, min_i = 0, min_j = 0;
  for (int i = 0; i < m; i++) {
    printf("Введите строку матрицы номер %d (каждое значение на отдельной строке):\n", i + 1);
    for (int j = 0; j < n; j++) {
      int x;
      scanf("%d", &x);
      c[i][j] = x;
      if (i == 0 && j == 0) min = x;

      if (x < min) {
        min = x;
        min_i = i;
        min_j = j;
      }
    }
  }

  int first = c[0][0];
  c[0][0] = min;
  c[min_i][min_j] = first;

  for (int i = 0; i < m; i++) {
    printf("\n");
    for (int j = 0; j < n; j++) {
      printf(" %2d", c[i][j]);
    }
  }
}