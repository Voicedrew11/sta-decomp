#include "common.h"
typedef struct { u8 pad[0x14]; f32 x14; } A;
typedef struct { u8 pad[8]; f32 x8; } B;
void func_0017F840(s32, s32 *);
extern s32 D_00201D48;
extern f32 *D_00201D50;
extern s32 D_002021AC;
extern s32 D_004A28C0[];

void func_0019A6A0(s32 i, A *a, B *b) {
    s32 t;
    func_0017F840(D_00201D48, &t);
    switch (D_002021AC) {
    case 0:
        a->x14 = b->x8 - (f32)i;
        break;
    case 2:
        if (i >= D_004A28C0[0] - 3 && i <= D_004A28C0[0] + 3) {
            a->x14 = D_00201D50[i] = b->x8 - (f32)i;
        } else {
            a->x14 = D_00201D50[i] = -5.0f;
        }
        break;
    }
}
