#include <stdio.h>
#include <stdbool.h>

int abs(int x) { return x > 0 ? x : -x; }

int main() {
  int x;
  while (true) {
    scanf("%d", &x);
    if (x >= -9 && x <= 9) {
      if (x < 0) printf("minus ");
      switch (abs(x)) {
      case 0: printf("zero\n");  break;
      case 1: printf("one\n");   break;
      case 2: printf("two\n");   break;
      case 3: printf("three\n"); break;
      case 4: printf("four\n");  break;
      case 5: printf("five\n");  break;
      case 6: printf("six\n");   break;
      case 7: printf("seven\n"); break;
      case 8: printf("eight");   break;
      case 9: printf("nine\n");  break;
      }
      return 0;
    }
    printf("Wrong input, expected integer number from -9 to 9\n");
  }
}