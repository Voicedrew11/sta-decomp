/* libm.a member sf_atan.o */
#include <math.h>
#include <math_private.h>

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

/* STA: the tables as hex literals: this compiler rounds some of fdlibm's
   decimal constants a unit away from the retail words */
static const float atanhi[] = {
    0x1.dac6700000000p-2f, /* 0x3EED6338 */
    0x1.921fb40000000p-1f, /* 0x3F490FDA */
    0x1.f730ba0000000p-1f, /* 0x3F7B985D */
    0x1.921fb40000000p+0f, /* 0x3FC90FDA */
};

static const float atanlo[] = {
    0x1.586ed20000000p-28f, /* 0x31AC3769 */
    0x1.4442ce0000000p-25f, /* 0x33222167 */
    0x1.281f680000000p-25f, /* 0x33140FB4 */
    0x1.4442d00000000p-24f, /* 0x33A22168 */
};

static const float aT[] = {
    0x1.5555560000000p-2f, /* 0x3EAAAAAB */
    -0x1.9999980000000p-3f, /* 0xBE4CCCCC */
    0x1.2492480000000p-3f, /* 0x3E124924 */
    -0x1.c71c700000000p-4f, /* 0xBDE38E38 */
    0x1.745cdc0000000p-4f, /* 0x3DBA2E6E */
    -0x1.3b0f2a0000000p-4f, /* 0xBD9D8795 */
    0x1.10d6680000000p-4f, /* 0x3D886B34 */
    -0x1.dde2d40000000p-5f, /* 0xBD6EF16A */
    0x1.97b4b20000000p-5f, /* 0x3D4BDA59 */
    -0x1.2b44420000000p-5f, /* 0xBD15A221 */
    0x1.0ad3ae0000000p-6f, /* 0x3C8569D7 */
};

static const float one = 1.0, huge = 1.0e30;

float atanf(float x)
{
    float w, s1, s2, z;
    int ix, hx, id;

    GET_FLOAT_WORD(hx, x);
    ix = hx & 0x7fffffff;
    if (ix >= 0x50800000) { /* STA: no NaN case: this newlib's floats have none */
        if (hx > 0) {
            return atanhi[3] + atanlo[3];
        } else {
            return -atanhi[3] - atanlo[3];
        }
    }
    if (ix < 0x3ee00000) {
        if (ix < 0x31000000) {
            if (huge + x > one) {
                return x;
            }
        }
        id = -1;
    } else {
        x = fabsf(x);
        if (ix < 0x3f980000) {
            if (ix < 0x3f300000) {
                id = 0;
                x = ((float)2.0 * x - one) / ((float)2.0 + x);
            } else {
                id = 1;
                x = (x - one) / (x + one);
            }
        } else {
            if (ix < 0x401c0000) {
                id = 2;
                x = (x - (float)1.5) / (one + (float)1.5 * x);
            } else {
                id = 3;
                x = -(float)1.0 / x;
            }
        }
    }
    z = x * x;
    w = z * z;
    s1 = z * (aT[0] + w * (aT[2] + w * (aT[4] + w * (aT[6] + w * (aT[8] + w * aT[10])))));
    s2 = w * (aT[1] + w * (aT[3] + w * (aT[5] + w * (aT[7] + w * aT[9]))));
    if (id < 0) {
        return x - x * (s1 + s2);
    }
    z = atanhi[id] - ((x * (s1 + s2) - atanlo[id]) - x);
    return (hx < 0) ? -z : z;
}
