/* libgcc.a member _make_df.o (from fp-bit.c, double) */
#include "dp-bit.h"

int __make_dp(int class, int sign, int exp, long long frac)
{
    fp_number_type_d s;

    s.class = class;
    s.sign = sign;
    s.normal_exp = exp;
    s.fraction.ll = frac;
    __pack_d(&s);
}
