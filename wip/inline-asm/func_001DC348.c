#include "common.h"
void func_001DC348(void *m) {
    asm volatile("lqc2 $vf1, 0x0(%0)" :: "r"(m));
    asm volatile("lqc2 $vf2, 0x10(%0)" :: "r"(m));
    asm volatile("lqc2 $vf3, 0x20(%0)" :: "r"(m));
    asm volatile("lqc2 $vf4, 0x30(%0)" :: "r"(m));
}

