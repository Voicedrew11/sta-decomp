/* libgcc.a member _df_to_sf.o (from fp-bit.c, double) */
#include "dp-bit.h"

float dptofp(double arg_a)
{
    fp_number_type_d buf;

    long long m;
    int hi, t;
    __unpack_d(&arg_a, &buf);
    m = buf.fraction.ll;
    hi = (int)(m >> 30);
    t = hi | 1;
    if ((m & 0x3FFFFFFF) == 0)
        t = hi;
    __make_fp(buf.class, buf.sign, buf.normal_exp, t);
}
