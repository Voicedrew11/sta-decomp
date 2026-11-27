#include "common.h"
void Vector_Cross_5_001DC888(void *d, void *a, void *b) {
    asm("lqc2 $vf16, 0(%0)" : : "r"(a));
    asm("lqc2 $vf17, 0(%0)" : : "r"(b));
    asm("vopmula.xyz ACC, $vf16, $vf17");
    asm("vopmsub.xyz $vf16, $vf17, $vf16");
    asm("sqc2 $vf16, 0(%0)" : : "r"(d));
}

