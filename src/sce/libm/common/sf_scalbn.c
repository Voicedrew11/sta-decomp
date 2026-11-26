/* libm.a member sf_scalbn.o */
#include <math_private.h>
#include <math.h>

/* Float<->word access, the public-domain fdlibm idiom (netlib's fdlibm,
   math_private.h), defined in this member. */

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

/* SAB: this game's newlib scalbnf, built for the R5900 FPU (no denormals:
   a word below 0x00800000 is a zero; no infinities: every exponent is
   finite).  The constants are immediates, not a table. */
#define huge ((float)1.0e+30)
#define tiny 0x1.4484bep-100f /* 0x0DA2425F */

float scalbnf(float x, int n)
{
    int ix, k;
    unsigned int hx;

    GET_FLOAT_WORD(ix, x);
    hx = ix & 0x7fffffff;
    k = hx >> 23; /* extract exponent */
    if (hx < 0x00800000)
        return x; /* +-0 */
    k = k + n;
    if (k > 0xff)
        return huge * copysignf(huge, x); /* overflow  */
    if (k > 0) {                          /* normal result */
        SET_FLOAT_WORD(x, (ix & 0x807fffff) | (k << 23));
        return x;
    }
    if (n > 50000)                        /* in case integer overflow in n+k */
        return huge * copysignf(huge, x); /*overflow*/
    else
        return tiny * copysignf(tiny, x); /*underflow*/
}
