#include "common.h"
f32 func_0015DF20(Vec *a, Vec *b)
{
    Vec t;
    asm("lqc2 $vf16, 0x0(%1)\n\tlqc2 $vf17, 0x0(%2)\n\tvsub.xyz $vf16, $vf17, $vf16\n\tvmul.xyz $vf17, $vf16, $vf16\n\tvaddx.z $vf17, $vf17, $vf17x\n\tvaddy.z $vf17, $vf17, $vf17y\n\tsqc2 $vf17, 0x0(%0)" : : "r"(&t), "r"(a), "r"(b) : "memory");
    return t.z;
}
