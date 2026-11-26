#include "m2c.h"
extern s32 D_00201CF4;
extern f32 D_002020D4;
extern f32 D_002020D8;
extern f32 D_00202108;
extern s32 D_004A0AE0[];
extern s16 D_004A0AF0[];

void func_0018A420(s32 *a0) {
    switch (*a0) {
    case 0:
        *a0 = 0x16;
        break;
    case 0x19:
        if (D_00201CF4 != *a0) {
            D_004A0AE0[0] = 0;
            D_004A0AF0[0] = 3;
            D_002020D8 = D_002020D4;
        }
        *a0 = 0x1B;
        break;
    case 0x1A:
        *a0 = 0x1C;
        break;
    case 0x1B:
        if (!(D_00202108 <= 5.0f)) {
            D_00202108 = 0.0f;
            *a0 = 0;
        } else {
            D_00202108 += 1.0f;
        }
        break;
    case 0x1C:
        if (!(D_00202108 <= 12.0f)) {
            D_00202108 = 0.0f;
            *a0 = 0x1E;
        } else {
            D_00202108 += 1.0f;
        }
        break;
    case 0x1E:
        *a0 = 0x1F;
        break;
    case 0x21:
        D_002020D8 = D_002020D4;
        *a0 = 0x16;
        break;
    case 0x20:
        break;
    }
    D_00201CF4 = *a0;
}
