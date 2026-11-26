/* STA: the parts of libgcc's fp-bit.c (built with FLOAT unset: double)
 * that every dp-bit member shares.  libgcc builds each routine as its own
 * archive member, and the game links only the ones it calls. */
#ifndef DP_BIT_H
#define DP_BIT_H
#include "libgcc2.h"

#define CLASS_SNAN 0
#define CLASS_QNAN 1
#define CLASS_ZERO 2
#define CLASS_NUMBER 3
#define CLASS_INFINITY 4
/* libgcc's fp-bit.c reads a zero exponent as zero when NO_DENORMALS is
   defined (`if (fraction == 0 || 1)` under #ifdef NO_DENORMALS in the public
   GCC source), and this build defined it: the EE FPU has no denormals.
   Where the developers' build defined the macro (a target makefile fragment)
   is not known; the define is here. */
#define NO_DENORMALS

/* The double number in unpacked form.  FRAC_NBITS is 64 and NGARDS is 8, so the
   implicit one sits at bit 60 and the fraction is a 64-bit field at 0x10. */
typedef struct {
    unsigned int class;
    int sign;
    int normal_exp;
    int pad;

    /* libgcc's fp_number_type keeps the fraction in a union of the 64-bit
       value and its two 32-bit halves (public GCC fp-bit.c). */
    union {
        unsigned long long ll;
        unsigned int l[2];
    } fraction;
} fp_number_type_d;

static __inline__ int isnan_d(fp_number_type_d *x)
{
    return x->class == CLASS_SNAN || x->class == CLASS_QNAN;
}

static __inline__ int isinf_d(fp_number_type_d *x)
{
    return x->class == CLASS_INFINITY;
}

static __inline__ int iszero_d(fp_number_type_d *x)
{
    return x->class == CLASS_ZERO;
}

/* fp-bit.c's nan(): the NaN this build hands back for inf - inf, libgcc's
   __thenan_df (its own member, _thenan_df.o) */
extern const fp_number_type_d __thenan_df;

static __inline__ fp_number_type_d *nan_d(void)
{
    return (fp_number_type_d *)&__thenan_df;
}

typedef union {
    struct {
        unsigned long long fraction : 52;
        unsigned int exp : 11;
        unsigned int sign : 1;
    } bits;

    long long value;
} FLO_union_type_d;


long long __pack_d(void *s);
void __unpack_d(void *in, void *out);
fp_number_type_d *_fpadd_parts(fp_number_type_d *a, fp_number_type_d *b, fp_number_type_d *tmp);
int __fpcmp_parts_d(fp_number_type_d *a, fp_number_type_d *b);

#endif
