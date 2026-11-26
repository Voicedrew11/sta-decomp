/* libm.a member sf_tan.o (SAB: not in kfiv-decomp; newlib's sf_tan.c, built
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

float __kernel_tanf(float x, float y, int iy);
int __ieee754_rem_pio2f(float x, float *y);

float tanf(float x)
{
    float y[2], z = 0.0;
    int n, ix;

    GET_FLOAT_WORD(ix, x);
    /* |x| ~< pi/4 */
    ix &= 0x7fffffff;
    if (ix <= 0x3f490fda)
        return __kernel_tanf(x, z, 1);
    /* argument reduction needed (no Inf or NaN here) */
    else {
        n = __ieee754_rem_pio2f(x, y);
        return __kernel_tanf(y[0], y[1], 1 - ((n & 1) << 1)); /*   1 -- n even
                                                              -1 -- n odd */
    }
}
