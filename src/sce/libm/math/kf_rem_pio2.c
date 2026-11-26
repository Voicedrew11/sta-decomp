/* libm.a member kf_rem_pio2.o */
#include <math.h>
#include <math_private.h>

/* The member's own static tables, fdlibm's init_jk (three ints), PIo2 (eleven
   floats) and its four scalar constants, in declaration order: the member's
   whole .rodata (0x4c). */
static const int init_jk[] = {
    4,
    7,
    9,
};

/* SAB: hex literals: this compiler rounds some of the decimal ones a unit
   away from the retail words */
static const float PIo2[] = {
    0x1.9200000000000p+0f, /* 0x3FC90000 */
    0x1.e000000000000p-12f, /* 0x39F00000 */
    0x1.b3fffe0000000p-16f, /* 0x37D9FFFF */
    0x1.4400000000000p-24f, /* 0x33A20000 */
    0x1.07fffe0000000p-34f, /* 0x2E83FFFF */
    0x1.9ffffe0000000p-41f, /* 0x2B4FFFFF */
    0x1.83fffe0000000p-48f, /* 0x27C1FFFF */
    0x1.9ffffe0000000p-58f, /* 0x22CFFFFF */
    0x1.8800000000000p-64f, /* 0x1FC40000 */
    0x1.8bfffe0000000p-72f, /* 0x1BC5FFFF */
    0x1.8800000000000p-81f, /* 0x17440000 */
};

static const float zero = 0.0, one = 1.0, two8 = 2.5600000000e+02, /* 0x43800000 */
    twon8 = 3.9062500000e-03;                                      /* 0x3b800000 */

int __kernel_rem_pio2f(float *x, float *y, int e0, int nx, int prec, const int *ipio2)
{
    int jz, jx, jv, jp, jk, carry, n, iq[20], i, j, k, m, q0, ih;
    float z, fw, f[20], fq[20], q[20];

    /* initialize jk*/
    jk = init_jk[prec];
    jp = jk;

    /* determine jx,jv,q0, note that 3>q0 */
    jx = nx - 1;
    jv = (e0 - 3) / 8;
    if (jv < 0)
        jv = 0;
    q0 = e0 - 8 * (jv + 1);

    /* set up f[0] to f[jx+jk] where f[jx+jk] = ipio2[jv+jk] */
    j = jv - jx;
    m = jx + jk;
    for (i = 0; i <= m; i++, j++)
        f[i] = (j < 0) ? zero : (float)ipio2[j];

    /* compute q[0],q[1],...q[jk] */
    for (i = 0; i <= jk; i++) {
        for (j = 0, fw = 0.0f; j <= jx; j++)
            fw += x[j] * f[jx + i - j];
        q[i] = fw;
    }

    jz = jk;
recompute:
    /* distill q[] into iq[] reversingly */
    for (i = 0, j = jz, z = q[jz]; j > 0; i++, j--) {
        fw = (float)((int)(twon8 * z));
        iq[i] = (int)(z - two8 * fw);
        z = q[j - 1] + fw;
    }

    /* compute n */
    z = scalbnf(z, q0);             /* actual value of z */
    z -= 8.0f * floorf(z * 0.125f); /* trim off integer >= 8 */
    n = (int)z;
    z -= (float)n;
    ih = 0;
    if (q0 > 0) { /* need iq[jz-1] to determine n */
        i = (iq[jz - 1] >> (8 - q0));
        n += i;
        iq[jz - 1] -= i << (8 - q0);
        ih = iq[jz - 1] >> (7 - q0);
    } else if (q0 == 0)
        ih = iq[jz - 1] >> 8;
    else if (z >= 0.5f)
        ih = 2;

    if (ih > 0) { /* q > 0.5 */
        n += 1;
        carry = 0;
        for (i = 0; i < jz; i++) { /* compute 1-q */
            j = iq[i];
            if (carry == 0) {
                if (j != 0) {
                    carry = 1;
                    iq[i] = 0x100 - j;
                }
            } else
                iq[i] = 0xff - j;
        }
        if (q0 > 0) { /* rare case: chance is 1 in 12 */
            switch (q0) {
            case 1:
                iq[jz - 1] &= 0x7f;
                break;
            case 2:
                iq[jz - 1] &= 0x3f;
                break;
            }
        }
        if (ih == 2) {
            z = one - z;
            if (carry != 0)
                z -= scalbnf(one, q0);
        }
    }

    /* check if recomputation is needed */
    if (z == zero) {
        j = 0;
        for (i = jz - 1; i >= jk; i--)
            j |= iq[i];
        if (j == 0) { /* need recomputation */
            for (k = 1; iq[jk - k] == 0; k++)
                ; /* k = no. of terms needed */

            for (i = jz + 1; i <= jz + k; i++) { /* add q[jz+1] to q[jz+k] */
                f[jx + i] = (float)ipio2[jv + i];
                for (j = 0, fw = 0.0f; j <= jx; j++)
                    fw += x[j] * f[jx + i - j];
                q[i] = fw;
            }
            jz += k;
            goto recompute;
        }
    }

    /* chop off zero terms */
    if (z == zero) {
        jz -= 1;
        q0 -= 8;
        while (iq[jz] == 0) {
            jz--;
            q0 -= 8;
        }
    } else { /* break z into 8-bit if necessary */
        z = scalbnf(z, -q0);
        if (z >= two8) {
            fw = (float)((int)(twon8 * z));
            iq[jz] = (int)(z - two8 * fw);
            jz += 1;
            q0 += 8;
            iq[jz] = (int)fw;
        } else
            iq[jz] = (int)z;
    }

    /* convert integer "bit" chunk to floating-point value */
    fw = scalbnf(one, q0);
    for (i = jz; i >= 0; i--) {
        q[i] = fw * (float)iq[i];
        fw *= twon8;
    }

    /* compute PIo2[0,...,jp]*q[jz,...,0] */
    for (i = jz; i >= 0; i--) {
        for (fw = 0.0f, k = 0; k <= jp && k <= jz - i; k++)
            fw += PIo2[k] * q[i + k];
        fq[jz - i] = fw;
    }

    /* compress fq[] into y[] */
    switch (prec) {
    case 0:
        fw = 0.0f;
        for (i = jz; i >= 0; i--)
            fw += fq[i];
        y[0] = (ih == 0) ? fw : -fw;
        break;
    case 1:
    case 2:
        fw = 0.0f;
        for (i = jz; i >= 0; i--)
            fw += fq[i];
        y[0] = (ih == 0) ? fw : -fw;
        fw = fq[0] - fw;
        for (i = 1; i <= jz; i++)
            fw += fq[i];
        y[1] = (ih == 0) ? fw : -fw;
        break;
    case 3: /* painful */
        for (i = jz; i > 0; i--) {
            fw = fq[i - 1] + fq[i];
            fq[i] += fq[i - 1] - fw;
            fq[i - 1] = fw;
        }
        for (i = jz; i > 1; i--) {
            fw = fq[i - 1] + fq[i];
            fq[i] += fq[i - 1] - fw;
            fq[i - 1] = fw;
        }
        for (fw = 0.0f, i = jz; i >= 2; i--)
            fw += fq[i];
        if (ih == 0) {
            y[0] = fq[0];
            y[1] = fq[1];
            y[2] = fw;
        } else {
            y[0] = -fq[0];
            y[1] = -fq[1];
            y[2] = -fw;
        }
    }
    return n & 7;
}
