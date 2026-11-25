#include "common.h"
typedef struct { s32 x0; s32 x4; u8 x8; u8 pad9; u8 xA; u8 padB[3]; u8 xE; } Obj;
s32 func_0017F470(s32, s32, f32);
void func_0017F7C0(s32, s32, s32);
s32 func_0017F3D0(s32);
void func_00131600(s32, u8);
int func_0012C1B0(void);
void func_0012C730(s32);
void func_0012C720(s32);
void func_0012DA60(s32);
extern s32 D_004A10E0[];
extern s32 D_004A10D0[];
extern f32 D_004A10D8[];
extern Flags8 D_004A10DC[];
extern s32 D_004A10D4[];
extern s32 D_004A10C0[];
extern s32 D_004A10C4[];
extern s32 D_004A10C8[];
extern u8 D_004A1071[];
extern u8 D_004A1074[];
extern u8 D_004A1075[];
extern s32 D_00202128;

void func_0018F490(Obj *o) {
    s32 cur;
    u32 old;
    s32 b;
    s32 v;

    cur = D_004A10E0[0];
    old = cur;
    func_0017F470(0xD, 0, D_004A10D0[0]);
    if (D_004A10D8[0] <= 20.0f) {
        return;
    }
    if (D_004A10DC[0].f.b5) {
        if (func_0012C1B0()) {
            func_0017F7C0(0xB, 1, 0);
            func_0017F470(0xB, 0, D_004A10E0[0]);
            return;
        }
        D_004A10DC[0].f.b5 = 0;
    }
    if (func_0017F3D0(0xB)) {
        switch (D_004A10E0[0]) {
        case 0:
            if (o->x4 & 0x20) {
                D_004A1071[0]++;
                func_00131600(0x6A, o->xE);
            }
            if (o->x4 & 0x80) {
                if (D_004A1071[0] > 0) {
                    D_004A1071[0]--;
                } else {
                    D_004A1071[0] = 2;
                }
                func_00131600(0x6A, o->xE);
            }
            D_004A1071[0] = D_004A1071[0] % 3u;
            switch (D_004A1071[0]) {
            case 0:
                func_0012DA60(0);
                break;
            case 1:
                func_0012DA60(1);
                break;
            case 2:
                func_0012DA60(2);
                break;
            }
            break;
        case 1:
            if ((o->x4 & 0x20) && D_004A1074[0] < 0x40) {
                func_00131600(0x6A, o->xE);
                D_004A1074[0]++;
            }
            if ((o->x4 & 0x80) && D_004A1074[0] > 0) {
                func_00131600(0x6A, o->xE);
                D_004A1074[0]--;
            }
            v = D_004A1074[0] * 2;
            if (v > 0x7F) {
                v = 0x7F;
            }
            func_0012C730(v);
            break;
        case 2:
            if ((o->x4 & 0x20) && D_004A1075[0] < 0x40) {
                func_00131600(0x6A, o->xE);
                D_004A1075[0]++;
            }
            if ((o->x4 & 0x80) && D_004A1075[0] > 0) {
                func_00131600(0x6A, o->xE);
                D_004A1075[0]--;
            }
            v = D_004A1075[0] * 2;
            if (v > 0x7F) {
                v = 0x7F;
            }
            func_0012C720(v);
            break;
        }
    }
    if (o->x4 & 0x4000) {
        if (func_0017F470(0xB, 1, -4.0f)) {
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
    if (!func_0017F470(0xB, 0, D_004A10E0[0])) {
        D_004A10E0[0] = old;
        return;
    }
    if (cur != D_004A10E0[0]) {
        func_00131600(0x66, o->xE);
    }
    D_004A10E0[0] = (cur + 3) % 3;
}
