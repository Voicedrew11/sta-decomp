#include "common.h"
typedef struct { s32 x0; s32 x4; s8 x8; } T;
extern f32 D_00202408;
extern f32 D_0020240C;
extern s32 D_00202410;
void func_001ED9A0(T *a) {
    if (a->x0 == 0x19) {
        D_00202408 = 0.0f;
        D_0020240C = 0.0f;
        D_00202410 = 0;
    }
    if (a->x0 == 0x16) {
        switch (D_00202410) {
        case 0:
            D_00202408 += 4.0f;
            if (!(D_00202408 <= 128.0f)) {
                D_00202408 = 128.0f;
                D_00202410 = 3;
            }
            break;
        case 1:
            break;
        case 3:
            D_0020240C += 1.0f;
            if (!(D_0020240C <= 450.0f)) {
                D_00202410 = 4;
            }
            break;
        case 4:
            D_00202408 -= 4.0f;
            if (D_00202408 < 0.0f) {
                D_00202408 = 0.0f;
                D_00202410 = 5;
            }
            break;
        case 5:
            a->x8 = 4;
            a->x4 = 0;
            a->x0 = 0x1A;
            break;
        }
    }
}
