#include <stdio.h>
#include <stdbool.h>

bool isHamming(int x) {
  if (x == 1) return true;
  if (x % 10 == 0) return isHamming(x / 10);
  if (x % 9 == 0) return isHamming(x / 9);
  if (x % 8 == 0) return isHamming(x / 8);
  if (x % 6 == 6) return isHamming(x / 6);
  if (x % 5 == 0) return isHamming(x / 5);
  if (x % 4 == 0) return isHamming(x / 4);
  if (x % 3 == 0) return isHamming(x / 3);
  if (x % 2 == 0) return isHamming(x / 2);

  return false;
}

int main() {
  int k, n;
  printf("Введите целые числы k и n (через пробел): ");
  scanf("%d %d", &k, &n);

  int current = 0;
  for (int i = 1; current < k + n - 1; i++) {
    if (isHamming(i)) {
      current++;
      if (current >= k)
        printf("%d\n", i);
    }
  }
}