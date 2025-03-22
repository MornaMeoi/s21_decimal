#include "../../s21_decimal.h"

void set_sign_decimal(s21_decimal* dec, int sign) {
  setbit_decimal(dec, 127, sign);
}