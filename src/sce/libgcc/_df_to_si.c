/* libgcc.a member _df_to_si.o (from fp-bit.c, double) */
#include "dp-bit.h"

int dptoli(long arg_a)
{
    fp_number_type_d a;
    int tmp;

    __unpack_d(&arg_a, &a);

    if (iszero_d(&a)) {
        return 0;
    }
    if (isnan_d(&a)) {
        return 0;
    }
    if (isinf_d(&a)) {
        return a.sign ? (-0x7FFFFFFF) - 1 : 0x7FFFFFFF;
    }
    if (a.normal_exp < 0) {
        return 0;
    }
    if (a.normal_exp > 30) {
        return a.sign ? (-0x7FFFFFFF) - 1 : 0x7FFFFFFF;
    }
    tmp = a.fraction.ll >> (60 - a.normal_exp);
    return a.sign ? -tmp : tmp;
}
