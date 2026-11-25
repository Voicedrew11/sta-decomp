#include "m2c.h"
typedef struct { s32 x0; s32 x4; u8 x8; u8 pad9; u8 xA; u8 padB[3]; u8 xE; } Obj;
s32 func_0017F470(s32, s32, f32);
void func_0017F7C0(s32, s32, s32);
s32 func_0017F3D0(s32);
void func_00131600(s32, u8);
extern s32 D_004A10E4[];
extern s32 D_004A10D0[];
extern f32 D_004A10D8[];
extern s32 D_004A10D4[];
extern s32 D_004A10C0[];
extern s32 D_004A10C4[];
extern s32 D_004A10C8[];
extern u8 D_004A1070[];
extern u8 D_004A1072[];
extern u8 D_004A1078[];
extern s32 D_00202128;

void func_0018F0D0(Obj *o) {
    s32 cur;
    u32 old;
    s32 b;

    cur = D_004A10E4[0];
    old = cur;
    func_0017F470(0xD, 0, D_004A10D0[0]);
    if (D_004A10D8[0] > 20.0f) {
        func_0017F7C0(0xB, 1, 0);
        func_0017F7C0(0xC, 1, 0);
    } else {
        return;
    }
    if (func_0017F3D0(0xB)) {
        switch (D_004A10E4[0]) {
        case 0:
            if (o->x4 & 0x20) {
                D_004A1078[0] = !D_004A1078[0];
                func_00131600(0x6A, o->xE);
            }
            if (o->x4 & 0x80) {
                D_004A1078[0] = !D_004A1078[0];
                func_00131600(0x6A, o->xE);
            }
            break;
        case 1:
            if (o->x4 & 0x20) {
                if (D_004A1072[0] < 2) {
                    D_004A1072[0]++;
                } else {
                    D_004A1072[0] = 0;
                }
                func_00131600(0x6A, o->xE);
            }
            if (o->x4 & 0x80) {
                if (D_004A1072[0] > 0) {
                    D_004A1072[0]--;
                } else {
                    D_004A1072[0] = 2;
                }
                func_00131600(0x6A, o->xE);
            }
            break;
        case 2:
            if ((o->x4 & 0x20) && D_004A1070[0] < 0x40) {
                func_00131600(0x6A, o->xE);
                D_004A1070[0]++;
            }
            if ((o->x4 & 0x80) && D_004A1070[0] > 0) {
                func_00131600(0x6A, o->xE);
                D_004A1070[0]--;
            }
            break;
        }
    }
    if (o->x4 & 0x4000) {
        if (func_0017F470(0xB, 1, -4.0f) && func_0017F470(0xC, 1, 1.0f)) {
            func_00131600(0x68, o->xE);
            D_004A10D4[0] = 0;
            D_00202128 = 2;
            return;
        }
    }
    b = o->x4;
    if (b & 0x10) {
        D_004A10C0[0] = 0;
        cur--;
        D_004A10C8[0] = 0;
        D_004A10C4[0] = 0;
        o->x4 &= ~0x10;
    } else if (b & 0x40) {
        D_004A10C0[0] = 0;
        cur++;
        D_004A10C8[0] = 0;
        D_004A10C4[0] = 0;
        o->x4 &= ~0x40;
    }
    if (!func_0017F470(0xB, 0, D_004A10E4[0])) {
        D_004A10E4[0] = old;
        return;
    }
    if (D_004A10E4[0] != cur) {
        func_00131600(0x66, o->xE);
    }
    D_004A10E4[0] = (cur + 3) % 3;
    func_0017F470(0xC, 0, D_004A10E4[0]);
}
