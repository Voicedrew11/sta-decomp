#include "m2c.h"
extern s32 D_002021F4;
extern s32 D_004A3290[];
extern f32 *D_00201D6C;
void func_0017F840(s32, s32 *);

void func_0019DE90(s32 i, s8 *a1, s8 *a2) {
    s32 t;
    f32 f;
    func_0017F840(1, &t);
    switch (D_002021F4) {
    case 0:
        *(f32 *)(a1 + 0x14) = *(f32 *)(a2 + 8) - (f32)i;
        break;
    case 2:
        if (i >= D_004A3290[0] - 3 && i <= D_004A3290[0] + 3) {
            f = *(f32 *)(a2 + 8) - (f32)i;
            D_00201D6C[i] = f;
            *(f32 *)(a1 + 0x14) = f;
        } else {
            D_00201D6C[i] = -5.0f;
            *(f32 *)(a1 + 0x14) = -5.0f;
        }
        break;
    }
}
