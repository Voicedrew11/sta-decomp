#include "common.h"
void func_001DC510(void *a, void *b, void *c, void *d, void *e, void *f) {
    asm volatile("lqc2 $vf16, 0x0(%3)
	vmulax.xyzw ACC, $vf1, $vf16x
	vmadday.xyzw ACC, $vf2, $vf16y
	vmaddaz.xyzw ACC, $vf3, $vf16z
	vmaddw.xyzw $vf16, $vf4, $vf16w
	lqc2 $vf17, 0x0(%4)
	lqc2 $vf18, 0x0(%5)
	vnop
	vdiv Q, $vf0w, $vf16w
	vmulax.xyzw ACC, $vf1, $vf17x
	vmadday.xyzw ACC, $vf2, $vf17y
	vmaddaz.xyzw ACC, $vf3, $vf17z
	vmaddw.xyzw $vf17, $vf4, $vf17w
	vnop
	vmula.w ACC, $vf12, $vf0
	vmaddq.w $vf26, $vf13, Q
	vmulq.xyz $vf26, $vf16, Q
	vdiv Q, $vf0w, $vf17w
	vmulax.xyzw ACC, $vf1, $vf18x
	vmadday.xyzw ACC, $vf2, $vf18y
	vmaddaz.xyzw ACC, $vf3, $vf18z
	vmaddw.xyzw $vf18, $vf4, $vf18w
	vftoi4.xyzw $vf16, $vf26
	vmula.w ACC, $vf12, $vf0
	vmaddq.w $vf27, $vf13, Q
	vmulq.xyz $vf27, $vf17, Q
	vdiv Q, $vf0w, $vf18w
	sqc2 $vf16, 0x0(%0)
	vnop
	vftoi4.xyzw $vf17, $vf27
	vnop
	vnop
	vmula.w ACC, $vf12, $vf0
	vmaddq.w $vf28, $vf13, Q
	vmulq.xyz $vf28, $vf18, Q
	sqc2 $vf17, 0x0(%1)
	vnop
	vnop
	vftoi4.xyzw $vf18, $vf28
	vnop
	vnop
	vnop
	sqc2 $vf18, 0x0(%2)
	" : : "r"(a), "r"(b), "r"(c), "r"(d), "r"(e), "r"(f));
}
