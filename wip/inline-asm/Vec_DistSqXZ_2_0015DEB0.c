#include "common.h"
f32 Vec_DistSqXZ_2_0015DEB0(Vec *a, Vec *b) {
    f32 r[4];
    asm("lqc2 $vf16, 0x0(%0)\n\tlqc2 $vf17, 0x0(%1)\n\tvsub.xyz $vf16, $vf17, $vf16\n\tvmul.xyz $vf17, $vf16, $vf16\n\tvaddx.z $vf17, $vf17, $vf17x\n\tsqc2 $vf17, 0x0(%2)" : : "r"(a), "r"(b), "r"(r));
    return r[2];
}
