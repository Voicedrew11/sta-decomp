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
u32 strlen(void *);
void TextParam_Init_1_00187A90(void *, void *, u64);
s32 Text_Render_2_00188010(void *, C);
void Text_DrawScaledH_1_001874F0(s16 h, s8 *str, u32 a, C col, f32 x, f32 y, f32 sc) {
    T t;
    if (str == 0) return;
    TextParam_Init_1_00187A90(&t, str, strlen(str));
    t.x0 = x;
    t.x4 = y;
    t.xC = h;
    t.x8.a = a;
    t.x24 = 1.0f;
    t.x20 = sc;
    t.x14 = 4096.0f;
    Text_Render_2_00188010(&t, col);
}

