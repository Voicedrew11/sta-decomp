#include "common.h"
typedef struct { char p[4]; u8 b4; char p5; u16 h6; } H;
extern s32 D_00201F2C;
void func_00171BB0(s32, H *, u8, u8, s32, f32);
void func_00171B70(H *h, s32 a, f32 f) {
    func_00171BB0((s32)((u8 *)((s32)h + 0x40) + D_00201F2C * (h->h6 * 0x140 + 0x200)), h, h->b4, h->h6, a, f);
}
