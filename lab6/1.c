#include <stdio.h>

int main() {
  int m, n;
  printf("Введите стороны матрицы (через пробел): ");
  scanf("%d %d", &m, &n);
  int matrix[m][n];
  int vector[m];

  for (int i = 0; i < m; i++) {
    printf("Введите строку матрицы номер %d (каждое значение на отдельной строке):\n", i + 1);
    for (int j = 0; j < n; j++) {
      scanf("%d", &matrix[i][j]);
    }
  }

  printf("Введите элеметы вектора (каждый на отдельной строке):\n");
  for (int i = 0; i < m; i++) {
    scanf("%d", &vector[i]);
  }

  for (int i = 0; i < m && i < n; i++) {
    int tmp = vector[i];
    vector[i] = matrix[i][i];
    matrix[i][i] = tmp;
  }

  printf("Вектор:");
  for (int i = 0; i < m; i++) printf(" %d", vector[i]);
  printf("\n");

  printf("Матрица:\n");
  for (int i = 0; i < n; i++) {
    printf("|");
    for (int j = 0; j < n; j++) {
      printf(" %-2d", matrix[i][j]);
    }
    if (n >= 10) printf(" ");
    printf("|\n");
  }
}