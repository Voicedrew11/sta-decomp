#include "actor.h"
#define WRAP(x) ((((3.1415927f + (x)) - 6.2831855f * (s32)(0.15915494f * (3.1415927f + (x)))) + ((3.1415927f + (x)) < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f)
typedef struct { f32 m[4][4]; } MtxF;
typedef struct { u8 pad[0x18]; s8 *o; u8 pad1C[0x40 - 0x1C]; Vec pos; u8 p50[0x3A0 - 0x50];
    union { struct { u16 a:7; u16 lvl:6; u16 r:3; } h; struct { u8 a; u8 r:7; u8 b7:1; } c; } f3A0; } P;
extern s32 D_00201E80;
void sceVu0CopyVector(Vec *, Vec *);
void memset(void *, s32, s32);
s32 func_001B3240(s8 *, MtxF *, Vec *, s32, s32);
s32 func_001B2800(s8 *, MtxF *, Vec *, u16, s32, s32);
s8 *func_00169B50(s32, s32, s32, s32);
void sceVu0RotMatrixY(MtxF *, MtxF *, f32);
void func_001677C0(s8 *, MtxF *);
void func_001CA2D0(s32);
extern MtxF D_001F2170;
static inline void hit(P *p, MtxF *r, MtxF *mp) {
    s8 *o;
    if (!p->f3A0.c.b7 && p->f3A0.h.lvl > 10) {
        o = func_00169B50(0x1DD, 0, 0, 0);
        if (o != 0) {
            sceVu0RotMatrixY(mp, &D_001F2170, WRAP(*(f32 *)(p->o + 0x24)));
            sceVu0CopyVector((Vec *)mp->m[3], (Vec *)r);
            func_001677C0(o, mp);
            func_001CA2D0(0x10);
        }
    }
}

s32 func_001BE050(Actor *a) {
    P *p;
    s32 i;
    s32 j;
    s8 *n;
    s8 ***q;
    s8 ***q2;
    s32 i2;
    Vec f;
    Vec e;
    MtxF m;
    MtxF t;
    p = (P *)(a->unk518 + 0x180);
    sceVu0CopyVector(&e, &p->pos);
    e.w = 1.0f;
    sceVu0CopyVector(&f, &p->pos);
    f.w = 1.0f;
    e.y = -29000.0f;
    memset(&m, 0, 0x40);
    for (i = 0, q = (s8 ***)(&D_00201E80 + 2); i < 2; i++, q++) {
        if (*q != 0 && **q != 0 && func_001B3240(**q, &m, &e, 0x80, 1)) {
            hit(p, &m, &t);
            return 1;
        }
    }
    for (i2 = 0, q2 = (s8 ***)(&D_00201E80 + 2); i2 < 2; i2++, q2++) {
        if (*q2 != 0 && (n = **q2) != 0) {
            for (j = 0; j < *(u16 *)(n + 0x6E); j++) {
                if (!func_001B2800(n, &m, &e, j, 0x80, 1) == 0) {
                    hit(p, &m, &t);
                    return 1;
                }
            }
        }
    }
    return 0;
}
