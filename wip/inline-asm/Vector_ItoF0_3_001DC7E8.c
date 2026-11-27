#include "common.h"
void Vector_ItoF0_3_001DC7E8(Vec *d, Vec *s)
{
    __asm__ __volatile__("lqc2 $vf16, 0x0(%1)\n\tvitof0.xyzw $vf16, $vf16\n\tsqc2 $vf16, 0x0(%0)" : : "r"(d), "r"(s));
}
