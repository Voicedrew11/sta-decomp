#include "m2c.h"
typedef struct { u128 q[2]; } Q2;
typedef struct { s32 p; s32 n; f32 f; void *fn; s32 a; s32 b; void *cb; } Arg;
typedef struct { s32 id; s32 o1; s32 o2; } Ent;
typedef struct { s32 x0; u32 n; s32 x8; s32 xC; Ent e[1]; } Tbl;
typedef struct { s32 x0; s32 x4; u8 x8; u8 pad9[5]; u8 xE; } Ev;
void func_0017F890(s32, Q2 *, Arg *);
void func_0017F7C0(s32, s32, s32);
s32 func_0017F470(f32, s32, s32);
void func_00131600(s32, u8);
void func_00183B90(s32);
Tbl *func_001958C0(void);
s32 func_001A9EC0(s16);
void func_00196C50(void);
void func_00196CB0(void);
extern Q2 D_001F2EC0;
extern s32 D_004A11A0[];
extern s32 D_004A13E0[];
extern u32 D_00202184;
extern s32 D_0020218C;

void func_00196940(Ev *arg0) {
    Q2 q;
    Arg a;
    Tbl *t2;
    Ent *e2;
    u32 i2;
    s32 cnt;
    u32 j;
    u32 i;
    Tbl *t;
    Ent *e;
    s32 n;
    s32 k;

    switch (arg0->x0) {
    case 0x19:
        D_004A13E0[0] = 0;
        t = func_001958C0();
        D_0020218C = 0;
        e = t->e;
        for (i = 0; i < t->n; i++, e++) {
            if (func_001A9EC0(e->id)) {
                D_004A11A0[D_0020218C] = e->id;
            } else {
                D_004A11A0[D_0020218C] = -1;
            }
            D_0020218C++;
        }
        t2 = func_001958C0();
        if (t2 == 0) {
            break;
        }
        cnt = 0;
        j = 0;
        e2 = t2->e;
        for (i2 = 0; i2 < t2->n; i2++, e2++) {
            if (func_001A9EC0(e2->id)) {
                cnt++;
            }
            j++;
        }
        D_00202184 = (u32)(cnt * 100) / j;
        q = D_001F2EC0;
        a.p = (s32)D_004A11A0;
        a.fn = func_00196C50;
        a.f = -3.0f;
        a.cb = func_00196CB0;
        a.a = 0;
        a.b = 0;
        a.n = D_0020218C;
        func_0017F890(0, &q, &a);
        func_0017F7C0(0, 1, 0);
        func_0017F470(D_004A13E0[0], 0, 1);
        break;
    case 0x16:
        n = D_004A13E0[0];
        k = n;
        if (arg0->x4 & 0x4000) {
            func_00131600(0x69, arg0->xE);
            arg0->x8 = 0x18;
            arg0->x4 = 0;
            arg0->x0 = 0x1A;
            func_0017F7C0(0, 0, 1);
            return;
        }
        if (arg0->x4 & 0x10) {
            k = n - 1;
        } else if (arg0->x4 & 0x40) {
            k = n + 1;
        }
        if (D_0020218C != 0) {
            k = (k + D_0020218C) % D_0020218C;
        }
        if (func_0017F470(n, 0, 0)) {
            if (D_004A13E0[0] != k) {
                func_00131600(0x66, arg0->xE);
            }
            D_004A13E0[0] = k;
        }
        break;
    }
    func_00183B90(D_004A11A0[D_004A13E0[0]]);
}
