#include "common.h"
typedef union { u32 w; struct { u8 r, g, b, a; } c; } Col;
typedef struct { u8 pad[8]; u8 x8; } E;
void func_0018A310(s32);
void func_0019E090(f32, E *);
f32 func_00187770(f32, f32, f32);
s8 *func_00195B10(s32);
void func_001875C0(s8 *, s32, Col, f32, f32, f32);
extern f32 D_00201D78;
extern s32 D_004A32C8[];

void func_0019DF90(E *e) {
    Col c;
    func_0018A310(0xC);
    if (!(D_00201D78 <= -2.49f)) func_0019E090(D_00201D78, e);
    if (e->x8 == 0x14) {
        D_00201D78 = func_00187770(D_00201D78, -0.02f, 3.5f);
        c.w = 0x80FFFFFF;
        if (D_004A32C8[0] >= 0) {
            func_001875C0(func_00195B10(D_004A32C8[0] + 0xA), 2, c, 622.0f, 17.0f, 1.0f);
        }
    } else {
        D_00201D78 = func_00187770(D_00201D78, -2.99f, 3.5f);
    }
}
