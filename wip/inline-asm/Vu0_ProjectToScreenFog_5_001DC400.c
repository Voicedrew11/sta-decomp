#include "common.h"
void Vu0_ProjectToScreenFog_5_001DC400(Vec *d, Vec *s)
{
    __asm__ __volatile__(
"lqc2 $vf16, 0x0(%1)\n"
"vmulax.xyzw ACC, $vf1, $vf16x\n"
"vmadday.xyzw ACC, $vf2, $vf16y\n"
"vmaddaz.xyzw ACC, $vf3, $vf16z\n"
"vmaddw.xyzw $vf16, $vf4, $vf16w\n"
"vnop\nvnop\nvnop\n"
"vdiv Q, $vf0w, $vf16w\n"
"vnop\nvnop\nvnop\nvnop\nvnop\n"
"vmula.w ACC, $vf12, $vf0\n"
"vmaddq.w $vf26, $vf13, Q\n"
"vmulq.xyz $vf26, $vf16, Q\n"
"vnop\nvnop\nvnop\n"
"vftoi4.xyzw $vf16, $vf26\n"
"vnop\nvnop\nvnop\n"
"sqc2 $vf16, 0x0(%0)" : : "r"(d), "r"(s));
}
