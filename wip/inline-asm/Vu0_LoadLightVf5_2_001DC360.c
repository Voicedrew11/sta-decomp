#include "common.h"
void Vu0_LoadLightVf5_2_001DC360(void *a) {
    asm volatile("lqc2 $vf5, 0x0(%0)\n\tlqc2 $vf6, 0x10(%0)\n\tlqc2 $vf7, 0x20(%0)" : : "r"(a));
}
