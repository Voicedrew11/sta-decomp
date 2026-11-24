#include "m2c.h"
typedef struct { f32 x, y, z, w; } Vec;
typedef struct { Vec m[4]; } __attribute__((aligned(16))) Mtx;
typedef struct {
    u8 pad[0x10];
    s32 f10;
    u8 pad2[0x60 - 0x14];
    Vec a, b, c;
} Ent;
typedef struct {
    u8 pad[0x18];
    s32 f18;
    u16 f1C;
    u16 pad1e;
    u8 b0:1;
    u8 b1:1;
    u8 b2:6;
    u8 pad21;
    u16 f22;
} Src;
typedef struct {
    Vec m[3];       /* 0x00 */
    Vec pos;        /* 0x30 */
    Vec a, b, c;    /* 0x40 0x50 0x60 */
    Vec d;          /* 0x70 */
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
    u8 a2:6;
    u8 c0:1;
    u8 c1:1;
    u8 c2:6;
    u16 fAA;
    s16 fAC;
    u16 fAE;
    s32 padB0;
    f32 fB4;
    u8 padB8[0xD0 - 0xB8];
} Obj;
typedef struct { s32 pad[2]; s32 f8; s32 fC; } G;
extern s32 D_00201E80;
extern Obj *D_00202288;
extern Ent *D_002022B0;
extern s32 D_002022BC;
extern s16 D_004AC5A0[];
extern Obj D_004AE370[][64];
void func_001AF4A0(Obj *);
void func_001B59E0(Src *, Vec *, Vec *, Vec *);
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

Obj *func_001AF150(s32 arg0, Src *arg1, u16 arg2, Vec *arg3) {
    Ent *ents;
    s32 side;
    s32 k;
    Obj *o;
    ents = D_002022B0;
    side = -1;
    if ((&D_00201E80)[2] == D_002022BC) side = 0;
    if ((&D_00201E80)[3] == D_002022BC) side = 1;
    k = !side;
    if (arg2 >= 0x40) return NULL;
    if (arg2 >= D_004AC5A0[k]) D_004AC5A0[k] = arg2 + 1;
    o = &D_004AE370[k][arg2];
    if (o->f9C != -1) func_001AF4A0(o);
    o->f9C = arg1->f18;
    o->fAA = arg1->f1C;
    o->fAE = arg1->f22;
    o->fA6 = 0x19;
    o->fA7 = -1;
    o->fAC = arg2;
    o->a0 = 0;
    o->a1 = 0;
    o->c1 = arg1->b1;
    o->f80 = ents[arg1->f18].f10;
    o->f8C = arg0;
    o->fB4 = 1.0f;
    func_001B59E0(arg1, &o->a, &o->b, &o->c);
    func_00102A60(&o->d, arg3);
    update(o);
    if (D_00202288 == NULL) D_00202288 = o;
    return o;
}
