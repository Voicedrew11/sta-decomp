#include "common.h"
void func_001DC370(void *m) {
    asm volatile("lqc2 $vf8, 0x0(%0)\n\tlqc2 $vf9, 0x10(%0)\n\tlqc2 $vf10, 0x20(%0)\n\tlqc2 $vf11, 0x30(%0)" : : "r"(m));
}
