#include "../../s21_decimal.h"

int get_sign(s21_decimal val) { return get_bit_decimal(val, 127); }