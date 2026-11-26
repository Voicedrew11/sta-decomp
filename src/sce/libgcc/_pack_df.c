/* libgcc.a member _pack_df.o (from fp-bit.c, double) */
#include "dp-bit.h"

/* STA: gcc's fp-bit.c pack_d as this libgcc was built: no denormals and no
   guard-bit rounding */
long long __pack_d(void *s)
{
    fp_number_type_d *src = s;
    FLO_union_type_d dst;
    unsigned long long fraction = src->fraction.ll;
    int sign = src->sign;
    int exp = 0;

    if (isnan_d(src)) {
        exp = 0x7FF;
        fraction |= 0x8000000000000LL;
    } else if (isinf_d(src)) {
        exp = 0x7FF;
        fraction = 0;
    } else if (iszero_d(src)) {
        exp = 0;
        fraction = 0;
    } else if (fraction == 0) {
        exp = 0;
    } else {
        if (src->normal_exp < -1022) {
            exp = 0;
            fraction = 0;
        } else if (src->normal_exp > 1023) {
            exp = 0x7FF;
            fraction = 0;
        } else {
            exp = src->normal_exp + 1023;
            fraction >>= 8;
        }
    }
    dst.bits.fraction = fraction;
    dst.bits.exp = exp;
    dst.bits.sign = sign;
    return dst.value;
}
