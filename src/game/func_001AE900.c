#include "m2c.h"
typedef struct { f32 v[4]; } __attribute__((aligned(16))) Vec;
typedef struct { Vec m[4]; } Mtx;
typedef struct { u8 pad[0x10]; s32 x10; u8 pad14[0x4C]; Vec a; Vec b; Vec c; } Ent;
typedef struct {
    u8 b0:1;
    u8 b1:1;
    u8 b2:4;
    u8 b6:1;
    u8 b7:1;
} BF;
typedef struct {
    Mtx m;          /* 0x00 */
    Vec v40, v50, v60, v70; /* 0x40..0x7F */
    s32 x80;
    u8 pad84[8];
    s32 *x8C;
    u8 pad90[0xC];
    s16 idx;        /* 0x9C */
    u8 pad9E[8];
    s8 xA6;
    s8 xA7;
    BF xA8;
    u8 fA9;
    s16 xAA;
    s16 xAC;
    s16 xAE;
    f32 xB0;
    f32 xB4;
} Node;
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
void sceVu0MulMatrix(void *, void *, void *);
void sceVu0AddVector(void *, void *, void *);
void sceVu0SubVector(void *, void *, void *);
void sceVu0CopyVector(Vec *, Vec *);
void func_00173FD0(void *, Vec *, Vec *, Vec *);
void func_001B51E0(s32, Vec *);
void *func_001AE360(s16, u8);
s32 func_001AE250(s32 *, Vec *, f32 *);
void func_001AE510(void);
extern Ent *D_002022B0;
extern s32 D_00201E80;
extern Node *D_00202288;
extern Vec D_001F3820;
extern Vec D_001F3830;
extern s32 D_002022BC;
extern s16 D_004AC5A4[];
extern Node *D_004AC5A8[][16];
static inline void upd(Node *n) {
    Ent *tbl = D_002022B0;
    if (n != NULL && n->idx != -1) {
        if (((u64)((s64)n->fA9 << 0x3E) >> 0x3F) != 0) {
            func_00173FD0(n, &n->v40, &n->v50, &n->v60);
        } else {
            Mtx tmp;
            Ent *e = &tbl[n->idx];
            func_00173FD0(&tmp, &e->a, &e->b, &e->c);
            func_00173FD0(n, &n->v40, &n->v50, &n->v60);
            sceVu0MulMatrix(n, n, &tmp);
        }
        sceVu0AddVector(&n->m.m[3], &n->m.m[3], &n->v70);
    }
}

Node *func_001AE900(s32 *owner, s16 id, Vec *a, Vec *b, s32 ground, s32 rel) {
    Vec c;
    Ent *t;
    Node *s;
    s32 side;

    t = D_002022B0;
    c = D_001F3830;
    side = -1;
    if (((s32 **)&D_00201E80)[2] == owner) {
        side = 0;
    }
    if (((s32 **)&D_00201E80)[3] == owner) {
        side = 1;
    }
    s = func_001AE360(id, side);
    if (s == 0) {
        return 0;
    }
    s->idx = id;
    s->xAA = 0;
    s->xAE = -1;
    s->xA6 = 0x19;
    s->xA7 = -1;
    s->xAC = 0;
    s->xA8.b0 = 0;
    s->xA8.b1 = 0;
    s->xA8.b6 = ground;
    s->x80 = t[id].x10;
    s->x8C = owner;
    s->xB4 = 1.0f;
    sceVu0CopyVector(&s->v40, a);
    sceVu0CopyVector(&s->v50, b);
    s->v50.v[2] = 0.0f;
    s->v50.v[0] = 0.0f;
    sceVu0CopyVector(&s->v60, &c);
    if (owner != 0) {
        func_001B51E0(*owner, &s->v70);
        if (rel != 0) {
            sceVu0SubVector(&s->v40, &s->v40, &s->v70);
        }
    }
    upd(s);
    if (ground != 0) {
        if (func_001AE250(owner, &s->m.m[3], &s->xB0) == 0) {
            s->idx = -1;
            *(s16 *)&s->xA8 = 0;
            s->x80 = 0;
            s->x8C = 0;
            return 0;
        }
        s->xB0 -= s->v70.v[1];
    }
    D_004AC5A8[side][D_004AC5A4[side]++] = s;
    func_001AE510();
    if (D_00202288 == 0) {
        D_00202288 = s;
    }
    return s;
}

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
    o->f80 = ents[id].x10;
    o->f8C = arg0;
    o->fB4 = 1.0f;
    sceVu0CopyVector(&o->a, a);
    sceVu0CopyVector(&o->b, b);
    sceVu0CopyVector(&o->c, &c);
    sceVu0CopyVector(&o->d, d);
    update(o);
    D_004AC5A8[k][D_004AC5A4[k]++] = o;
    if (D_00202288 == NULL) D_00202288 = o;
    return o;
}
