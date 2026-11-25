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
} T;
u32 func_00125E00(void *);
void func_00187A90(void *, void *, u64);
s32 func_00188010(void *, C);

void func_00187680(s8 *str, u32 a, s16 h, C col, f32 x, f32 y, f32 sc) {
    T t;
    if (str == 0) {
        return;
    }
    func_00187A90(&t, str, func_00125E00(str));
    t.x0 = x;
    t.x4 = y;
    t.x8.a = a;
    t.x24 = 1.0f;
    t.x20 = sc;
    t.x14 = 4096.0f;
    t.x8.d = 1;
    t.xC = h;
    func_00188010(&t, col);
}
