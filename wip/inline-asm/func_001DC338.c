#include "common.h"
void func_001DC338(void *a, void *b) {
    asm volatile("lq $6, 0(%0)" :: "r"(b) : "$6");
    asm volatile("sq $6, 0(%0)" :: "r"(a));
}

