
#include "m2c.h"
#define R(a) (*(volatile u32 *)(a))
#define WAIT(L) asm { sync; L: nop; nop; nop; nop; nop; bc0f L; nop }
void Dma_SprClear_1_00178C00(s32 a0, u32 a1) {
    u32 q;
    goto cond;
body:
    R(0x1000E020) = 0xFFFFFC00;
    R(0x1000E010) = 0x100;
    R(0x1000D010) = a0;
    R(0x1000D020) = 0x300;
    R(0x1000D080) = 0x70000000;
    R(0x1000E020) |= 0x100;
    R(0x1000D000) = 0x100;
    WAIT(W1);
    a0 += 0x3000;
    a1 -= 0x3000;
cond:
    if (a1 >= 0x3000) goto body;
    if (a1 < 0x10) return;
    q = a1 >> 4;
    R(0x1000E020) = 0xFFFFFC00;
    R(0x1000E010) = 0x100;
    R(0x1000D010) = a0;
    R(0x1000D020) = q;
    R(0x1000D080) = 0x70000000;
    R(0x1000E020) |= 0x100;
    R(0x1000D000) = 0x100;
    WAIT(W2);
}
