#include "m2c.h"
typedef struct { u8 b0:1; u8 b1:1; u8 b2:1; u8 r:5; } F;
typedef struct { s32 x0; s32 x4; u8 x8; u8 pad[5]; u8 xE; } P;
s32 func_001A4570(void);
s32 func_001E82A0(s32);
s32 func_0017F470(f32, s32, s32);
void func_00131600(s32, u8);
void func_0018E470(s32);
void func_00189ED0(s32);
extern s32 D_004A4390[];
extern s32 D_004A4394[];
extern f32 D_004A4398[];
extern u8 D_004A43A2[];
extern F D_004A43AC[];

void func_001A40A0(P *p) {
    s32 cur;
    s32 old;
    s32 r;
    u8 c;

    if (D_004A4394[0] == 0) {
        if (D_004A43AC[0].b2) {
            r = func_001A4570();
            if (r == 0) return;
            if (r >= 0 && (r & 2)) {
                D_004A4390[0] = 1;
                D_004A43AC[0].b0 = 1;
            } else {
                D_004A43AC[0].b0 = 0;
            }
            D_004A4394[0] = 1;
            if (D_004A43AC[0].b0) D_004A4390[0] = 1;
            func_001E82A0(0);
            func_0017F470(0.0f, 0, 1);
        } else {
            D_004A4394[0] = 1;
            func_0017F470(0.0f, 0, 1);
        }
    }
    if (D_004A4394[0] == 1) {
        old = cur = D_004A4390[0];
        if (!(D_004A4398[0] <= 30.0f) && (p->x4 & 0x2008)) {
            switch (cur) {
            case 0:
                if (func_0017F470(-3.0f, 0, 1)) {
                    D_004A43AC[0].b1 = 1;
                    func_00131600(0x69, p->xE);
                    D_004A43A2[0] = 7;
                    D_004A4394[0] = 2;
                }
                break;
            case 1:
                if (func_0017F470(-3.0f, 0, 1)) {
                    func_00131600(0x69, p->xE);
                    D_004A43A2[0] = 9;
                    D_004A4394[0] = 2;
                    func_0018E470(1);
                }
                break;
            }
            D_004A4398[0] = 0.0f;
            return;
        }
        if (p->x4 & 0x10) {
            cur--;
            p->x4 &= ~0x10;
        } else if (p->x4 & 0x40) {
            cur++;
            p->x4 &= ~0x40;
        }
        if (!func_0017F470(*(volatile s32 *)D_004A4390, 0, 0)) {
            D_004A4390[0] = old;
        } else {
            if (cur != D_004A4390[0]) {
                func_00131600(0x66, p->xE);
            }
            D_004A4390[0] = (cur + 2) % 2;
        }
    }
    D_004A4398[0] += 1.0f;
    if (D_004A4394[0] == 2) {
        c = D_004A43A2[0];
        if (D_004A4398[0] < 5.0f) return;
        p->x8 = c;
        if (*(volatile u8 *)D_004A43A2 == 7) {
            func_0018E470(1);
            func_00189ED0(7);
            p->x8 = 0xD;
        } else {
            func_00189ED0(6);
        }
        p->x4 = 0;
        p->x0 = 0x1A;
    }
}
