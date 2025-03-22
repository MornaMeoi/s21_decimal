#include "../../s21_decimal.h"

void print_dec(s21_decimal a) {
  printf("\nScale: %d\n", get_scale_decimal(a));
  for (int i = 0; i < 4; i++) {
    unsigned s = a.bits[i];
    printf("   bit[%d]: %u\n", i, s);
  }
  printf("\nSign: %d", get_sign_decimal(a));
  printf("\n");
  for (int i = 0; i < 128; i++) {
    printf("%d", get_bit_decimal(a, i));
  }
}