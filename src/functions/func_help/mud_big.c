#include "../../s21_decimal.h"

void mud_big(big_s21_decimal val1, big_s21_decimal val2,
             big_s21_decimal* result) {
  big_s21_decimal res = {0};
  null_big_decimal(&res);
  // printf_big_decimal(val1);
  // printf_big_decimal(val2);
  unsigned int sign_1 = get_sign_big_decimal(val1);
  unsigned int sign_2 = get_sign_big_decimal(val2);
  unsigned scale_1 = get_scale_big_decimal(val1);
  unsigned scale_2 = get_scale_big_decimal(val2);
  unsigned int sign = sign_2 | sign_1;
  cout_1(val1) <= cout_1(val2) ? mud_bit(val2, val1, &res)
                               : mud_bit(val1, val2, &res);
  set_scale_big_decimal(&res, scale_2 + scale_1);
  set_sign_big_decimal(&res, sign);
  // need convertation_to_decimal
  *result = res;
}
