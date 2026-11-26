#include "common.h"
void func_001DC770(void *a0, void *a1, void *a2) {
    asm("lqc2 $vf1, 0x0(%0)" : : "r"(a1));
    asm("lqc2 $vf2, 0x10(%0)" : : "r"(a1));
    asm("lqc2 $vf3, 0x20(%0)" : : "r"(a1));
    asm("lqc2 $vf4, 0x30(%0)" : : "r"(a1));
    asm("lqc2 $vf16, 0x0(%0)" : : "r"(a2));
    asm("vmulax.xyzw ACC, $vf1, $vf16x");
    asm("vmadday.xyzw ACC, $vf2, $vf16y");
    asm("vmaddaz.xyzw ACC, $vf3, $vf16z");
    asm("vmaddw.xyzw $vf16, $vf4, $vf16w");
    asm("sqc2 $vf16, 0x0(%0)" : : "r"(a0));
}
