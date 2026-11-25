#include "m2c.h"
typedef struct { s32 buf, size, n, cur; s32 stk[16]; s32 x50, x54, x58, x5C, x60, x64, x68, x6C; } G;
extern G D_002F1940;
extern s32 D_00201F28;
void func_001549D0(void);
static inline void chk(void) {
    if ((u32)((D_002F1940.cur - D_002F1940.x68) / 32) < 0x660) {
        D_00201F28 = 1;
    } else {
        D_00201F28 = 0;
    }
}
static inline void push(s32 off) {
    if (D_002F1940.x54) func_001549D0();
    D_002F1940.cur = D_002F1940.x68 + off;
    D_002F1940.stk[D_002F1940.n] = D_002F1940.cur;
    D_002F1940.n++;
    chk();
}

void func_00154610(s32 a0, s32 a1) {
    push(((a1 + 0x10) + a0 * 0x220) * 32);
}
