/* libgcc.a member _pack_sf.o (from fp-bit.c, single) */
#include "fp-bit.h"

/* STA: gcc's fp-bit.c pack_d as this single-precision build has it: no
   NaNs, infinities or denormals, no guard-bit rounding, and the largest
   exponent a number */
float __pack_f(void *s)
{
    fp_number_type *src = s;
    FLO_union_type dst;
    unsigned int fraction = src->fraction;
    int sign = src->sign;
    int exp = 0;

    if (iszero(src)) {
        exp = 0;
        fraction = 0;
    } else if (fraction == 0) {
        exp = 0;
    } else {
        if (src->normal_exp < -126) {
            exp = 0;
            fraction = 0;
        } else if (src->normal_exp > 128 || (src->normal_exp == 128 && fraction >= IMPLICIT_2)) {
            exp = 0xFF;
            fraction = 0;
        } else {
            exp = src->normal_exp + 127;
            fraction >>= 7;
        }
    }
    dst.bits.fraction = fraction;
    dst.bits.exp = exp;
    dst.bits.sign = sign;
    return dst.value;
}
