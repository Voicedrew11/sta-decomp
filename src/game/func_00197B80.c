#include "m2c.h"
typedef struct { s32 state; s32 btn; s8 x8; s8 pad[5]; u8 xE; } P;
s32 func_0017F470(f32, s32, s32);
void func_0017F7C0(s32, s32, s32);
void func_00183DC0(s32);
s32 func_00195B80(s32, s32 *);
void func_00197F90(s32);
void func_00197DD0(void);
void func_00131600(s32, u8);
extern s32 D_00201D38;
extern s32 *D_00201D3C;
extern s32 D_00202194;
extern s32 D_00202198;
extern s32 D_004A1430[];
extern s32 D_004A1434[];
extern s32 D_004A1438[];
extern s32 D_004A1440[];

void func_00197B80(P *p) {
    s32 sel;

    switch (p->state) {
    case 25:
        D_00201D38 = 6;
        D_004A1430[0] = 0;
        D_00202194 = 0;
        func_00197F90(6);
        func_00197DD0();
        break;
    case 22:
        sel = D_004A1430[0];
        if (p->btn & 0x4000) {
            func_00131600(0x69, p->xE);
            p->x8 = 0x18;
            p->btn = 0;
            p->state = 0x1A;
            func_0017F7C0(D_00201D38, 0, 1);
            return;
        }
        if (p->btn & 0x10) {
            sel--;
        } else if (p->btn & 0x40) {
            sel++;
        } else if (p->btn & 0x480) {
            D_004A1430[0] = 0;
            D_004A1434[0] = 1;
            D_00202194--;
            D_004A1438[0] = func_00195B80(7, &D_00202194);
            D_004A1440[0] = 0;
            func_0017F7C0(D_00201D38, 0, 1);
            func_00131600(0x66, p->xE);
            p->btn = 0;
        } else if (p->btn & 0x820) {
            D_004A1430[0] = 0;
            D_004A1434[0] = 1;
            D_00202194++;
            D_004A1438[0] = func_00195B80(7, &D_00202194);
            D_004A1440[0] = 0;
            func_0017F7C0(D_00201D38, 0, 1);
            func_00131600(0x66, p->xE);
            p->btn = 0;
        }
        if (D_00202198 != 0) {
            sel = (sel + D_00202198) % D_00202198;
        }
        if (func_0017F470(D_004A1430[0], D_00201D38, 0) != 0) {
            if (D_004A1430[0] != sel) {
                func_00131600(0x66, p->xE);
            }
            D_004A1430[0] = sel;
        }
        p->btn = 0;
        break;
    }
    func_00183DC0(D_00201D3C[D_004A1430[0]]);
}
