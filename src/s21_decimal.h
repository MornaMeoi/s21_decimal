#ifndef S21_DECIMAL_H
#define S21_DECIMAL_H

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CODE_OK 0
#define CODE_CALCULATING_ERROR 1

#define EQUAL 0
#define GREATER 1
#define LESS -1
#define OK 0
#define INF(X) (X == (1.0 / 0.0))
#define NEG_INF(X) (X == (-1.0 / 0.0))
#define MAX_UINT -1
//               -1
//               4294962297
#define MAX_INT 2147483647
//               2147483648
// 1  1111111111 1111111111 1111111111
// 11 1111111111 1111111111 1111111111
// 10 0000000000 0000000000 0000000000
#define MIN_INT 2147483648
#define s21_NULL (void *)0
#define MAX_DEC 79228162514264337593543950336.0f
#define SCALE 0x00ff0000

typedef struct {
  int bits[4];
} s21_decimal;

typedef struct {
  int bits[8];
} big_s21_decimal;

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_is_equal(s21_decimal val1, s21_decimal val2);
int s21_is_greater(s21_decimal val1, s21_decimal val2);
int s21_is_greater_or_equal(s21_decimal val1, s21_decimal val2);
int s21_is_less(s21_decimal val1, s21_decimal val2);
int s21_is_less_or_equal(s21_decimal val1, s21_decimal val2);
int s21_is_not_equal(s21_decimal val1, s21_decimal val2);
int s21_from_decimal_to_float(s21_decimal src, float *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_floor(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_negate(s21_decimal value, s21_decimal *result);

void s21_add_bit(big_s21_decimal value_1, big_s21_decimal value_2,
                 big_s21_decimal *result);
void s21_sub_bit(big_s21_decimal *value_1, big_s21_decimal *value_2,
                 big_s21_decimal *result);

void mul_bit(big_s21_decimal val1, big_s21_decimal val2, big_s21_decimal *res);
int cout_1(big_s21_decimal val);
int find_1(big_s21_decimal val);

int get_bit_decimal(s21_decimal dec, int i);
void setbit_decimal(s21_decimal *dec, int i, int bit);
int get_sign_decimal(s21_decimal dec);
void set_sign_decimal(s21_decimal *dec, int sign);
int get_scale_decimal(s21_decimal dec);
void set_scale_decimal(s21_decimal *dec, int scale);
int is_zero_decimal(s21_decimal dec);
void null_decimal(s21_decimal *dec);

int get_bit_big_decimal(big_s21_decimal dec, int i);
void setbit_big_decimal(big_s21_decimal *dec, int i, int bit);
int get_sign_big_decimal(big_s21_decimal dec);
void set_sign_big_decimal(big_s21_decimal *dec, int sign);
int get_scale_big_decimal(big_s21_decimal dec);
void set_scale_big_decimal(big_s21_decimal *dec, int scale);
int is_zero_big_decimal(big_s21_decimal dec);
void null_big_decimal(big_s21_decimal *dec);

void shift_left(big_s21_decimal *decimal, int step);
void normalization(big_s21_decimal *a, big_s21_decimal *b);
void cmp_normalization(big_s21_decimal *a, big_s21_decimal *b);
void convert_to_big(s21_decimal dec, big_s21_decimal *big_dec);
void print_dec(s21_decimal a);
void print_big_dec(big_s21_decimal a);

big_s21_decimal convert_to_big_return(s21_decimal val);
int s21_cmp_decimal(s21_decimal val1, s21_decimal val2);
int get_sign(s21_decimal val);

int s21_is_not_equal_big(big_s21_decimal val1, big_s21_decimal val2);
int s21_is_less_or_equal_big(big_s21_decimal val1, big_s21_decimal val2);
int s21_is_less_big(big_s21_decimal val1, big_s21_decimal val2);
int s21_is_greater_or_equal_big(big_s21_decimal val1, big_s21_decimal val2);
int s21_is_greater_big(big_s21_decimal val1, big_s21_decimal val2);
int s21_is_equal_big(big_s21_decimal val1, big_s21_decimal val2);

void from_big_to_decimal(big_s21_decimal *big, s21_decimal *dec);
void div_ten(big_s21_decimal *dec);
void mud_ten(big_s21_decimal *dec);
void div_bit(big_s21_decimal value_1, big_s21_decimal value_2,
             big_s21_decimal *result, big_s21_decimal *temp);
int s21_is_greater_or_equal_big_help(big_s21_decimal val1,
                                     big_s21_decimal val2);

void div_add(big_s21_decimal value_1, big_s21_decimal *result, int i);
void mud_big(big_s21_decimal val1, big_s21_decimal val2,
             big_s21_decimal *result);
void mud_bit(big_s21_decimal val1, big_s21_decimal val2, big_s21_decimal *res);
int s21_cmp_big_decimal(big_s21_decimal val1, big_s21_decimal val2);
int s21_cmp_big_decimal_help(big_s21_decimal val1, big_s21_decimal val2);
int is_full(big_s21_decimal dec);
int s21_is_greater_big_help(big_s21_decimal dec1, big_s21_decimal dec2);
int s21_is_equal_big_help(big_s21_decimal dec1, big_s21_decimal dec2);

#endif