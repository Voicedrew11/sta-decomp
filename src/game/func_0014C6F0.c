#include "actor.h"
typedef struct { u8 pad[0x2A]; u16 f; u8 pad2C[0x80]; f32 xAC; } P;
typedef struct { u8 pad[0x210]; P *tbl[1]; } Q;
typedef struct {
    u8 pad0[0x4C];
    f32 x4C;
    u8 pad50[0x10];
    f32 x60;
    f32 x64;
    f32 x68;
    f32 x6C;
    u8 pad70[0x20];
    Q *x90;
    u16 x94;
    u8 pad96[0x7E];
    u8 b0:1;
    u8 b1:1;
    u8 b2:1;
    u8 b3:1;
    u8 b4:1;
    u8 b5:1;
} O;
typedef struct { u8 pad[0x30]; f32 v[4]; } M;
void sceVu0CopyVector(void *, void *);
void func_00163C80(O *, M *);
f32 func_00146940(f32 *, s8 *);
extern s8 D_001F2160[];
inline s32 has(void) {
    return D_002022E4 != NULL && D_002022E4->unk518 != NULL;
}

void func_0014C6F0(O *o) {
    f32 a, b, c, d;
    f32 pos[4];
    M m;
    f32 t;
    P *p;

    a = o->x60;
    b = o->x64;
    c = o->x68;
    d = o->x6C;
    if (o->b5) {
        func_00163C80(o, &m);
        sceVu0CopyVector(pos, m.v);
    } else {
        sceVu0CopyVector(pos, o);
    }
    t = func_00146940(pos, has() ? D_002022E4->unk518 + 0x1C0 : D_001F2160);
    if (c < t) {
        a = a;
    } else if (t < d) {
        a = b;
    } else {
        a = b + (a - b) * (t - d) / (c - d);
    }
    p = o->x90->tbl[o->x94];
    if (p->f & 0x10) {
        o->x4C = o->x4C * a;
    } else {
        o->x4C = a * p->xAC;
    }
    if (127.0f < o->x4C) {
        o->x4C = 127.0f;
    }
}
