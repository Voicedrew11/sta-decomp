/* libm.a member ef_asin.o */
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

#define one ((float)1.0000000000e+00) /* 0x3F800000 */

#define huge ((float)1.0000000150e+30) /* 0x7149F2CA */

#define pio2_hi ((float)1.5707962513e+00) /* 0x3FC90FDA */

#define pio2_lo ((float)7.5497894159e-08) /* 0x33A22168 */

#define pio4_hi ((float)7.8539818525e-01) /* 0x3F490FDB */

/* coefficients for R(x*x) */
#define pS0 ((float)1.6666667163e-01) /* 0x3E2AAAAB */

#define pS1 ((float)-3.2556581497e-01) /* 0xBEA6B090 */

#define pS2 ((float)2.0121252537e-01) /* 0x3E4E0AA8 */

#define pS3 ((float)-4.0055535734e-02) /* 0xBD241146 */

#define pS4 ((float)7.9153501429e-04) /* 0x3A4F7F04 */

#define pS5 ((float)3.4793309169e-05) /* 0x3811EF08 */

#define qS1 ((float)-2.4033949375e+00) /* 0xC019D139 */

#define qS2 ((float)2.0209457874e+00) /* 0x4001572D */

#define qS3 ((float)-6.8828397989e-01) /* 0xBF303361 */

#define qS4 ((float)7.7038154006e-02) /* 0x3D9DC62E */

float __ieee754_asinf(float x)
{
    float t, w, p, q, c, r, s;
    int hx, ix;

    GET_FLOAT_WORD(hx, x);
    ix = hx & 0x7fffffff;
    if (ix == 0x3f800000) {
        /* asin(1) = +-pi/2 with inexact */
        return x * pio2_hi + x * pio2_lo;
    } else if (ix > 0x3f800000) { /* |x| >= 1 */
        return (x - x) / (x - x); /* asin(x) = NaN */
    } else if (ix < 0x3f000000) { /* |x| < 0.5 */
        if (ix < 0x32000000) {    /* if |x| < 2**-27 */
            if (huge + x > one) {
                return x; /* return x with inexact if x != 0 */
            }
        } else { /* STA: this newlib braces the whole computation */
            t = x * x;
            p = t * (pS0 + t * (pS1 + t * (pS2 + t * (pS3 + t * (pS4 + t * pS5)))));
            q = one + t * (qS1 + t * (qS2 + t * (qS3 + t * qS4)));
            w = p / q;
            return x + x * w;
        }
    }
    /* 1 > |x| >= 0.5 */
    w = one - fabsf(x);
    t = w * (float)0.5;
    p = t * (pS0 + t * (pS1 + t * (pS2 + t * (pS3 + t * (pS4 + t * pS5)))));
    q = one + t * (qS1 + t * (qS2 + t * (qS3 + t * qS4)));
    s = __ieee754_sqrtf(t);
    if (ix >= 0x3F79999A) { /* if |x| > 0.975 */
        w = p / q;
        t = pio2_hi - ((float)2.0 * (s + s * w) - pio2_lo);
    } else {
        int iw;
        w = s;
        GET_FLOAT_WORD(iw, w);
        SET_FLOAT_WORD(w, iw & 0xfffff000);
        c = (t - w * w) / (s + w);
        r = p / q;
        p = (float)2.0 * s * r - (pio2_lo - (float)2.0 * c);
        q = pio4_hi - (float)2.0 * w;
        t = pio4_hi - (p - q);
    }
    if (hx > 0) {
        return t;
    } else {
        return -t;
    }
}
