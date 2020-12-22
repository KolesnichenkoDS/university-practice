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
      int ii = (i + 1) <= n / 2 ? i : n - i - 1;
      matrix[i][j] = j >= ii && j < n - ii ? 1 : 0;
      printf(" %-2d", matrix[i][j]);
    }
    if (n >= 10) printf(" ");
    printf("|\n");
  }
  for (int i = 0; i < n * 3 - 1 - (n < 10) + 4; i++) printf("-");
  printf("\n");
  return 0;
}