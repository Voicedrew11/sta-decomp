#include "m2c.h"
typedef union { u32 w; u8 b[4]; } C4;
typedef struct { s32 idx; s32 id; u8 pad8[0x24]; f32 f2C; f32 f30; u8 pad34[8]; C4 c; } Item;
typedef struct { u32 n; Item *items; } List;
typedef struct { f32 t; s32 id; } Key;
typedef struct { s32 x0; s32 id; } Obj;
typedef struct { s32 res; s32 lst; s32 item; Key *keys; s32 n; f32 t; Obj *obj; void (*fn)(); } Anim;
List **func_00189050(s32);
s32 func_00189020(s32);
void func_001829B0(Item *, s32, void (*)(), Obj *);
void func_00180CA0();
static inline f32 mu(u32 x, f32 k) { f32 f = x; return f * k; }

void func_0017F990(Anim *s) {
    Item it;
    C4 c;
    List *l;
    s32 base;
    f32 t;
    s32 n;
    Key *keys;
    s32 i;
    s32 hi;
    s32 lo;
    f32 f;
    Item *pB;
    Item *pA;
    Obj *o;

    if (s == 0) return;
    l = func_00189050(s->res)[s->lst];
    base = func_00189020(s->res);
    keys = s->keys;
    t = s->t;
    n = s->n;
    if (l == 0 || base == 0 || keys == 0 || n == 0) return;
    if (t < keys[0].t) return;
    if (keys[n - 1].t < t) return;
    for (i = 0; i < n - 1; i++) {
        if (keys[i].t <= t && t <= keys[i + 1].t) {
            lo = i;
            hi = i + 1;
            break;
        }
    }
    f = (t - keys[lo].t) / (keys[hi].t - keys[lo].t);
    lo = keys[lo].id;
    hi = keys[hi].id;
    pA = 0;
    pB = 0;
    for (i = 0; i < l->n; i++) {
        if (hi == l->items[i].id) pB = &l->items[i];
        if (lo == l->items[i].id) pA = &l->items[i];
    }
    if (pB == 0 || pA == 0) return;
    o = s->obj;
    o->id = f < 0.5f ? lo : (lo = hi);
    it = l->items[s->item];
    it.f2C = pB->f2C * f + pA->f2C * (1.0f - f);
    it.f30 = pB->f30 * f + pA->f30 * (1.0f - f);
    c.b[0] = mu(pB->c.b[0], f) + mu(pA->c.b[0], (1.0f - f));
    c.b[1] = mu(pB->c.b[1], f) + mu(pA->c.b[1], (1.0f - f));
    c.b[2] = mu(pB->c.b[2], f) + mu(pA->c.b[2], (1.0f - f));
    c.b[3] = mu(pB->c.b[3], f) + mu(pA->c.b[3], (1.0f - f));
    if (c.b[0] == 0x7F) c.b[0] = 0x80;
    if (c.b[1] == 0x7F) c.b[1] = 0x80;
    if (c.b[2] == 0x7F) c.b[2] = 0x80;
    if (c.b[3] == 0x7F) c.b[3] = 0x80;
    it.c = c;
    if (s->fn == 0) {
        func_001829B0(&it, base + it.idx * 8, func_00180CA0, s->obj);
    } else {
        func_001829B0(&it, base + it.idx * 8, s->fn, s->obj);
    }
}
