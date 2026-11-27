#include "actor.h"
#include "m2c.h"
void func_001979C0(s32 arg0);
void func_00197B80();

/* func_001979C0 */
typedef struct { u128 q[2]; } Q2;
typedef struct { s32 p; s32 n; f32 f; void *fn; s32 a; s32 b; void *cb; } Arg;
void func_0017F890(s32, Q2 *, Arg *);
void func_0017F7C0(s32, s32, s32);
s32 func_0017F470(f32, s32, s32);
void func_00197F30(void);
void func_00198100(void);
void func_00197F90(s32);
void func_00197B80();
extern Q2 D_001F2F40;
extern s32 D_00201D38;
extern s32 *D_00201D3C;
extern s32 D_00202198;
extern s32 D_004A1430[];
extern s32 D_004A1434[];
extern s32 D_004A1438[];
extern f32 D_004A143C[];
extern f32 D_004A1440[];
extern Flags8 D_004A1444[];

void func_001979C0(s32 arg0) {
    Q2 q;
    Arg a;

    if (!(D_004A143C[0] <= 0.0f)) {
        D_004A143C[0] -= 1.0f;
        D_004A1444[0].f.b1 = 0;
    } else {
        switch (D_004A1434[0]) {
        case 1:
            D_004A1430[0] = 0;
            D_00201D38 = D_004A1438[0];
            func_00197F90(D_00201D38);
            q = D_001F2F40;
            a.fn = func_00197F30;
            a.f = -3.0f;
            a.cb = func_00198100;
            a.a = 0;
            a.b = 0;
            a.p = (s32)D_00201D3C;
            a.n = D_00202198;
            func_0017F890(D_00201D38, &q, &a);
            func_0017F7C0(D_00201D38, 1, 1);
            func_0017F470(D_004A1430[0], D_00201D38, 1);
        }
        D_004A1434[0] = 0;
        D_004A1438[0] = 0;
        D_004A1444[0].f.b1 = 1;
        D_004A1440[0] += 8.0f;
        if (!(D_004A1440[0] <= 128.0f)) {
            D_004A1440[0] = 128.0f;
        }
    }
    if (D_004A1444[0].f.b1) {
        func_00197B80(arg0);
    }
}

/* func_00197B80 */
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
extern f32 D_004A1440[];

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
            *(s32 *)D_004A1440 = 0;
            func_0017F7C0(D_00201D38, 0, 1);
            func_00131600(0x66, p->xE);
            p->btn = 0;
        } else if (p->btn & 0x820) {
            D_004A1430[0] = 0;
            D_004A1434[0] = 1;
            D_00202194++;
            D_004A1438[0] = func_00195B80(7, &D_00202194);
            *(s32 *)D_004A1440 = 0;
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
