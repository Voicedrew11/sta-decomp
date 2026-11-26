/* libm.a member kf_tan.o (STA: not in kfiv-decomp; newlib's kf_tan.c, built
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

static const float one = 1.0000000000e+00;    /* 0x3f800000 */
static const float pio4 = 7.8539812565e-01;   /* 0x3f490fda */
static const float pio4lo = 3.7748947079e-08; /* 0x33222168 */
static const float T[] = {
    3.3333334327e-01,  /* 0x3eaaaaab */
    1.3333334029e-01,  /* 0x3e088889 */
    5.3968254477e-02,  /* 0x3d5d0dd1 */
    2.1869488060e-02,  /* 0x3cb327a4 */
    8.8632395491e-03,  /* 0x3c11371f */
    3.5920790397e-03,  /* 0x3b6b6916 */
    1.4562094584e-03,  /* 0x3abede48 */
    5.8804126456e-04,  /* 0x3a1a26c8 */
    2.4646313977e-04,  /* 0x398137b9 */
    7.8179444245e-05,  /* 0x38a3f445 */
    7.1407252108e-05,  /* 0x3895c07a */
    -1.8558637748e-05, /* 0xb79bae5f */
    2.5907305826e-05,  /* 0x37d95384 */
};

float fabsf(float x);

float __kernel_tanf(float x, float y, int iy)
{
    float z, r, v, w, s;
    int ix, hx;

    GET_FLOAT_WORD(hx, x);
    ix = hx & 0x7fffffff;   /* high word of |x| */
    if (ix < 0x31800000) {  /* x < 2**-28 */
        if ((int)x == 0) {  /* generate inexact */
            if ((ix | (iy + 1)) == 0)
                return one / fabsf(x);
            else
                return (iy == 1) ? x : -one / x;
        }
    }
    if (ix >= 0x3f2ca140) { /* |x|>=0.6744 */
        if (hx < 0) {
            x = -x;
            y = -y;
        }
        z = pio4 - x;
        w = pio4lo - y;
        x = z + w;
        y = 0.0;
    }
    z = x * x;
    w = z * z;
    r = T[1] + w * (T[3] + w * (T[5] + w * (T[7] + w * (T[9] + w * T[11]))));
    v = z * (T[2] + w * (T[4] + w * (T[6] + w * (T[8] + w * (T[10] + w * T[12])))));
    s = z * x;
    r = y + z * (s * (r + v) + y);
    r += T[0] * s;
    w = x + r;
    if (ix >= 0x3f2ca140) {
        v = (float)iy;
        return (float)(1 - ((hx >> 30) & 2)) * (v - (float)2.0 * (x - (w * w / (w + v) - r)));
    }
    if (iy == 1)
        return w;
    else {
        float a, t;
        int i;
        z = w;
        GET_FLOAT_WORD(i, z);
        SET_FLOAT_WORD(z, i & 0xfffff000);
        v = r - (z - x);         /* z+v = r+x */
        t = a = -(float)1.0 / w; /* a = -1.0/w */
        GET_FLOAT_WORD(i, t);
        SET_FLOAT_WORD(t, i & 0xfffff000);
        s = (float)1.0 + t * z;
        return t + a * (s + t * v);
    }
}
