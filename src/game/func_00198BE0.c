#include "common.h"
typedef struct { s32 x0; s32 x4; u8 x8; u8 pad9[5]; u8 xE; } M;
extern s32 D_002021A8;
extern s32 D_004A1450[];
extern s32 D_004A18B0[];
extern f32 D_004A18B8[];
void func_00199000(void);
void func_00198D80(void);
void func_001803D0(s32, s32);
void func_00131600(s32, s32);
void func_0017F7C0(s32, s32, s32);
s32 func_0017F470(f32, s32, s32);
void func_00183970(s32);

void func_00198BE0(M *m) {
    s32 sel;
    s32 old;
    switch (m->x0) {
    case 0x19:
        D_004A18B0[0] = 0;
        func_00199000();
        func_00198D80();
        break;
    case 0x16:
        old = D_004A18B0[0];
        sel = old;
        if (m->x4 & 0x4000) {
            func_001803D0(-2, -2);
            func_00131600(0x69, m->xE);
            m->x8 = 0x18;
            m->x4 = 0;
            m->x0 = 0x1A;
            func_0017F7C0(0, 0, 1);
            return;
        }
        if (m->x4 & 0x10) {
            sel = old - 1;
        } else if (m->x4 & 0x40) {
            sel = old + 1;
        }
        if (D_002021A8 != 0) {
            sel = (sel + D_002021A8) % D_002021A8;
        }
        if (func_0017F470(old, 0, 0)) {
            if (D_004A18B0[0] != sel) {
                func_00131600(0x66, m->xE);
            }
            D_004A18B0[0] = sel;
        } else {
            D_004A18B8[0] = 10.0f;
        }
        break;
    }
    func_00183970(D_004A1450[D_004A18B0[0]] * 10);
}
