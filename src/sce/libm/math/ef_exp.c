/* libm.a member ef_exp.o (STA: not in kfiv-decomp; newlib's ef_exp.c, built
   for the R5900 FPU like the rest of this libm) */
#include <math.h>
#include <math_private.h>

/* Float<->word access, the public-domain fdlibm idiom (netlib's fdlibm,
   math_private.h), defined in this member. */

/* STA: macros: this game's libm emits no .rodata for these constants (the
   code loads them as immediates) */
#define GET_FLOAT_WORD(i, d)                                                                       \
    do {                                                                                           \
        ieee_float_shape_type gf_u;                                                                \
        gf_u.value = (d);                                                                          \
        (i) = gf_u.word;                                                                           \
    } while (0)
#define SET_FLOAT_WORD(d, i)                                                                       \
    do {                                                                                           \
        ieee_float_shape_type sf_u;                                                                \
        sf_u.word = (i);                                                                           \
        (d) = sf_u.value;                                                                          \
    } while (0)

/* the member's .rodata, in declaration order (newlib's `one` is not in it) */
#define one ((float)1.0)
static const float halF[2] = {0.5, -0.5};
static const float huge = 1.0e+30;
static const float twom100 = 7.8886090522e-31; /* 2**-100=0x0d800000 */
static const float ln2HI[2] = {6.9313812256e-01, /* 0x3f317180 */
                               -6.9313812256e-01}; /* 0xbf317180 */
static const float ln2LO[2] = {9.0580006145e-06, /* 0x3717f7d1 */
                               -9.0580006145e-06}; /* 0xb717f7d1 */
static const float invln2 = 1.4426950216e+00;  /* 0x3fb8aa3b */
static const float P1 = 1.6666667163e-01;      /* 0x3e2aaaab */
static const float P2 = -2.7777778450e-03;     /* 0xbb360b61 */
static const float P3 = 6.6137559770e-05;      /* 0x388ab355 */
static const float P4 = -1.6533901999e-06;     /* 0xb5ddea0e */
static const float P5 = 4.1381369442e-08;      /* 0x3331bb4c */

float __ieee754_expf(float x)
{
    float y, hi, lo, c, t;
    int k, xsb, sx;
    unsigned int hx;

    GET_FLOAT_WORD(sx, x);
    xsb = (sx >> 31) & 1;  /* sign bit of x */
    hx = sx & 0x7fffffff; /* high word of |x| */

    /* filter out non-finite argument (none here: every word is finite) */
    if (sx > 0x42b2d4fc)
        return huge * huge; /* overflow */
    if (sx < 0 && hx > 0x42aeac50)
        return twom100 * twom100; /* underflow */

    /* argument reduction */
    if (hx > 0x3eb17218) {     /* if  |x| > 0.5 ln2 */
        if (hx < 0x3F851592) { /* and |x| < 1.5 ln2 */
            hi = x - ln2HI[xsb];
            lo = ln2LO[xsb];
            k = 1 - xsb - xsb;
        } else {
            k = invln2 * x + halF[xsb];
            t = k;
            hi = x - t * ln2HI[0]; /* t*ln2HI is exact here */
            lo = t * ln2LO[0];
        }
        x = hi - lo;
    } else if (hx < 0x31800000) { /* when |x|<2**-28 */
        if (huge + x > one)
            return one + x; /* trigger inexact */
    } else
        k = 0;

    /* x is now in primary range */
    t = x * x;
    c = x - t * (P1 + t * (P2 + t * (P3 + t * (P4 + t * P5))));
    if (k == 0)
        return one - ((x * c) / (c - (float)2.0) - x);
    else
        y = one - ((lo - (x * c) / ((float)2.0 - c)) - hi);
    if (k >= -125) {
        unsigned int hy;
        GET_FLOAT_WORD(hy, y);
        SET_FLOAT_WORD(y, hy + (k << 23)); /* add k to y's exponent */
        return y;
    } else {
        unsigned int hy;
        GET_FLOAT_WORD(hy, y);
        SET_FLOAT_WORD(y, hy + ((k + 100) << 23)); /* add k to y's exponent */
        return y * twom100;
    }
}
