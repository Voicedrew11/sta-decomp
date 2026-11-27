#include "common.h"
void Vector_FtoI4_3_001DC7B8(void *d, void *s)
{
    asm("lqc2 $vf16, 0(%1)\n\tvftoi4.xyzw $vf16, $vf16\n\tsqc2 $vf16, 0(%0)" : : "r"(d), "r"(s));
}
