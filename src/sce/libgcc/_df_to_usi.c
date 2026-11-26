/* libgcc.a member _df_to_usi.o (from fp-bit.c, double) */
#include "dp-bit.h"

unsigned int dptoul(long arg_a)
{
    fp_number_type_d a;

    __unpack_d(&arg_a, &a);

    if (iszero_d(&a)) {
        return 0;
    }
    if (isnan_d(&a)) {
        return 0;
    }
    if (a.sign) {
        return 0;
    }
    if (isinf_d(&a)) {
        return 0xFFFFFFFF;
    }
    if (a.normal_exp < 0) {
        return 0;
    }
    if (a.normal_exp > 31) {
        return 0xFFFFFFFF;
    }
    if (a.normal_exp > 60) {
        return a.fraction.ll << (a.normal_exp - 60);
    }
    return a.fraction.ll >> (60 - a.normal_exp);
}
