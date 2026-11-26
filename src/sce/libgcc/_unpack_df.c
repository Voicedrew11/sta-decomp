/* libgcc.a member _unpack_df.o (from fp-bit.c, double) */
#include "dp-bit.h"

/* STA: gcc's fp-bit.c unpack_d as this libgcc was built: no denormals, and
   an infinity is also given the largest normal exponent and fraction */
void __unpack_d(void *in, void *out)
{
    FLO_union_type_d src;
    fp_number_type_d *dst = out;
    unsigned long long fraction;
    int exp;
    int sign;

    src.value = *(long long *)in;
    fraction = src.bits.fraction;
    exp = src.bits.exp;
    sign = src.bits.sign;

    dst->sign = sign;
    if (exp == 0) {
        dst->class = CLASS_ZERO;
    } else if (exp == 0x7FF) {
        dst->normal_exp = 1023;
        if (fraction == 0) {
            dst->class = CLASS_INFINITY;
            dst->fraction.ll = 0x1000000000000000ULL;
        } else {
            if (fraction & 0x8000000000000ULL) {
                dst->class = CLASS_QNAN;
            } else {
                dst->class = CLASS_SNAN;
            }
            dst->fraction.ll = fraction;
        }
    } else {
        dst->normal_exp = exp - 1023;
        dst->class = CLASS_NUMBER;
        dst->fraction.ll = (fraction << 8) | 0x1000000000000000ULL;
    }
}
