#include "common.h"
f32 func_00171550(Vec *m) {
    Vec v;
    asm("lqc2 $vf15, 0x0(%1)\n\tlqc2 $vf16, 0x10(%1)\n\tlqc2 $vf17, 0x20(%1)\n\tvmul.xyz $vf14, $vf15, $vf15\n\tvaddy.x $vf14, $vf14, $vf14y\n\tvaddz.x $vf15, $vf14, $vf14z\n\tvmul.xyz $vf14, $vf16, $vf16\n\tvaddy.x $vf14, $vf14, $vf14y\n\tvaddz.x $vf16, $vf14, $vf14z\n\tvmul.xyz $vf14, $vf17, $vf17\n\tvaddy.x $vf14, $vf14, $vf14y\n\tvaddz.x $vf17, $vf14, $vf14z\n\tvmax.x $vf14, $vf15, $vf16\n\tvmax.x $vf14, $vf14, $vf17\n\tvsqrt Q, $vf14x\n\tvwaitq\n\tvaddq.x $vf14, $vf0, Q\n\tsqc2 $vf14, 0x0(%0)" : : "r"(&v), "r"(m));
    return v.x;
}
