#include <stdint.h>
#include <stdio.h>
#include <locale.h>

uint32_t pack(const uint8_t cs[4]) {
  uint32_t result = 0;
  result += (uint32_t)cs[0];
  result += (uint32_t)cs[1] << 8u;
  result += (uint32_t)cs[2] << 16u;
  result += (uint32_t)cs[3] << 24u;
  return result;
}

void unpack(uint32_t p, uint8_t *cs) {
  cs[0] = (uint8_t)p;
  cs[1] = (uint8_t)(p >> 8u);
  cs[2] = (uint8_t)(p >> 16u);
  cs[3] = (uint8_t)(p >> 24u);
}

int main() {
  uint8_t cs[4];
  uint8_t ds[4];
  printf("Введите четыре символа: ");
  cs[0] = getchar();
  cs[1] = getchar();
  cs[2] = getchar();
  cs[3] = getchar();
  uint32_t packed = pack(cs);
  printf("packed = %d\n", packed);
  unpack(packed, ds);
  printf("unpacked = %c, %c, %c, %c\n", ds[0], ds[1], ds[2], ds[3]);
  return 0;
}