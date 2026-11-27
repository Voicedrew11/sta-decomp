#include "common.h"
void Vector_Sub3_3_001DC828(void *v0, void *v1, void *v2) {
    asm __volatile__("lqc2 $vf16,0x0(%1)\n\tlqc2 $vf17,0x0(%2)\n\tvsub.xyz $vf16,$vf16,$vf17\n\tsqc2 $vf16,0x0(%0)" : : "r"(v0), "r"(v1), "r"(v2));
}
