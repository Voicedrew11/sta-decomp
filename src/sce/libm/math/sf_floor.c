/* libm.a member sf_floor.o */
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

/* fdlibm's constant: the member's whole .rodata (0x4).  The code loads it as
 * an immediate, so the word is referenced by nothing. */
/* SAB: a macro: this member has no .rodata */
#define huge ((float)1.0e30)

/* SAB: this newlib is built for the R5900 FPU: no denormals (a word below
   0x00800000 is a zero) and no infinities (every word is finite) */
float floorf(float x)
{
    int i0, j0;
    unsigned int i, ix;

    GET_FLOAT_WORD(i0, x);
    ix = (i0 & 0x7fffffff);
    j0 = (ix >> 23) - 0x7f;
    if (j0 < 23) {
        if (j0 < 0) {                    /* raise inexact if x != 0 */
            if (huge + x > (float)0.0) { /* return 0*sign(x) if |x|<1 */
                if (i0 >= 0) {
                    i0 = 0;
                } else if (!(ix < 0x00800000)) {
                    i0 = 0xbf800000;
                }
            }
        } else {
            i = (0x007fffff) >> j0;
            if ((i0 & i) == 0)
                return x;                /* x is integral */
            if (huge + x > (float)0.0) { /* raise inexact flag */
                if (i0 < 0)
                    i0 += (0x00800000) >> j0;
                i0 &= (~i);
            }
        }
    } else {
        return x; /* x is integral */
    }
    SET_FLOAT_WORD(x, i0);
    return x;
}
