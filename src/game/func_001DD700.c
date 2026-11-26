#include "common.h"
typedef union { u32 w; struct { u8 r, g, b, a; } c; } C;
typedef struct { u8 a:3; u8 c:1; u8 d:1; u8 e:3; } BF;
typedef struct {
    f32 x0;
    f32 x4;
    BF x8;
    u8 pad9[3];
    s16 xC;
    u8 padE[6];
    f32 x14;
    u8 pad18[8];
    f32 x20;
    f32 x24;
    s8 *x28;
    u8 pad2C[0x10];
} T;
u32 strlen(void *);
void func_00187A90(void *, void *, u64);
s32 func_00188010(void *, C);
void func_00187B20(s32);
s8 *func_00195B10(s32);
extern s32 D_00201E50;
extern f32 D_002020D4;
extern f32 D_00202360;

void func_001DD700(s32 a0, s32 a1) {
    C col;
    T t;
    s8 *s;
    col.w = 0x80808080;
    a0 += a1;
    if (D_00201E50 != a0) {
        D_00201E50 = a0;
        D_00202360 = D_002020D4;
    }
    s = func_00195B10(a0 + 0x12C);
    if (s == 0) {
        return;
    }
    func_00187A90(&t, s, strlen(s));
    t.x0 = 622.0f;
    t.x4 = 415.0f;
    t.x8.a = 2;
    t.x24 = 1.0f;
    t.x20 = 0.7f;
    t.x14 = 3.0f * (D_002020D4 - D_00202360);
    func_00188010(&t, col);
    func_00187B20(1);
}
