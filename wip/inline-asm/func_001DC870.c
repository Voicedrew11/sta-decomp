#include "common.h"
void func_001DC870(Vec *d, Vec *s, f32 f) {
    asm __volatile__(
        "mfc1 $2, %2\n"
        "lqc2 $vf16, 0x0(%1)\n"
        "qmtc2.ni $2, $vf31\n"
        "vmulx.xyzw $vf16, $vf16, $vf31x\n"
        "sqc2 $vf16, 0x0(%0)\n"
        : : "r"(d), "r"(s), "f"(f) : "$2");
}
