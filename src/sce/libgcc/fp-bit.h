/* STA: the parts of libgcc's fp-bit.c (FLOAT: single) the fp-bit members
 * share.  This libgcc's single-precision build has no NaNs or infinities:
 * the largest exponent is a number. */
#ifndef FP_BIT_H
#define FP_BIT_H
#include "libgcc2.h"

#define CLASS_SNAN 0
#define CLASS_QNAN 1
#define CLASS_ZERO 2
#define CLASS_NUMBER 3
#define CLASS_INFINITY 4
#define IMPLICIT_1 0x40000000
#define IMPLICIT_2 0x80000000

typedef struct {
    unsigned int class;
    int sign;
    int normal_exp;
    unsigned int fraction;
} fp_number_type;

/* The single-float number in unpacked form.  FRAC_NBITS is 32, NGARDS is 7,
   so the implicit one sits at bit 30 and the overflow bit at bit 31. */

static __inline__ int isnan(fp_number_type *x)
{
    return x->class == CLASS_SNAN || x->class == CLASS_QNAN;
}

static __inline__ int isinf(fp_number_type *x)
{
    return x->class == CLASS_INFINITY;
}

static __inline__ int iszero(fp_number_type *x)
{
    return x->class == CLASS_ZERO;
}

typedef union {
    struct {
        unsigned int fraction : 23;
        unsigned int exp : 8;
        unsigned int sign : 1;
    } bits;

    float value;
} FLO_union_type;


float __pack_f(void *s);
void __unpack_f(void *in, void *out);
int __make_dp(int class, int sign, int exp, long long frac);

#endif
