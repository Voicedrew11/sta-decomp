#include "common.h"
typedef struct { s32 x0; s32 x4; s32 x8; u8 xC; u8 p[3]; } B;
typedef struct { s8 a; s8 b; s8 c; s8 d; } C;
extern struct { char pad[0x200]; B b[8]; C c[64]; } D_004BA500;
extern u16 D_004BAA36[];
void func_001DBDB0(s32, s32, s32, s32, s32, s32, s32);
s32 func_001DA620(s32 i, s32 j, u8 x, u8 y, u8 z) {
    C *c;
    B *b;
    if (D_004BAA36[0] == 0) {
        return -1;
    }
    if (!(0 > i) && i < 0x40 && !(0 > j) && j < 8) {
        c = &D_004BA500.c[i];
        b = &D_004BA500.b[j];
        if (b->x0 == 0) {
            return -1;
        }
        func_001DBDB0(1, 5, i, j, x, y, (z << 4) | (b->xC & 0xF));
        c->a = -1;
        c->b = j;
        c->c = 0;
    } else {
        return -1;
    }
    return i;
}
