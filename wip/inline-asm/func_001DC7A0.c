#include "common.h"
void func_001DC7A0(void *a, void *b, void *c) {
    asm volatile("lqc2 $vf16, 0(%0)" : : "r"(b));
    asm volatile("lqc2 $vf17, 0(%0)" : : "r"(c));
    asm volatile("vmul.xyzw $vf16, $vf16, $vf17");
    asm volatile("sqc2 $vf16, 0(%0)" : : "r"(a));
}
