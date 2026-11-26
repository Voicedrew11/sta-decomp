#include "common.h"
void func_001DC840(void *d, void *a, void *b) {
    asm volatile("lqc2 $vf16, 0(%0)" :: "r"(a));
    asm volatile("lqc2 $vf17, 0(%0)" :: "r"(b));
    asm volatile("vsub.xyzw $vf16, $vf16, $vf17");
    asm volatile("sqc2 $vf16, 0(%0)" :: "r"(d));
}

