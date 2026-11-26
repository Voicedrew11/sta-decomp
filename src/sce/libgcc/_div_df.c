/* libgcc.a member _div_df.o (from fp-bit.c, double) */
#include "dp-bit.h"

/* STA: gcc's fp-bit.c _fpdiv_parts and divide; this libgcc does no
   guard-bit rounding */
static __inline__ fp_number_type_d *_fpdiv_parts(fp_number_type_d *a, fp_number_type_d *b)
{
    unsigned long long bit;
    unsigned long long numerator;
    unsigned long long denominator;
    unsigned long long quotient;

    if (isnan_d(a)) {
        return a;
    }
    if (isnan_d(b)) {
        return b;
    }

    a->sign = a->sign ^ b->sign;

    if (isinf_d(a) || iszero_d(a)) {
        if (a->class == b->class)
            return nan_d();
        return a;
    }

    if (isinf_d(b)) {
        a->fraction.ll = 0;
        a->normal_exp = 0;
        return a;
    }
    if (iszero_d(b)) {
        a->class = CLASS_INFINITY;
        return a;
    }

    a->normal_exp = a->normal_exp - b->normal_exp;
    numerator = a->fraction.ll;
    denominator = b->fraction.ll;

    if (numerator < denominator) {
        /* Fraction will be less than 1.0 */
        numerator *= 2;
        a->normal_exp--;
    }
    bit = 0x1000000000000000ULL;
    quotient = 0;
    while (bit) {
        if (numerator >= denominator) {
            quotient |= bit;
            numerator -= denominator;
        }
        bit >>= 1;
        numerator *= 2;
    }
    a->fraction.ll = quotient;
    return a;
}

long long dpdiv(long arg_a, long arg_b)
{
    fp_number_type_d a;
    fp_number_type_d b;
    fp_number_type_d *res;

    __unpack_d(&arg_a, &a);
    __unpack_d(&arg_b, &b);

    res = _fpdiv_parts(&a, &b);

    return __pack_d(res);
}
