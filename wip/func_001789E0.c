#include "m2c.h"
#define R(a) (*(volatile u32 *)(a))
#define WAIT(L) asm { sync; L: nop; nop; nop; nop; nop; bc0f L; nop }
#define WAITE(L) asm { sync; L: nop; nop; nop; nop; nop; bc0f L }
void func_001789E0(s32 a0, s32 a1, u32 a2) {
    goto cond;
body:
    R(0x1000E020) = 0xFFFFFC00;
    R(0x1000E010) = 0x200;
    R(0x1000D410) = a1;
    a1 += 0x3000;
    R(0x1000D420) = 0x300;
    R(0x1000D480) = 0x70000000;
    R(0x1000E020) |= 0x200;
    R(0x1000D400) = 0x101;
    WAIT(W1);
    R(0x1000E020) = 0xFFFFFC00;
    a2 -= 0x300;
    R(0x1000E010) = 0x100;
    R(0x1000D010) = a0;
    a0 += 0x3000;
    R(0x1000D020) = 0x300;
    R(0x1000D080) = 0x70000000;
    R(0x1000E020) |= 0x100;
    R(0x1000D000) = 0x100;
    WAIT(W2);
cond:
    if (a2 > 0x300) goto body;
    R(0x1000E020) = 0xFFFFFC00;
    R(0x1000E010) = 0x200;
    R(0x1000D410) = a1;
    a1 += a2 << 4;
    R(0x1000D420) = a2;
    R(0x1000D480) = 0x70000000;
    R(0x1000E020) |= 0x200;
    R(0x1000D400) = 0x101;
    WAIT(W3);
    R(0x1000E020) = 0xFFFFFC00;
    R(0x1000E010) = 0x100;
    R(0x1000D010) = a0;
    a0 += a2 << 4;
    R(0x1000D020) = a2;
    R(0x1000D080) = 0x70000000;
    R(0x1000E020) |= 0x100;
    R(0x1000D000) = 0x100;
    WAITE(W4);
}
