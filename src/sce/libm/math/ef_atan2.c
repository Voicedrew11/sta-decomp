/* libm.a member ef_atan2.o */
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

#define tiny ((float)1.0e-30)

#define zero ((float)0.0)

#define pi_o_4 ((float)7.8539818525e-01)

#define pi_o_2 ((float)1.5707963705e+00)

#define pi ((float)3.1415925026e+00)

#define pi_lo ((float)1.5099578832e-07)

/* SAB: this game's newlib, built for the R5900 FPU: no NaNs or infinities,
   and a word below 0x00800000 is a zero */
float __ieee754_atan2f(float y, float x)
{
    float z;
    int k, m, hx, hy, ix, iy;

    GET_FLOAT_WORD(hx, x);
    ix = hx & 0x7fffffff;
    GET_FLOAT_WORD(hy, y);
    iy = hy & 0x7fffffff;
    if (hx == 0x3f800000) {
        return atanf(y);
    }
    m = ((hy >> 31) & 1) | ((hx >> 30) & 2);

    if (iy < 0x00800000) {
        switch (m) {
        case 0:
        case 1:
            return y;
        case 2:
            return pi + tiny;
        case 3:
            return -pi - tiny;
        }
    }
    if (ix < 0x00800000) {
        return (hy < 0) ? -pi_o_2 - tiny : pi_o_2 + tiny;
    }

    k = (iy - ix) >> 23;
    if (k > 60) {
        z = pi_o_2 + (float)0.5 * pi_lo;
    } else if (hx < 0 && k < -60) {
        z = 0.0f;
    } else {
        z = atanf(fabsf(y / x));
    }
    switch (m) {
    case 0:
        return z;
    case 1: {
        unsigned int zh;
        GET_FLOAT_WORD(zh, z);
        SET_FLOAT_WORD(z, zh ^ 0x80000000);
    }
        return z;
    case 2:
        return pi - (z - pi_lo);
    default:
        return (z - pi_lo) - pi;
    }
}
