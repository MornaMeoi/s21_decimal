#include "../../s21_decimal.h"

void set_sign_big_decimal(big_s21_decimal* dec, int sign) {
  setbit_big_decimal(dec, 223, sign);
}