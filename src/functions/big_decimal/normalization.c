#include "../../s21_decimal.h"

void normalization(big_s21_decimal* a, big_s21_decimal* b) {
  int sign1 = get_sign_big_decimal(*a);
  int sign2 = get_sign_big_decimal(*b);
  int scale_a = get_scale_big_decimal(*a);
  int scale_b = get_scale_big_decimal(*b);

  int diff = scale_a - scale_b;
  diff < 0 ? diff *= -1 : diff;
  while (diff > 0) {
    if (scale_a > scale_b) {
      big_s21_decimal temp = *b;
      shift_left(b, 3);
      shift_left(&temp, 1);
      s21_add_bit(*b, temp, b);
    } else if (scale_b > scale_a) {
      big_s21_decimal temp = *a;
      shift_left(a, 3);
      shift_left(&temp, 1);
      s21_add_bit(*a, temp, a);
    }
    diff--;
  }

  set_sign_big_decimal(a, sign1);
  set_sign_big_decimal(b, sign2);

  scale_a > scale_b ? set_scale_big_decimal(b, scale_a)
                    : set_scale_big_decimal(a, scale_b);
}