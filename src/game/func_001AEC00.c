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
    s16 pad9e[4];
    s8 fA6;
    s8 fA7;
    u8 a0:1;
    u8 a1:1;
    u8 a2:4;
    u8 a6:1;
    u8 a7:1;
    u8 c0:1;
    u8 c1:1;
    u8 c2:6;
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
extern s32 D_002022BC;
extern s16 D_004AC5A4[];
extern Obj *D_004AC5A8[][16];
extern Vec D_001F3820;
Obj *func_001AE360(s16, u8);
void func_00102A60(Vec *, Vec *);
void func_00173FD0(void *, Vec *, Vec *, Vec *);
void func_001027E0(void *, void *, Mtx *);
void func_001029D0(Vec *, Vec *, Vec *);
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
        func_001027E0(o, o, &m);
    }
    func_001029D0(&o->pos, &o->pos, &o->d);
}

Obj *func_001AEC00(s32 arg0, s16 id, Vec *a, Vec *b, Vec *d) {
    Ent *ents;
    s32 side;
    Obj *o;
    s32 k;
    Vec c;
    ents = D_002022B0;
    c = D_001F3820;
    side = -1;
    if ((&D_00201E80)[2] == D_002022BC) side = 0;
    if ((&D_00201E80)[3] == D_002022BC) side = 1;
    k = !side;
    o = func_001AE360(id, k);
    if (o == NULL) return NULL;
    o->f9C = id;
    o->fAA = 0;
    o->fAE = -1;
    o->fA6 = 0x19;
    o->fA7 = -1;
    o->fAC = 0;
    o->a0 = 0;
    o->a1 = 0;
    o->a6 = 0;
    o->f80 = ents[id].f10;
    o->f8C = arg0;
    o->fB4 = 1.0f;
    func_00102A60(&o->a, a);
    func_00102A60(&o->b, b);
    func_00102A60(&o->c, &c);
    func_00102A60(&o->d, d);
    update(o);
    D_004AC5A8[k][D_004AC5A4[k]++] = o;
    if (D_00202288 == NULL) D_00202288 = o;
    return o;
}
