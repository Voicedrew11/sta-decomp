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
void func_00195420(void);
void func_00195D80(void);
extern Q2 D_001F2E40;
extern s32 D_001F2E60[];
extern s8 D_001FD268[];
extern s8 *D_00201D28;
extern s8 *D_00201D2C;
extern u8 D_00201D20[4];
extern s32 D_00202154;
extern Tbl *D_0020215C;
extern u32 D_002022B8;
static inline Tbl *get(void) {
    if (D_0020215C != NULL) {
        return (Tbl *)D_0020215C->x0;
    }
    return 0;
}
static inline s8 *find1(Tbl *t, s32 id) {
    Ent *e;
    u32 i;
    if (t == 0) {
        return D_001FD268;
    }
    e = t->e;
    for (i = 0; i < t->n; i++, e++) {
        if (e->id == id) {
            return (s8 *)t + e->o1;
        }
    }
    return D_001FD268;
}
static inline s8 *find2(Tbl *t, s32 id) {
    Ent *e;
    u32 i;
    if (t == 0) {
        return D_001FD268;
    }
    e = t->e;
    for (i = 0; i < t->n; i++, e++) {
        if (e->id == id) {
            return (s8 *)t + e->o2;
        }
    }
    return D_001FD268;
}

void func_00195460(Ev *arg0) {
    Q2 q;
    Arg a;
    s32 n;
    s32 k;
    Tbl *t;
    u32 id;

    if (arg0->x0 == 0x19) {
        id = D_002022B8 / 10;
        t = get();
        if (t != 0) {
            D_00201D28 = find1(t, id);
            D_00201D2C = find2(t, id);
            D_00202154 = 0;
            q = D_001F2E40;
            a.p = (s32)D_001F2E60;
            a.n = 3;
            a.fn = func_00195420;
            a.f = -3.0f;
            a.cb = func_00195D80;
            a.a = 0;
            a.b = 0;
            func_0017F890(3, &q, &a);
            func_0017F7C0(3, 1, 1);
            func_0017F470(D_00202154, 3, 1);
        }
    }
    if (arg0->x0 == 0x16) {
        n = D_00202154;
        k = n;
        if (arg0->x4 & 0x2000) {
            func_0017F7C0(3, 0, 1);
            arg0->x4 &= ~0x2000;
            arg0->x8 = D_00201D20[n];
            arg0->x4 = 0;
            arg0->x0 = 0x1F;
            func_00131600(0x69, arg0->xE);
        } else if (arg0->x4 & 0x4000) {
            func_0017F7C0(3, 0, 1);
            arg0->x8 = 0x14;
            arg0->x4 = 0;
            arg0->x0 = 0x1F;
            func_00131600(0x69, arg0->xE);
        } else {
            if (arg0->x4 & 0x10) {
                k = n - 1;
            } else if (arg0->x4 & 0x40) {
                k = n + 1;
            }
            k = (k + 3) % 3;
            if (func_0017F470(n, 3, 0)) {
                if (k != D_00202154) {
                    func_00131600(0x66, arg0->xE);
                }
                D_00202154 = k;
            }
        }
    }
}
