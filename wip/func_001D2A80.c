#include "common.h"
typedef struct { u8 pad[0xC]; union { s32 w; Flags8 f; } c; } Ent;
typedef struct { u8 pad[4]; u8 b4, b5, b6; } T;
typedef struct { u8 pad[0x90]; T **x90; u16 x94; } O;

static inline u8 bits(Ent *e) {
    u8 m = 0;
    if (e->c.w == 0) {
        return 0;
    }
    if (e->c.f.f.b0) m |= 1;
    if (e->c.f.f.b1) m |= 2;
    if (e->c.f.f.b2) m |= 4;
    if (e->c.f.f.b3) m |= 8;
    return m;
}

u8 func_001D2A80(O *o) {
    u8 r;
    s32 i;
    T *t;
    Ent *e;

    r = 0;
    t = o->x90[o->x94 + 0x84];
    e = (Ent *)(t->b6 * 12 + (t->b5 * 4 + (t->b4 * 20 + (s32)t)) + 0x108);
    for (i = 0; i < 4; i++) {
        r |= bits(&e[i]);
    }
    return r;
}
