/* libgcc.a member _make_sf.o (from fp-bit.c, single) */
#include "fp-bit.h"

void __make_fp(int class, int sign, int exp, int frac)
{
    fp_number_type buf;
    buf.class = class;
    buf.sign = sign;
    buf.normal_exp = exp;
    buf.fraction = frac;
    __pack_f(&buf);
}
