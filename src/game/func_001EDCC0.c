#include "common.h"
typedef struct { s32 x0; u8 pad[0x10]; Flags8 f14; } A;
void func_0012C320(void);
void func_00130440(void);
s32 func_00130590(s32 *, s32, s32);
extern s32 D_00201A70[];
extern f32 D_00202414;
extern f32 D_00202418;
extern f32 D_0020241C;
extern s32 D_00202420;

void func_001EDCC0(A *a) {
    if (a->x0 == 0x19) {
        D_00202414 = 0.0f;
        D_00202418 = 0.0f;
        D_0020241C = 0.0f;
        D_00202420 = 0;
        func_0012C320();
        func_00130590(D_00201A70, 0, 0);
    }
    if (a->x0 == 0x16) {
        switch (D_00202420) {
        case 0:
            D_00202414 += 4.0f;
            if (D_00202414 > 128.0f) {
                D_00202414 = 128.0f;
                D_00202420 = 1;
            }
            break;
        case 1:
            D_00202418 += 4.0f;
            if (D_00202418 > 128.0f) {
                D_00202418 = 128.0f;
                D_00202420 = 3;
            }
            break;
        case 3:
            D_0020241C += 1.0f;
            if (D_0020241C > 450.0f) {
                D_00202420 = 4;
            }
            break;
        case 4:
            D_00202418 -= 4.0f;
            if (D_00202418 < 0.0f) {
                D_00202418 = 0.0f;
                D_00202420 = 5;
            }
            break;
        case 5:
            func_00130440();
            a->f14.f.b1 = 1;
            break;
        }
    }
}

