#include "m2c.h"
#include "actor.h"
typedef struct { u16 a : 7; u16 v : 6; } BF;
s32 func_00169B50(s32, s32, s32, s32);
void func_00102CC8(f32 *, void *, f32);
void func_00102A60(f32 *, s8 *);
void func_001677C0(s32, f32 *);
void func_001CA2D0(u8);
s32 func_001C8320(s32, s32, s32, s32);
extern Actor *D_002022E4;
extern s8 D_001F2170[];
#define WRAP(x) ((((3.1415927f + (x)) - 6.2831855f * (s32)(0.15915494f * (3.1415927f + (x)))) + ((3.1415927f + (x)) < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f)
static inline s8 *cur(void) {
    if (D_002022E4 == 0) return 0;
    if (D_002022E4->unk518 == 0) return 0;
    return D_002022E4->unk518 + 0x180;
}

void func_001BE510(Actor *a0) {
    s8 *s1;
    s32 s0;
    f32 m[16];
    s8 *c;
    f32 t, h, n;

    s1 = a0->unk518 + 0x180;
    if (((BF *)(a0->unk518 + 0x520))->v > 8) {
        s0 = 0;
        switch (*(u8 *)(s1 + 0x3BF)) {
        case 0: case 2: case 3: case 4: case 7: case 8: case 9: case 10: case 11: case 12: case 13: case 15: break;
        case 1: s0 = func_00169B50(0x1DB, 0, 0, 0); break;
        case 5: s0 = func_00169B50(0x1DE, 0, 0, 0); break;
        case 6: s0 = func_00169B50(0x1DD, 0, 0, 0); break;
        case 14: s0 = func_00169B50(0x1DD, 0, 0, 0); break;
        }
        if (s0 != 0) {
            func_00102CC8(m, D_001F2170, WRAP(*(f32 *)(*(s8 **)(s1 + 0x18) + 0x24)));
            c = cur();
            if (c != 0) {
                func_00102A60(m + 12, c + 0x40);
            }
            m[13] += 220.0f;
            func_001677C0(s0, m);
        }
        func_001CA2D0(*(u8 *)(s1 + 0x3BF));
    }
    if (((BF *)(s1 + 0x3A0))->v >= 20) {
        t = 30.0f * *(f32 *)(s1 + 0x54);
        h = t / 1000.0f;
        n = h / 2.0f - 9.0f;
        if (n == 0.0f) n = 1.0f;
        s0 = (s32)((h * h) / (1800.0f / n));
        if (s0 > 0) {
            func_001C8320(s0, 1, 1, 1);
            *(s32 *)(*(s8 **)(s1 + 0x390) + 0x48) = 60;
        }
    }
}
