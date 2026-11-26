#include "common.h"
void func_001DC398(void *v0, void *v1) {
    asm __volatile__("lqc2 $vf16,0x0(%1)\n\tvmulax.xyzw ACC,$vf1,$vf16x\n\tvmadday.xyzw ACC,$vf2,$vf16y\n\tvmaddaz.xyzw ACC,$vf3,$vf16z\n\tvmaddw.xyzw $vf16,$vf4,$vf16w\n\tvnop\n\tvnop\n\tvnop\n\tvdiv Q,$vf0w,$vf16w\n\tvnop\n\tvnop\n\tvnop\n\tvnop\n\tvnop\n\tvnop\n\tvmulq.xyzw $vf26,$vf16,Q\n\tvnop\n\tvnop\n\tvnop\n\tvftoi4.xyzw $vf16,$vf26\n\tvnop\n\tvnop\n\tvnop\n\tsqc2 $vf16,0x0(%0)" : : "r"(v0), "r"(v1));
}
