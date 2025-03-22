#include "../../s21_decimal.h"

big_s21_decimal convert_to_big_return(s21_decimal val) {
  big_s21_decimal result = {0};
  result.bits[0] = val.bits[0];
  result.bits[1] = val.bits[1];
  result.bits[2] = val.bits[2];
  result.bits[3] = 0;
  result.bits[4] = 0;
  result.bits[5] = 0;
  result.bits[6] = val.bits[3];
  result.bits[7] = 0;
  return result;
}
