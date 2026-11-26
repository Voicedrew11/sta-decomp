#include "common.h"
void func_001DC7D8(void *dst, void *src) {
    __asm__ __volatile__("lqc2 $vf16, 0(%1)\n\tvitof4.xyzw $vf16, $vf16\n\tsqc2 $vf16, 0(%0)" : : "r"(dst), "r"(src));
}
