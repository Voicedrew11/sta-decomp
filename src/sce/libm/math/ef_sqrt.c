/* libm.a member ef_sqrt.o */
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

/* STA: macros: this member has no .rodata */
#define one 1.0f
#define tiny 1.0e-30f

/* STA: this game's newlib, built for the R5900 FPU: every word is finite,
   a word below 0x00800000 is a zero, no subnormals */
/* TODO(STA): TEMPORARY inline asm, to be removed: __ieee754_sqrtf is retail's
 * instructions until the C below matches.  The C is kept (under #if 0) for
 * the next attempt; delete the asm and the #if 0 once it compiles to the
 * same bytes.  tools/asm2inline.py generated the block. */
#if 0
float __ieee754_sqrtf(float x)
{
    float z;
    unsigned int r, hx;
    int ix, s, q, m, t;

    GET_FLOAT_WORD(ix, x);
    hx = ix & 0x7fffffff;
    if (hx < 0x00800000)
        return x; /* sqrt(+-0) = +-0 */
    if (ix < 0)
        return (x - x) / (x - x); /* sqrt(-ve) = sNaN */
    m = (ix >> 23);
    m -= 127;                     /* unbias exponent */
    ix = (ix & 0x007fffff) | 0x00800000;
    ix <<= (m & 1); /* odd m, double x to make it even */
    m >>= 1;        /* m = [m/2] */
    ix += ix;
    q = s = 0;      /* q = sqrt(x) */
    r = 0x01000000; /* r = moving bit from right to left */
    while (r != 0) {
        t = s + r;
        if (t <= ix) {
            s = t + r;
            ix -= t;
            q += r;
        }
        ix += ix;
        r >>= 1;
    }
    /* use floating add to find out rounding direction */
    if (ix != 0) {
        z = one - tiny; /* trigger inexact flag */
        if (z >= one) {
            z = one + tiny;
            if (z > one)
                q += 2;
            else
                q += (q & 1);
        }
    }
    ix = (q >> 1) + 0x3f000000;
    ix += (m << 23);
    SET_FLOAT_WORD(z, ix);
    return z;
}
#endif
__asm__(".section .text\n"
        "    .set noat\n"
        "    .set noreorder\n"
        "    .align 3\n"
        "    .globl __ieee754_sqrtf\n"
        "    .type __ieee754_sqrtf, @function\n"
        "__ieee754_sqrtf:\n"
        "    mfc1       $3, $f12\n"
        "    daddu      $5, $3, $0\n"
        "    lui        $2, (0x7FFFFFFF >> 16)\n"
        "    lui        $3, (0x7FFFFF >> 16)\n"
        "    ori        $2, $2, (0x7FFFFFFF & 0xFFFF)\n"
        "    ori        $3, $3, (0x7FFFFF & 0xFFFF)\n"
        "    and        $2, $5, $2\n"
        "    sltu       $2, $3, $2\n"
        "    beqz       $2, .L0011C3E0\n"
        "    mov.s     $f0, $f12\n"
        "    bgez       $5, .L0011C3E8\n"
        "    sra       $7, $5, 23\n"
        "    sub.s      $f0, $f12, $f12\n"
        "    nop\n"
        "    nop\n"
        "    div.s      $f0, $f0, $f0\n"
        ".L0011C3E0:\n"
        "    jr         $31\n"
        "    nop\n"
        ".L0011C3E8:\n"
        "    addiu      $7, $7, -0x7F\n"
        "    lui        $2, (0x800000 >> 16)\n"
        "    and        $3, $5, $3\n"
        "    andi       $4, $7, 0x1\n"
        "    or         $5, $3, $2\n"
        "    daddu      $8, $0, $0\n"
        "    sllv       $5, $5, $4\n"
        "    lui        $4, (0x1000000 >> 16)\n"
        "    sra        $7, $7, 1\n"
        "    sll        $5, $5, 1\n"
        "    daddu      $6, $0, $0\n"
        "    nop\n"
        ".L0011C418:\n"
        "    addu       $3, $8, $4\n"
        "    slt        $2, $5, $3\n"
        "    bnel       $2, $0, .L0011C438\n"
        "    srl       $4, $4, 1\n"
        "    subu       $5, $5, $3\n"
        "    addu       $8, $3, $4\n"
        "    addu       $6, $6, $4\n"
        "    srl        $4, $4, 1\n"
        ".L0011C438:\n"
        "    bnez       $4, .L0011C418\n"
        "    sll       $5, $5, 1\n"
        "    beqz       $5, .L0011C44C\n"
        "    andi      $2, $6, 0x1\n"
        "    addu       $6, $6, $2\n"
        ".L0011C44C:\n"
        "    sra        $2, $6, 1\n"
        "    sll        $3, $7, 23\n"
        "    lui        $5, (0x3F000000 >> 16)\n"
        "    addu       $5, $5, $2\n"
        "    addu       $5, $5, $3\n"
        "    mtc1       $5, $f0\n"
        "    jr         $31\n"
        "    nop\n"
        "    .size __ieee754_sqrtf, . - __ieee754_sqrtf\n"
        "    .set reorder\n"
        "    .set at\n");
