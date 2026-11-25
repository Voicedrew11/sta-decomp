#include "m2c.h"
void func_0017F840(s32, void **);
extern s32 D_00202238;
extern s32 D_00202230;
extern f32 *D_00201D80;
extern s32 D_004A4330[];

void func_001A2FF0(s32 i, s8 *o, s8 *p) {
    void *info;
    func_0017F840(D_00202238, &info);
    switch (D_00202230) {
    case 0:
        *(f32 *)(o + 0x14) = *(f32 *)(p + 8) - (f32)i;
        break;
    case 2:
        if (i >= D_004A4330[0] - 3 && i <= D_004A4330[0] + 3) {
            *(f32 *)(o + 0x14) = D_00201D80[i] = *(f32 *)(p + 8) - (f32)i;
        } else {
            *(f32 *)(o + 0x14) = D_00201D80[i] = -5.0f;
        }
        break;
    }
}
