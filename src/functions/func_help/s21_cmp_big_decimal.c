
/*#include "../../s21_decimal.h"

int s21_cmp_big_decimal(big_s21_decimal val1, big_s21_decimal val2) {
  int result = 123;

  if (get_sign_big_decimal(val1) < get_sign_big_decimal(val2)) {
    result = GREATER;  // 1
  } else if (get_sign_big_decimal(val1) > get_sign_big_decimal(val2)) {
    result = LESS;  //-1
  } else if (((val1.bits[3] ^ val2.bits[3]) == 0) &&
             ((val1.bits[2] ^ val2.bits[2]) == 0) &&
             ((val1.bits[1] ^ val2.bits[1]) == 0) &&
             ((val1.bits[0] ^ val2.bits[0]) == 0) &&
             ((val1.bits[4] ^ val2.bits[4]) == 0) &&
             ((val1.bits[5] ^ val2.bits[5]) == 0) &&
             ((val1.bits[6] ^ val2.bits[6]) == 0)) {
    result = EQUAL;
  } else {
    normalization(&val1, &val2);

    for (int i = 6; i >= 0; i--) {
      if (val1.bits[i] > val2.bits[i]) {
        result = GREATER;
        break;
      } else if (val1.bits[i] < val2.bits[i]) {
        result = LESS;
        break;
      }
    }
    if (get_sign_big_decimal(val1) == 1 || get_sign_big_decimal(val2) == 1) {
      if (result == GREATER) {
        result = LESS;
      } else if (result == LESS) {
        result = GREATER;
      }
    }
  }
  return result;
}*/
#include "../../s21_decimal.h"

int s21_cmp_big_decimal(big_s21_decimal val1, big_s21_decimal val2) {
  int result = 123;

  if (((val1.bits[3] ^ val2.bits[3]) == 0) &&
      ((val1.bits[2] ^ val2.bits[2]) == 0) &&
      ((val1.bits[1] ^ val2.bits[1]) == 0) &&
      ((val1.bits[0] ^ val2.bits[0]) == 0) &&
      ((val1.bits[4] ^ val2.bits[4]) == 0) &&
      ((val1.bits[5] ^ val2.bits[5]) == 0) &&
      ((val1.bits[6] ^ val2.bits[6]) == 0)) {
    result = EQUAL;
  } else {
    normalization(&val1, &val2);

    for (int i = 6; i >= 0; i--) {
      if (val1.bits[i] > val2.bits[i]) {
        result = GREATER;
        break;
      } else if (val1.bits[i] < val2.bits[i]) {
        result = LESS;
        break;
      }
    }
  }
  return result;
}
