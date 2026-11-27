#include "common.h"
f32 Vec_DistB_3_0015DF50(Vec *a, Vec *b)
{
    f32 r[4] __attribute__((aligned(16)));
    asm("lqc2 $vf16, 0(%1)\n\tlqc2 $vf17, 0(%2)\n\tvsub.xyz $vf16, $vf17, $vf16\n\tvmul.xyz $vf17, $vf16, $vf16\n\tvaddx.z $vf17, $vf17, $vf17x\n\tvaddy.z $vf17, $vf17, $vf17y\n\tvsqrt Q, $vf17z\n\tvwaitq\n\tvaddq.x $vf16, $vf0, Q\n\tsqc2 $vf16, 0(%0)" : : "r"(r), "r"(a), "r"(b));
    return r[0];
}
