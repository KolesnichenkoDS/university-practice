#include <stdio.h>

int main() {
  int n;
  printf("Введите размер матрицы: ");
  scanf("%d", &n);
  int matrix[n][n];
  for (int i = 0; i < n * 3 - 1 - (n < 10) + 4; i++) printf("-");
  printf("\n");
  for (int i = 0; i < n; i++) {
    printf("|");
    for (int j = 0; j < n; j++) {
      matrix[i][j] = i % 2 ? n - j : j + 1;
      printf(" %-2d", matrix[i][j]);
    }
    if (n >= 10) printf(" ");
    printf("|\n");
  }
  for (int i = 0; i < n * 3 - 1 - (n < 10) + 4; i++) printf("-");
  printf("\n");
  return 0;
}