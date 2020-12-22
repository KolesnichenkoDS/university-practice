#include <stdio.h>
#include <stdbool.h>

bool isSimple(int x) {
  for (int i = 2; i < x; i++) {
    if (x % i == 0) return false;
  }
  return true;
}

void printFactors(int x) {
  if (isSimple(x)) { printf("%d\n", x); }
  for (int i = 2; i < x; i++) {
    if (x % i == 0) {
      printFactors(i);
      printFactors(x / i);
      return;
    }
  }
}

int main() {
  int x;
  printf("Введите число: ");
  scanf("%d", &x);
  printFactors(x);
}