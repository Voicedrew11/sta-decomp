#include "common.h"
typedef struct { u8 b0 : 1; u8 b1 : 1; u8 b2 : 4; u8 b6 : 2; } B;
typedef struct { char p[0x48]; B b; char q[3]; } E;
extern E D_00486990[24];
void func_0017F7C0(s32 i, s32 on, s32 f) {
    B *b;
    i %= 24;
    b = &D_00486990[i].b;
    b->b0 = on & 1;
    if (f) b->b2 = 3;
}
