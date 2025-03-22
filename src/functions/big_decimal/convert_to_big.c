#include "../../s21_decimal.h"

void convert_to_big(s21_decimal dec, big_s21_decimal* big_dec) {
  // printf("\n SIDN DO %d",get_sign_decimal(dec) );
  null_big_decimal(big_dec);
  // set_sign_big_decimal(big_dec, get_sign_decimal(dec));
  // set_scale_big_decimal(big_dec, get_scale_decimal(dec));
  //  printf("\n SIDN CC %d",get_sign_big_decimal(*big_dec) );
  big_dec->bits[2] = dec.bits[2];
  big_dec->bits[1] = dec.bits[1];
  big_dec->bits[0] = dec.bits[0];
  big_dec->bits[3] = 0;
  big_dec->bits[4] = 0;
  big_dec->bits[5] = 0;
  big_dec->bits[6] = dec.bits[3];
  // printf("\n SIDN DD %d",get_sign_big_decimal(*big_dec) );
  // printf("\n SIDN PP %d",get_sign_big_decimal(*big_dec) );
  // printf("\n SIDN FF %d",get_sign_big_decimal(*big_dec) );
}