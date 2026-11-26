/* libgcc.a member _sf_to_df.o (from fp-bit.c, single) */
#include "fp-bit.h"

int fptodp(float arg_a)
{
    fp_number_type in;
    float local1[4];
    long long a3_val;
    local1[0] = arg_a;
    __unpack_f(local1, &in);
    a3_val = (long long)in.fraction << 32;
    return __make_dp(in.class, in.sign, in.normal_exp,
                     (long long)((unsigned long long)a3_val >> 2));
}
