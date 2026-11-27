#include "common.h"
void Vector_ApplyMatrix_3_001DC8A0(void *dst, void *a, void *b, void *c, void *d, void *v) {
    __asm__ __volatile__("lqc2 $vf16, 0(%5)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tlqc2 $vf3, 0(%3)\n\tlqc2 $vf4, 0(%4)\n\tvmulax.xyz ACC, $vf1, $vf16x\n\tvmadday.xyz ACC, $vf2, $vf16y\n\tvmaddaz.xyz ACC, $vf3, $vf16z\n\tvmaddw.xyz $vf16, $vf4, $vf16w\n\tsqc2 $vf16, 0(%0)" : : "r"(dst), "r"(a), "r"(b), "r"(c), "r"(d), "r"(v));
}
