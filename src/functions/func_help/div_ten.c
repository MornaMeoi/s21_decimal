#include "../../s21_decimal.h"

void mud_ten(big_s21_decimal* dec) {
  big_s21_decimal ten = {0};
  null_big_decimal(&ten);
  ten.bits[0] = 10;
  big_s21_decimal temp_2 = {0};
  null_big_decimal(&temp_2);
  temp_2 = *dec;
  null_big_decimal(dec);
  mud_big(temp_2, ten, dec);
}
void div_ten(big_s21_decimal* dec) {
  big_s21_decimal ten = {0}, dec_temp = {0}, res_temp = {0};
  null_big_decimal(&ten);
  null_big_decimal(&dec_temp);
  ten.bits[0] = 10;
  dec_temp = *dec;
  div_bit(dec_temp, ten, dec, &res_temp);
}