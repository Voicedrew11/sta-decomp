/* libgcc.a member _unpack_sf.o (from fp-bit.c, single) */
#include "fp-bit.h"

/* STA: gcc's fp-bit.c unpack_d as this single-precision build has it: no
   denormals, NaNs or infinities */
void __unpack_f(void *in, void *out)
{
    FLO_union_type src;
    fp_number_type *dst = out;
    unsigned int fraction;
    int exp;
    int sign;

    src.value = *(float *)in;
    fraction = src.bits.fraction;
    exp = src.bits.exp;
    sign = src.bits.sign;

    dst->sign = sign;
    if (exp == 0) {
        dst->class = CLASS_ZERO;
    } else {
        dst->normal_exp = exp - 127;
        dst->class = CLASS_NUMBER;
        dst->fraction = (fraction << 7) | IMPLICIT_1;
    }
}
