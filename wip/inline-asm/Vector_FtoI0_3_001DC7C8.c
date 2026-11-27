#include "common.h"
void Vector_FtoI0_3_001DC7C8(void *a0, void *a1) {
    asm("lqc2 $vf16, 0(%0)" : : "r"(a1));
    asm("vftoi0.xyzw $vf16, $vf16");
    asm("sqc2 $vf16, 0(%0)" : : "r"(a0));
}
