#include "common.h"
void func_001DC810(void *d, void *a, void *b) {
    asm volatile("lqc2 $vf16, 0(%1)\n\tlqc2 $vf17, 0(%2)\n\tvadd.xyzw $vf16, $vf16, $vf17\n\tsqc2 $vf16, 0(%0)" : : "r"(d), "r"(a), "r"(b) : "memory");
}
