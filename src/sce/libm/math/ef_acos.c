/* libm.a member ef_acos.o (SAB: not in kfiv-decomp; newlib's ef_acos.c, built
   for the R5900 FPU like the rest of this libm) */
#include <math.h>
#include <math_private.h>

/* Float<->word access, the public-domain fdlibm idiom (netlib's fdlibm,
   math_private.h), defined in this member. */

/* SAB: macros: this game's libm emits no .rodata for these constants (the
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

#define one ((float)1.0000000000e+00)       /* 0x3F800000 */
#define pi ((float)3.1415925026e+00)        /* 0x40490fda */
#define pio2_hi ((float)1.5707962513e+00)   /* 0x3fc90fda */
#define pio2_lo ((float)7.5497894159e-08)   /* 0x33a22168 */
#define pS0 ((float)1.6666667163e-01)       /* 0x3e2aaaab */
#define pS1 ((float)-3.2556581497e-01)      /* 0xbea6b090 */
#define pS2 ((float)2.0121252537e-01)       /* 0x3e4e0aa8 */
#define pS3 ((float)-4.0055535734e-02)      /* 0xbd241146 */
#define pS4 ((float)7.9153501429e-04)       /* 0x3a4f7f04 */
#define pS5 ((float)3.4793309169e-05)       /* 0x3811ef08 */
#define qS1 ((float)-2.4033949375e+00)      /* 0xc019d139 */
#define qS2 ((float)2.0209457874e+00)       /* 0x4001572d */
#define qS3 ((float)-6.8828397989e-01)      /* 0xbf303361 */
#define qS4 ((float)7.7038154006e-02)       /* 0x3d9dc62e */

float __ieee754_sqrtf(float x);

float __ieee754_acosf(float x)
{
    float z, p, q, r, w, s, c, df;
    int hx, ix;

    GET_FLOAT_WORD(hx, x);
    ix = hx & 0x7fffffff;
    if (ix == 0x3f800000) { /* |x|==1 */
        if (hx > 0)
            return 0.0; /* acos(1) = 0  */
        else
            return pi + (float)2.0 * pio2_lo; /* acos(-1)= pi */
    } else if (ix > 0x3f800000) {             /* |x| >= 1 */
        return (x - x) / (x - x);             /* acos(|x|>1) is NaN */
    }
    if (ix < 0x3f000000) { /* |x| < 0.5 */
        if (ix <= 0x23000000)
            return pio2_hi + pio2_lo; /*if|x|<2**-57*/
        z = x * x;
        p = z * (pS0 + z * (pS1 + z * (pS2 + z * (pS3 + z * (pS4 + z * pS5)))));
        q = one + z * (qS1 + z * (qS2 + z * (qS3 + z * qS4)));
        r = p / q;
        return pio2_hi - (x - (pio2_lo - x * r));
    } else if (hx < 0) { /* x < -0.5 */
        z = (one + x) * (float)0.5;
        p = z * (pS0 + z * (pS1 + z * (pS2 + z * (pS3 + z * (pS4 + z * pS5)))));
        q = one + z * (qS1 + z * (qS2 + z * (qS3 + z * qS4)));
        s = __ieee754_sqrtf(z);
        r = p / q;
        w = r * s - pio2_lo;
        return pi - (float)2.0 * (s + w);
    } else { /* x > 0.5 */
        int idf;
        z = (one - x) * (float)0.5;
        s = __ieee754_sqrtf(z);
        df = s;
        GET_FLOAT_WORD(idf, df);
        SET_FLOAT_WORD(df, idf & 0xfffff000);
        c = (z - df * df) / (s + df);
        p = z * (pS0 + z * (pS1 + z * (pS2 + z * (pS3 + z * (pS4 + z * pS5)))));
        q = one + z * (qS1 + z * (qS2 + z * (qS3 + z * qS4)));
        r = p / q;
        w = r * s + c;
        return (float)2.0 * (df + w);
    }
}
