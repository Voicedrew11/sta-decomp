#include "common.h"
typedef struct { u8 pad[0x10]; u8 (**tbl)[16]; u16 n14; u16 n16; } Q;
typedef struct { Q *q; } R;
typedef struct { R *r; } Anim;
typedef struct { Anim *a; } M84;
typedef struct {
    u8 pad[0x84];
    M84 *x84;
    u8 pad88[8];
    s32 x90;
    u8 pad94[0x14];
    Flags8 xA8;
} Node;
void func_001710D0(Anim *, s16, f32, f32, f32);
static inline u8 get(Node *o, s32 a1) {
    if (o->x90 != 0) {
        return a1;
    }
    return (*o->x84->a->r->q->tbl)[o->x90][a1];
}

void func_001AD1C0(Node *o, s32 a1) {
    s32 v;
    Anim *a;

    if (o != NULL && o->xA8.f.b0) {
        v = get(o, a1);
        a = o->x84->a;
        if (a->r->q->n16 != 0) {
            func_001710D0(a, v, 1.0f, 0.0f, 0.0f);
            o->xA8.f.b3 = 0;
            o->xA8.f.b4 = 1;
            o->xA8.f.b5 = 0;
        }
    }
}
