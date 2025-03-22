#include "../../s21_decimal.h"

void print_big_dec(big_s21_decimal a) {
  printf("\nScale: %d\n", get_scale_big_decimal(a));
  printf("\nSign %d", get_sign_big_decimal(a));
  printf("\n");
  for (int i = 0; i < 7; i++) {
    unsigned s = a.bits[i];
    printf("   bit[%d]: %u\n", i, s);
  }
}