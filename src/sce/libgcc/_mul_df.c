/* libgcc.a member _mul_df.o (from fp-bit.c, double) */
#include "dp-bit.h"

static __inline__ fp_number_type_d *_fpmul_parts(fp_number_type_d *a, fp_number_type_d *b,
                                                 fp_number_type_d *tmp)
{
    unsigned long long low;
    unsigned long long high;
    unsigned long long nl;
    unsigned long long nh;
    unsigned long long ml;
    unsigned long long mh;
    unsigned long long pp_ll;
    unsigned long long pp_hl;
    unsigned long long pp_lh;
    unsigned long long pp_hh;
    unsigned long long ps;
    unsigned long long res0;
    unsigned long long res2;

    if (isnan_d(a)) {
        a->sign = a->sign != b->sign;
        return a;
    }
    if (isnan_d(b)) {
        b->sign = a->sign != b->sign;
        return b;
    }
    if (isinf_d(a)) {
        if (iszero_d(b)) {
            return nan_d();
        }
        a->sign = a->sign != b->sign;
        return a;
    }
    if (isinf_d(b)) {
        if (iszero_d(a)) {
            return nan_d();
        }
        b->sign = a->sign != b->sign;
        return b;
    }
    if (iszero_d(a)) {
        a->sign = a->sign != b->sign;
        return a;
    }
    if (iszero_d(b)) {
        b->sign = a->sign != b->sign;
        return b;
    }

    nl = a->fraction.ll & 0xFFFFFFFF;
    nh = a->fraction.ll >> 32;
    ml = b->fraction.ll & 0xFFFFFFFF;
    mh = b->fraction.ll >> 32;

    pp_ll = ml * nl;
    pp_hl = mh * nl;
    pp_lh = ml * nh;
    pp_hh = mh * nh;

    res2 = 0;
    ps = pp_hl + pp_lh;
    if (ps < pp_hl) {
        res2 += 1ULL << 32;
    }
    pp_hl = (ps << 32) & 0xFFFFFFFF00000000ULL;
    res0 = pp_ll + pp_hl;
    if (res0 < pp_ll) {
        res2++;
    }
    res2 += ((ps >> 32) & 0xFFFFFFFF) + pp_hh;
    high = res2;
    low = res0;

    tmp->normal_exp = a->normal_exp + b->normal_exp;
    tmp->sign = a->sign != b->sign;
    tmp->normal_exp += 4;

    while (high >= 0x2000000000000000ULL) {
        tmp->normal_exp++;
        if (high & 1) {
            low >>= 1;
            low |= 0x8000000000000000ULL;
        }
        high >>= 1;
    }
    while (high < 0x1000000000000000ULL) {
        high <<= 1;
        if (low & 0x8000000000000000ULL) {
            high |= 1;
        }
        tmp->normal_exp--;
        low <<= 1;
    }
    /* STA: this libgcc does no guard-bit rounding */
    tmp->fraction.ll = high;
    tmp->class = CLASS_NUMBER;
    return tmp;
}

long long dpmul(long arg_a, long arg_b)
{
    fp_number_type_d x, y, z;

    __unpack_d(&arg_a, &x);
    __unpack_d(&arg_b, &y);
    return __pack_d(_fpmul_parts(&x, &y, &z));
}
