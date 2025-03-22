#include "../../s21_decimal.h"

#define EQUAL 0
#define GREATER 1
#define LESS -1

/*
  Вернет 1 при a > b, 0 при a == b, -1 при a < b
*/
int s21_cmp_decimal(s21_decimal val1, s21_decimal val2) {
  int result = EQUAL;

  if (get_sign(val1) < get_sign(val2)) {
    result = GREATER;
  } else if (get_sign(val1) > get_sign(val2)) {
    result = LESS;
  } else {
    big_s21_decimal big_val1 = convert_to_big_return(val1);
    big_s21_decimal big_val2 = convert_to_big_return(val2);

    normalization(&big_val1, &big_val2);

    for (int i = 223; i >= 0; i--) {
      if (get_bit_big_decimal(big_val1, i) > get_bit_big_decimal(big_val2, i)) {
        result = get_sign(val1) ? LESS : GREATER;
        i = -1;
      } else if (get_bit_big_decimal(big_val1, i) <
                 get_bit_big_decimal(big_val2, i)) {
        result = get_sign(val1) ? GREATER : LESS;
        i = -1;
      }
    }
  }

  return result;
}