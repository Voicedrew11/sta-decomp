#include "common.h"
typedef struct { u8 pad[0x14]; u16 n14; u16 n16; } Q;
typedef struct { Q *q; } R;
typedef struct { R *r; u8 pad4[4]; u16 id; u8 padA[2]; f32 x; f32 y; f32 spd; } Anim;
typedef struct { u8 pad[0x52]; s8 x52; u8 pad53[9]; s8 x5C[2][2]; u8 pad60[0x30]; } Ent;
typedef struct { Anim *a; } M84;
typedef struct {
    Mtx m;
    Vec v40, v50, v60, v70;
    s32 x80;
    M84 *x84;
    s8 *x88;
    u8 pad8C[0x10];
    s16 idx;
    u8 pad9E[2];
    f32 xA0;
    u8 xA4;
    u8 padA5[3];
    Flags8 xA8;
    Flags8 xA9;
    u8 padAA[6];
    f32 xB0;
    u8 padB4[4];
    s32 xB8;
    s32 xBC;
    s32 xC0[2][2];
} Node;
void sceVu0MulMatrix(void *, void *, void *);
void sceVu0AddVector(void *, void *, void *);
void sceVu0CopyVector(Vec *, void *);
void func_00173FD0(void *, Vec *, Vec *, Vec *);
f32 func_00173F70(Q *, u16);
void func_00171B70(Anim *, u16, f32);
void func_00171540(Anim *, Node *);
void func_001717A0(Anim *, u16, f32, f32, void *);
void func_001AD2C0();
s8 *func_001715B0(M84 *);
void func_001502A0(Vec *, Vec *, Vec *, f32);
void func_00167670(s32, Vec *);
void func_001677C0(s32, void *);
extern Ent *D_002022B0;
extern Node *D_002022A4;
static inline void upd(Node *n) {
    Ent *tbl = D_002022B0;
    if (n != NULL && n->idx != -1) {
        if (n->xA9.f.b1) {
            func_00173FD0(n, &n->v40, &n->v50, &n->v60);
        } else {
            Mtx tmp;
            Ent *e = &tbl[n->idx];
            func_00173FD0(&tmp, (Vec *)((s8 *)e + 0x60), (Vec *)((s8 *)e + 0x70), (Vec *)((s8 *)e + 0x80));
            func_00173FD0(n, &n->v40, &n->v50, &n->v60);
            sceVu0MulMatrix(n, n, &tmp);
        }
        sceVu0AddVector(&n->m.m[3], &n->m.m[3], &n->v70);
    }
}
static inline Ent *ent(s16 i) {
    if (D_002022B0 != NULL && i > 0 && i < 0x400) return &D_002022B0[i];
    return NULL;
}

void func_001AD4E0(Node *o0, f32 dt) {
    s32 i;
    Anim *a;
    Node *o;
    Ent *en;
    R *r;
    s32 played;
    Vec e[2];
    Vec d;
    Vec c;
    f32 len;
    s8 *s;

    o = o0;
    played = 0;
    if (o->idx == -1) return;
    if (!o->xA8.f.b0) return;
    a = o->x84->a;
    r = a->r;
    if (r == NULL || r->q == NULL) return;
    if (o->xA4) o->xA4--;
    en = ent(o->idx);
    if (r->q->n16 != 0 && (o->xA8.f.b3 || o->xA8.f.b4)) {
        len = func_00173F70(r->q, a->id);
        a->y = a->x;
        if (!o->xA8.f.b5) a->x = a->x + dt * a->spd;
        played = 1;
        if (o->xA8.f.b3) {
            if (a->x > len) a->x = a->x - len;
        } else {
            if (o->xA8.f.b5) o->xA8.f.b4 = 0;
            if (a->x > len) {
                a->x = len;
                o->xA8.f.b5 = 1;
            }
        }
        func_00171B70(a, a->id, a->x);
    }
    if (o->xA8.f.b6) {
        o->xA0 += 50.0f * dt;
        o->v40.y = o->v40.y + o->xA0;
        if (o->v40.y > o->xB0) {
            o->v40.y = o->xB0 - 1.0f;
            o->xA8.f.b6 = 0;
        }
        if (o->v40.y > 29000.0f) {
            o->v40.y = 29000.0f;
            o->xA8.f.b6 = 0;
        }
        upd(o);
    }
    if (!o->xA9.f.b0) func_00171540(o->x84->a, o);
    if (played && o->xA8.f.b7) {
        D_002022A4 = o;
        func_001717A0(a, a->id, a->x, a->y, func_001AD2C0);
    }
    if (o->xB8) {
        if (o->x88) {
            sceVu0CopyVector(&d, o->x88 + 0x60);
            sceVu0CopyVector(&c, o->x88 + 0x70);
            func_001502A0(e, &d, &c, d.w);
            func_00167670(o->xB8, e);
        }
        func_001677C0(o->xB8, o);
    }
    if (o->xBC) {
        if (en->x52 > -1 && en->x52 < r->q->n14) {
            s = func_001715B0(o->x84);
            func_001677C0(o->xBC, s + (en->x52 + 1) * 0x140 + 0xC0);
        } else {
            func_001677C0(o->xBC, o);
        }
    }
    for (i = 0; i < 4; i++) {
        s8 *k;
        s32 h = i / 2;
        s32 l = i % 2;
        s32 *p = &o->xC0[h][l];
        if (*p) {
            k = &en->x5C[h][l];
            if (*k > -1 && *k < r->q->n14) {
                s = func_001715B0(o->x84);
                func_001677C0(*p, s + (*k + 1) * 0x140 + 0xC0);
            } else {
                func_001677C0(*p, o);
            }
        }
    }
}
