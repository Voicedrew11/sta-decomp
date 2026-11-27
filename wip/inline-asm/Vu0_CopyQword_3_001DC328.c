#include "common.h"
void Vu0_CopyQword_3_001DC328(void *v0, void *v1) {
    asm __volatile__("lq $6,0x0(%1)\n\tsq $6,0x0(%0)" : : "r"(v0), "r"(v1) : "$6");
}
