#include "common.h"
typedef union { u32 w; struct { u8 r, g, b, a; } c; } C;
typedef struct { u8 a:3; u8 b:5; } BF;
typedef struct { f32 x0; f32 x4; BF x8; u8 p9[5]; s16 xE; u8 p10[4]; f32 x14; u8 p18[8]; f32 x20; f32 x24; u8 p28[0x14]; } T;
s8 *func_0019D4A0(s32);
u32 strlen(void *);
void func_00187A90(void *, void *, u64);
s32 func_00188010(void *, C);
extern s32 D_00202358;
void func_001DF360(s32 on, s32 id) {
    T t;
    C col;
    s8 *s = func_0019D4A0(id);
    if (s == NULL) return;
    func_00187A90(&t, s, strlen(s));
    t.x0 = 598.0f;
    t.x4 = 286.0f;
    t.x8.a = 2;
    t.x24 = 1.0f;
    t.x20 = 1.1f;
    t.x14 = 4096.0f;
    t.xE = 100;
    col.w = 0x80808080;
    if (on) {
        D_00202358 += 0x10;
        if (D_00202358 > 0x80) D_00202358 = 0x80;
    } else {
        D_00202358 = 0;
    }
    col.c.a = D_00202358;
    func_00188010(&t, col);
}
