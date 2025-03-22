#include "../../s21_decimal.h"

int cout_1(big_s21_decimal val) {
  int res = 0;
  for (int i = 191; i >= 0; i--) {
    if (get_bit_big_decimal(val, i) == 1) res++;
  }
  return res;
}
int find_1(big_s21_decimal val) {
  int res = 0;
  for (int i = 191; i >= 0; i--) {
    if (get_bit_big_decimal(val, i) == 1) {
      res = i;
      i = -1;
    }
  }
  return res;
}
// 228335555.123333