/* libgcc.a member _fpcmp_parts_df.o (from fp-bit.c, double) */
#include "dp-bit.h"

/* STA: gcc's fp-bit.c __fpcmp_parts */
int __fpcmp_parts_d(fp_number_type_d *a, fp_number_type_d *b)
{
    /* Handle NaNs */
    if (isnan_d(a) || isnan_d(b))
        return 1; /* false, truth == 0 */
    if (isinf_d(a) && isinf_d(b)) {
        /* +inf > -inf, but +inf != +inf */
        return b->sign - a->sign;
    }
    /* but not both...  */
    if (isinf_d(a))
        return a->sign ? -1 : 1;
    if (isinf_d(b))
        return b->sign ? 1 : -1;
    if (iszero_d(a) && iszero_d(b))
        return 0;
    if (iszero_d(a))
        return b->sign ? 1 : -1;
    if (iszero_d(b))
        return a->sign ? -1 : 1;
    /* now both are "normal".  */
    if (a->sign != b->sign) {
        /* opposite signs */
        return a->sign ? -1 : 1;
    }
    /* same sign; exponents? */
    if (a->normal_exp > b->normal_exp)
        return a->sign ? -1 : 1;
    if (a->normal_exp < b->normal_exp)
        return a->sign ? 1 : -1;
    /* same exponents; check size. */
    if (a->fraction.ll > b->fraction.ll)
        return a->sign ? -1 : 1;
    if (a->fraction.ll < b->fraction.ll)
        return a->sign ? 1 : -1;
    /* after all that, they're equal. */
    return 0;
}
