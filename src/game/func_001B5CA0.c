#include "m2c.h"
typedef struct { u8 b0:1; u8 b1:1; u8 b2:1; } F;
typedef struct { u8 pad[0x10]; s32 x10; } M;
typedef struct { M *m; } O;
typedef struct { f32 x, y, z; s16 rx, ry, rz; u16 sx, sy, sz; u16 id; u8 pad1A[0x10]; F f; u8 pad2B; } E;
typedef struct { s8 *obj; F f; } P8;
typedef struct {
    s32 pad0;
    O *o;
    u8 pad8[8];
    f32 x10[4];
    u8 pad20[0x58];
    u16 n78;
    u8 pad7A[0x3A];
    u8 xB4[0x9C];
    E *x150;
    u8 pad154[0x3C];
    P8 *x190;
} S;
void func_00102A60(f32 *, f32 *);
void func_001029D0(f32 *, f32 *, f32 *);
s32 func_00169BB0(s32);
s8 *func_00169B50(s32, s32, s32, s32);
s8 *func_00169BD0(s32, s32, void *, s32, s32, s32);
void func_00173FD0(void *, f32 *, f32 *, f32 *);
void func_00167740(s8 *, void *);
static inline f32 u2f(u32 x) { return x; }

void func_001B5CA0(S *s) {
    f32 v[4];
    f32 mat[4][4];
    f32 pos[4];
    f32 rot[4];
    f32 scl[4];
    u32 i;
    s32 k;
    E *e;
    P8 *p;

    func_00102A60(v, s->x10);
    for (i = 0; i < s->n78; i++) {
        e = &s->x150[i];
        p = &s->x190[i];
        if (func_00169BB0(e->id)) {
            p->obj = func_00169B50(e->id, e->f.b0, e->f.b1, e->f.b2);
            p->f.b0 = 1;
        } else {
            p->obj = func_00169BD0(e->id, s->o->m->x10, s->xB4, e->f.b0, e->f.b1, e->f.b2);
            p->f.b0 = 0;
        }
        if (e->f.b0) {
            p->f.b1 = 1;
        }
        if (p->obj) {
            for (k = 0; k < 3; k++) {
                pos[k] = (&e->x)[k];
                rot[k] = 0.00024414062f * (&e->rx)[k];
                scl[k] = 0.00024414062f * u2f((&e->sx)[k]);
            }
            pos[3] = 1.0f;
            rot[3] = 0.0f;
            scl[3] = 1.0f;
            func_00173FD0(mat, pos, rot, scl);
            func_001029D0(mat[3], mat[3], v);
            func_00167740(p->obj, mat);
        }
    }
}
