#include "common.h"
void Vector_Add3_3_001DC7F8(void *d, void *a, void *b) {
    asm volatile("lqc2 $vf16, 0(%0)\n\tlqc2 $vf17, 0(%1)\n\tvadd.xyz $vf16, $vf16, $vf17\n\tsqc2 $vf16, 0(%2)" : : "r"(a), "r"(b), "r"(d));
}

