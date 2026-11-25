#include "common.h"
typedef struct { f32 x, y, z; s16 rx, ry, rz; u16 sx, sy, sz; s16 x18; s16 x1A; f32 x1C; u8 pad20[2]; u8 x22; u8 pad23[0xD]; } E;
typedef struct { f32 x, y, z, w; f32 x10[3]; f32 x1C; u8 pad20[2]; u8 x22; u8 pad23[0xD]; } E2;
typedef struct { u8 pad[0x24]; Flags8 f24; } M24;
typedef struct { M24 **obj; Flags8 f; u8 pad[3]; } P8;
typedef struct { u8 pad[0x3C]; u8 x3C; } O4;
typedef struct { u8 pad[0x10]; s32 *x10; } M;
typedef struct { Vec v[8]; } V8;
typedef struct { u8 pad[0xA0]; } A0;
typedef struct { u8 pad[0x140]; } B;
typedef struct {
    s32 pad0;
    M **p4;
    s32 *x8;
    s32 *xC;
    Vec x10;
    u8 pad20[4];
    s32 x24;
    u8 pad28[0x3C];
    s32 x64;
    u8 pad68[4];
    u16 n6C, n6E, n70, n72, n74, n76, n78;
    u8 pad7A[6];
    u16 n80;
    u8 pad82[0xA];
    s16 x8C;
    s16 x8E;
    u8 pad90[0x24];
    u8 xB4[0x80];
    E *x134;
    u8 pad138[0xC];
    V8 *x144;
    E2 *x148;
    u8 pad14C[0x2C];
    P8 *x178;
    u8 pad17C[0xC];
    A0 *x188;
    s32 *x18C;
    u8 pad190[0x48];
    Flags8 f1D8;
} S;
extern s32 D_00201F2C;
extern s32 D_002022C4;
extern s32 D_002022D0;
extern Mtx D_001F2170;
extern Vec D_003139A0;
s32 func_001B6190(S *, s32, s32);
void func_00169D70(s32 *, void *, s32);
s32 *func_001288C0(s32, s32);
void func_00123C40(void *, s32, s32);
void func_001B4F20(S *);
M24 **func_00174230(s32, M **, s32, s32);
void func_00102A60(void *, void *);
void func_001029D0(void *, void *, void *);
u8 *func_001715B0(M24 **);
void func_00102A70(void *, void *);
void func_00173FD0(void *, f32 *, f32 *, f32 *);
void func_00171540(M24 *, Mtx *);
void func_001B6130(S *);
void func_001BB8A0(s32, S *, s32);
void func_001B5FB0(S *, s32);
void func_001B5CA0(S *);
s32 func_0015DBF0(u8, f32 *, void *, f32, f32);
void func_0015CD30(A0 *, Vec *, Vec *, Vec *, Vec *, Vec *, Vec *, Vec *, Vec *, Vec *, Vec *);
void func_00166F90(s32 *, s32, s32, s32);
void func_00166F80(s32, s32, s32);
static inline f32 u2f(u32 x) { return x; }

void func_001B6800(S *a, s32 a1) {
    f32 v[4];
    f32 w[4];
    f32 pos[4];
    f32 rot[4];
    f32 scl[4];
    f32 pos2[4];
    f32 rot2[4];
    f32 scl2[4];
    s32 r;
    s32 sz;
    s32 saved;
    s32 j;
    s32 i;
    s32 k;
    u8 *m;
    u8 *b;
    E *e;
    s32 *o;
    E2 *f;

    r = func_001B6190(a, *(*a->p4)->x10, *(*a->p4)->x10);
    func_00169D70((*a->p4)->x10, a->xB4, 0x20);
    sz = ((a->n6C + a->n70 + a->n72) * 8 + 15) & ~15; sz = (sz + a->n6E * 0x80 + 15) & ~15;
    sz += a->n74 * 0xA0;
    sz += a->n80 * 0x10 + (a->n76 * 4 + a->n78 * 8);
    a->x8 = func_001288C0(D_002022C4, sz);
    func_00123C40((void *)*a->x8, 0, sz);
    func_001B4F20(a);
    saved = D_00201F2C;
    a->x178[0].obj = func_00174230(D_002022D0, a->p4, -1, a->n6C);
    func_00102A60((u8 *)*a->x178[0].obj + 0x30, &a->x10);
    (*a->x178[0].obj)->f24.f.b2 = 0;
    j = 0;
    do {
        D_00201F2C = j;
        m = func_001715B0(a->x178[0].obj);
        func_00102A70(m + 0x140, &D_001F2170);
        func_00102A70(m + 0xC0, &D_001F2170);
        m[0x1F0] = 0xFF;
        *(s32 *)m = ((O4 *)*a->p4)->x3C & 7;
        *(s32 *)(m + 4) = 0;
        for (i = 0; i < a->n6C; i++) {
            e = &a->x134[i];
            for (k = 0; k < 3; k++) {
                pos[k] = (&e->x)[k];
                rot[k] = 0.00024414062f * (&e->rx)[k];
                scl[k] = 0.00024414062f * u2f((&e->sx)[k]);
            }
            pos[3] = 1.0f;
            rot[3] = 0.0f;
            scl[3] = 1.0f;
            b = (u8 *)&((B *)m)[i + 1];
            func_00173FD0(b + 0x140, pos, rot, scl);
            e = &a->x134[i];
            for (k = 0; k < 3; k++) {
                pos2[k] = (&e->x)[k];
                rot2[k] = 0.00024414062f * (&e->rx)[k];
                scl2[k] = 0.00024414062f * u2f((&e->sx)[k]);
            }
            pos2[3] = 1.0f;
            rot2[3] = 0.0f;
            scl2[3] = 1.0f;
            func_00173FD0(b + 0xC0, pos2, rot2, scl2);
            if (a->x134[i].x18 == -1) m[i * 0x140 + 0x330] = 0xFF; else m[i * 0x140 + 0x330] = a->x134[i].x18;
            if (a->x134[i].x1A == -1) m[i * 0x140 + 0x332] = 0xFF; else m[i * 0x140 + 0x332] = a->x134[i].x1A;
            m[i * 0x140 + 0x331] = 0;
        }
        func_00171540(*a->x178[0].obj, &D_001F2170);
        j++;
    } while (j < 2);
    for (k = 0; k < a->n6C; k++) {
        P8 *p = &a->x178[k];
        p->f.f.b0 = 1;
        p->f.f.b1 = 0;
    }
    func_001B6130(a);
    func_001BB8A0(D_002022D0, a, r);
    func_001B5FB0(a, a1);
    func_001B5CA0(a);
    func_00102A60(v, &a->x10);
    for (i = 0; i < a->n76; i++) {
        f = &a->x148[i];
        o = &a->x18C[i];
        func_00102A60(w, f);
        func_001029D0(w, w, v);
        w[3] = f->w;
        *o = func_0015DBF0(f->x22, w, f->x10, w[3], f->x1C);
    }
    for (i = 0; i < a->n74; i++) {
        V8 *q = &a->x144[i];
        func_0015CD30(&a->x188[i], &q->v[0], &q->v[2], &D_003139A0, &D_003139A0, &q->v[1], &q->v[3], &D_003139A0, &D_003139A0, &q->v[5], &q->v[4]);
    }
    if (a->x64) {
        a->xC = func_001288C0(D_002022C4, 0x963C);
        func_00166F90(a->xC, a->x24, a->x64, 0x3F);
        func_00166F80(*a->xC, 0x7FFF, 0);
    }
    D_00201F2C = saved;
    a->f1D8.f.b0 = 1;
    a->x8C = 0;
    a->x8E = -2;
}
