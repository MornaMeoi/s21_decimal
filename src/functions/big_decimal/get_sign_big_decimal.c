#include "../../s21_decimal.h"

int get_sign_big_decimal(big_s21_decimal dec) {
  return get_bit_big_decimal(dec, 223);
}