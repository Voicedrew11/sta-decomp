#include "common.h"
f32 Vec_DistXZ_2_0015DEE0(void *a, void *b) {
    f32 r[4];
    asm("lqc2 $vf16, 0x0(%1)\n\tlqc2 $vf17, 0x0(%2)\n\tvsub.xyz $vf16, $vf17, $vf16\n\tvmul.xyz $vf17, $vf16, $vf16\n\tvaddx.z $vf17, $vf17, $vf17x\n\tvsqrt Q, $vf17z\n\tvwaitq\n\tvaddq.x $vf16, $vf0, Q\n\tsqc2 $vf16, 0x0(%0)" : : "r"(r), "r"(a), "r"(b) : "memory");
    return r[0];
}
