#include "m2c.h"
extern s32 *D_00201D7C;
extern s32 D_00202224;
extern s32 D_004A3320[];
extern u32 D_004A331C[];
extern f32 D_004A3328[];
extern s32 D_004A4330[];
extern s32 D_004A4334[];
void func_001A2F20(s32);
void func_00183DC0(s32);
void func_001A1C80(s32);
void func_001A1000(s32);
void func_001A0DB0(s32);
void func_001A0B00(s32);
void func_001A0850(s32);
void func_001A06B0(s32);
void func_001A03C0(s32);

void func_001A1B40(s32 a0) {
    s32 id;
    s32 x;

    x = D_004A3320[0];
    id = D_00201D7C[D_004A4330[0]];
    if (D_00202224 <= 0) id = -1;
    D_004A4334[0] = 0;
    func_001A2F20(x);
    func_00183DC0(id);
    if (D_004A3328[0] > 0.0f) {
        D_004A3328[0] -= 1.0f;
        return;
    }
    switch (D_004A331C[0]) {
    case 0: func_001A1C80(a0); break;
    case 1: func_001A1000(a0); break;
    case 2: func_001A0DB0(a0); break;
    case 3: func_001A0B00(a0); break;
    case 4: func_001A0850(a0); break;
    case 5: func_001A06B0(a0); break;
    case 6: func_001A03C0(a0); break;
    }
}
