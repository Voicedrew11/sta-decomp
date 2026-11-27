#include "m2c.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) Vec;
typedef struct { Vec m[4]; } __attribute__((aligned(16))) Mtx;
typedef struct {
    u8 pad[0x10];
    s32 f10;
    u8 pad2[0x60 - 0x14];
    Vec a, b, c;
} Ent;
typedef struct {
    Vec m[3];
    Vec pos;
    Vec a, b, c;
    Vec d;
    s32 f80;
    s32 pad84[2];
    s32 f8C;
    s32 pad90[3];
    s16 f9C;
    s16 pad9e[3];
    s8 fA4;
    s8 padA5;
    s8 fA6;
    s8 fA7;
    u8 a0:1;
    u8 a1:1;
    u8 a2:4;
    u8 a6:1;
    u8 a7:1;
    u8 c0:1;
    u8 c1:1;
    u8 c2:1;
    u8 c3:5;
    u16 fAA;
    s16 fAC;
    s16 fAE;
    s32 padB0;
    f32 fB4;
    u8 padB8[0xD0 - 0xB8];
} Obj;
extern s32 D_00201E80;
extern Obj *D_00202288;
extern Ent *D_002022B0;
extern s16 D_004AC5A0[];
extern Obj D_004AE370[2][64];
#pragma explicit_zero_data on
Vec D_001F3810 = { 1.0f, 1.0f, 1.0f, 1.0f };
void func_001AF4A0(Obj *);
void func_001B51E0(s32, Vec *);
void sceVu0CopyVector(Vec *, Vec *);
void func_00173FD0(void *, Vec *, Vec *, Vec *);
void sceVu0MulMatrix(void *, void *, Mtx *);
void sceVu0AddVector(Vec *, Vec *, Vec *);
static inline void update(Obj *o) {
    Mtx m;
    Ent *e;
    Ent *ents = D_002022B0;
    if (o == NULL) return;
    if (o->f9C == -1) return;
    if (o->c1) {
        func_00173FD0(o, &o->a, &o->b, &o->c);
    } else {
        e = &ents[o->f9C];
        func_00173FD0(&m, &e->a, &e->b, &e->c);
        func_00173FD0(o, &o->a, &o->b, &o->c);
        sceVu0MulMatrix(o, o, &m);
    }
    sceVu0AddVector(&o->pos, &o->pos, &o->d);
}

Obj *func_001AEE80(s32 *arg0, s16 id, Vec *a, Vec *b, s16 arg4) {
    Ent *ents;
    s32 side;
    Obj *o;
    s16 *cnt;
    Vec c;
    ents = D_002022B0;
    c = D_001F3810;
    side = -1;
    if ((&D_00201E80)[2] == (s32)arg0) side = 0;
    if ((&D_00201E80)[3] == (s32)arg0) side = 1;
    cnt = &D_004AC5A0[side];
    if (!(*(volatile s16 *)cnt < 0x40)) return NULL;
    o = &D_004AE370[side][*(volatile s16 *)cnt];
    if (o->f9C != -1) func_001AF4A0(o);
    o->f9C = id;
    o->fAA = 0;
    o->fAE = -1;
    o->fA6 = 0x19;
    o->fA7 = -1;
    o->fAC = arg4;
    o->a0 = 0;
    o->a1 = 0;
    o->c2 = 1;
    o->f80 = ents[id].f10;
    o->f8C = (s32)arg0;
    o->fB4 = 1.0f;
    o->fA4 = 0x2D;
    sceVu0CopyVector(&o->a, a);
    sceVu0CopyVector(&o->b, b);
    o->b.z = 0.0f;
    o->b.x = 0.0f;
    sceVu0CopyVector(&o->c, &c);
    if (arg0 != NULL) func_001B51E0(*arg0, &o->d);
    update(o);
    (*cnt)++;
    if (D_00202288 == NULL) D_00202288 = o;
    return o;
}
