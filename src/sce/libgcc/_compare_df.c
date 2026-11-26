/* libgcc.a member _compare_df.o (from fp-bit.c, double) */
#include "dp-bit.h"

int dpcmp(long arg_a, long arg_b)
{
    fp_number_type_d x, y;

    __unpack_d(&arg_a, &x);
    __unpack_d(&arg_b, &y);
    return __fpcmp_parts_d(&x, &y);
}
