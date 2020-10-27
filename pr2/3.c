#include <stdio.h>
#include <stdbool.h>

int main() {
  unsigned char current;

  unsigned int count_a = 0;
  unsigned int count_e = 0;
  bool found_u = false;
  bool previous_n = false;
  bool previous_o = false;
  bool found_no = false;
  bool previous_minus = false;
  bool previous_plus = false;
  bool found_minus_plus;
  unsigned int count_minus = 0;
  unsigned int count_plus = 0;
  bool previous_c = false;
  bool previous_ch = false;
  bool previous_cha = false;
  bool found_char = false;
  while ((current = getchar()) != '.') {
    if (current == 'a') count_a++;
    if (current == 'e' && !found_u) count_e++;
    if (current == 'u') found_u = true;
    if (previous_n && current == 'o' || previous_o && current == 'n') found_no = true;
    if (previous_minus && current == '+' || previous_plus && current == '-') found_minus_plus = true;
    if (current == '-') count_minus++;
    if (current == '+') count_plus++;
    if (previous_cha && current == 'r') found_char = true;

    previous_n = current == 'n';
    previous_o = current == 'o';
    previous_minus = current == '-';
    previous_plus = current == '+';
    previous_cha = previous_ch && current == 'a';
    previous_ch = previous_c && current == 'h';
    previous_c = current == 'c';
  }

  printf("Character 'a' found %d times\n", count_a);
  printf("Character 'e' before first character 'u' found %d times\n", count_e);
  if (found_no) {
    printf("Character sequence 'no'/'on' was found\n");
  } else {
    printf("Character sequence 'no'/'on' was not found\n");
  }
  printf("Character '+' found %d times\n", count_plus);
  printf("Character '-' found %d times\n", count_minus);
  if (found_minus_plus) {
    printf("Characters '+' and '-' were found near each other\n");
  } else {
    printf("Characters '+' and '-' were not not found near each other\n");
  }
  if (found_char) {
    printf("Character sequence 'char' was found\n");
  } else {
    printf("Character sequence 'char' was not found\n");
  }
  return 0;
}