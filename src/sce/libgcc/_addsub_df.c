/* libgcc.a member _addsub_df.o (from fp-bit.c, double) */
#include "dp-bit.h"

fp_number_type_d *_fpadd_parts(fp_number_type_d *a, fp_number_type_d *b, fp_number_type_d *tmp)
{
    long long tfraction;
    int a_normal_exp;
    int b_normal_exp;
    unsigned long long a_fraction;
    unsigned long long b_fraction;
    int diff;

    if (isnan_d(a))
        return a;
    if (isnan_d(b))
        return b;
    if (isinf_d(a)) {
        /* adding infinities with opposite signs yields a NaN */
        if (isinf_d(b) && a->sign != b->sign)
            return nan_d();
        return a;
    }
    if (isinf_d(b))
        return b;
    if (iszero_d(b)) {
        if (iszero_d(a)) {
            *tmp = *a;
            tmp->sign = a->sign & b->sign;
            return tmp;
        }
        return a;
    }
    if (iszero_d(a))
        return b;

    a_normal_exp = a->normal_exp;
    b_normal_exp = b->normal_exp;
    a_fraction = a->fraction.ll;
    b_fraction = b->fraction.ll;

    diff = a_normal_exp - b_normal_exp;
    if (diff < 0)
        diff = -diff;
    if (diff < 64) {
        while (a_normal_exp > b_normal_exp) {
            b_normal_exp++;
            b_fraction = (b_fraction & 1) | (b_fraction >> 1);
        }
        while (b_normal_exp > a_normal_exp) {
            a_normal_exp++;
            a_fraction = (a_fraction & 1) | (a_fraction >> 1);
        }
    } else {
        if (a_normal_exp > b_normal_exp) {
            b_fraction = 0;
            b_normal_exp = a_normal_exp;
        } else {
            a_fraction = 0;
            a_normal_exp = b_normal_exp;
        }
    }

    if (a->sign != b->sign) {
        if (a->sign)
            tfraction = -a_fraction + b_fraction;
        else
            tfraction = a_fraction - b_fraction;

        if (tfraction >= 0) {
            tmp->sign = 0;
            tmp->normal_exp = a_normal_exp;
            tmp->fraction.ll = tfraction;
        } else {
            tmp->sign = 1;
            tmp->normal_exp = a_normal_exp;
            tmp->fraction.ll = -tfraction;
        }
        while (tmp->fraction.ll < 0x1000000000000000ULL && tmp->fraction.ll) {
            tmp->fraction.ll <<= 1;
            tmp->normal_exp--;
        }
    } else {
        tmp->sign = a->sign;
        tmp->normal_exp = a_normal_exp;
        tmp->fraction.ll = a_fraction + b_fraction;
    }
    tmp->class = CLASS_NUMBER;

    if (tmp->fraction.ll >= 0x2000000000000000ULL) {
        tmp->fraction.ll = (tmp->fraction.ll & 1) | (tmp->fraction.ll >> 1);
        tmp->normal_exp++;
    }
    return tmp;
}

void dpadd(long arg_a, long arg_b)
{
    fp_number_type_d x, y, z;

    __unpack_d(&arg_a, &x);
    __unpack_d(&arg_b, &y);
    __pack_d(_fpadd_parts(&x, &y, &z));
}

long long dpsub(long arg_a, long arg_b)
{
    fp_number_type_d x, y, z;

    __unpack_d(&arg_a, &x);
    __unpack_d(&arg_b, &y);
    y.sign ^= 1;
    return __pack_d(_fpadd_parts(&x, &y, &z));
}
