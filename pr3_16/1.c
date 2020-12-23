#include <stdio.h>
#include <math.h>

int powi(int x, int n) { return (int) pow((double) x, (double) n); }

int charToInt(char c) {
  switch (c) {
    case '1': return 1;
    case '2': return 2;
    case '3': return 3;
    case '4': return 4;
    case '5': return 5;
    case '6': return 6;
    case '7': return 7;
    case '8': return 8;
    case '9': return 9;
    default: return 0;
  }
}

int main() {
  char s[10];
  printf("Введите число, полученное выписыванием в обратном порядке цифр заданного целого трёхзначного числа: ");
  scanf("%s", s);
  int x = 0;
  for (int i = 0; i < 3; i++) {
    x += charToInt(s[i]) * powi(10, i);
  }
  printf("Число: %d\n", x);
}