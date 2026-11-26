#include "common.h"
typedef struct {
    s32 x0;
    s32 x4;
    u8 x8;
    u8 pad9[5];
    u8 xE;
    u8 padF[5];
    Flags8 f14;
} O;
void func_00130440(void);
void func_001304B0(s32);
void func_00131600(s32, u8);
void func_001DD650(O *);
extern s16 D_00201E40;
extern f32 D_00202334;
extern f32 D_00202338;
extern s32 D_00202340;
extern u8 D_00202348;
extern s16 D_00202350;
extern s16 D_00202352;
extern s16 D_00202354;
extern s16 D_00202356;

void func_001DCC30(O *o) {
    s16 v;

    func_001DD650(o);
    if (o->x0 != 0x16) return;
    if (D_00202348 != 5) {
        D_00202356 = (127.0f * (15.0f - (D_00202334 - D_00202338))) / 15.0f;
        if (!(D_00202334 < 15.0f + D_00202338)) {
            o->x8 = D_00202348;
            o->x4 = 0;
            o->x0 = 0x1A;
        }
    } else {
        if (!(D_00202334 <= 100.0f) && (o->x4 & 0x6008)) {
            func_00131600(0x69, o->xE);
            D_00202348 = 6;
            D_00202338 = D_00202334;
            o->x8 = 6;
            o->f14.f.b5 = 0;
            D_00202340 = 0;
            o->x4 = 0;
            o->x0 = 0x1F;
            return;
        }
        if (o->x4 & 0x6008) {
            func_00131600(0x69, o->xE);
            D_00202348 = 6;
            D_00202338 = D_00202334;
            o->x8 = 6;
            o->f14.f.b5 = 1;
            D_00202340 = 0;
            o->x4 = 0;
            o->x0 = 0x1F;
            return;
        }
        if (!(D_00202334 < 1800.0f)) {
            func_001304B0(-0x444);
            D_00201E40 = -2;
            if (!(D_00202334 < 1830.0f)) {
                o->x8 = 4;
                o->x4 = 0;
                o->x0 = 0x1E;
                func_00130440();
            } else {
                v = (127.0f * (1830.0f - D_00202334)) / 30.0f;
                D_00202356 = v;
                D_00202354 = v;
                D_00202352 = v;
                D_00202350 = v;
            }
        }
    }
    D_00202334 += 1.0f;
}

