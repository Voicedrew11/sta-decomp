#include "m2c.h"
typedef struct { s8 pad[0x1A]; u16 x1A; s8 pad2[0x10]; } Ent;
typedef struct { s32 a; u8 b0:1; u8 b1:1; } Slot;
typedef struct {
    s32 id;
    s8 pad4[0x74];
    u16 n;
    s8 pad7A[0xD6];
    Ent *ents;
    s8 pad154[0x3C];
    Slot *x190;
    s8 pad194[0x44];
    u8 x1D8;
} Chr;
void func_00167640(s32, s32);
extern s32 D_00201E80;
#define C (((Chr ***)&D_00201E80)[2])
#define D (((Chr ***)&D_00201E80)[3])
static inline s32 ok(Chr **p) {
    s32 r;
    if (p != 0) {
        r = ((*p)->x1D8 & 1) != 0;
    } else {
        r = 0;
    }
    return r;
}
static inline Chr *find(s32 id) {
    Chr **c = C;
    Chr *r = 0;
    if (ok(c) && (*c)->id == id) r = *c;
    if (ok(c = D) && (*c)->id == id) r = *c;
    return r;
}
static inline s32 lookup(Chr *c, s32 key) {
    s32 i;
    if (c == 0) {
        return -1;
    }
    for (i = 0; i < c->n; i++) {
        if (key == c->ents[i].x1A % 100) {
            return i;
        }
    }
    return -1;
}

void func_001B11F0(s32 id, s32 key, s32 a2) {
    s32 idx;
    Chr *t;
    t = find(id);
    idx = lookup(find(id), key);
    if (t != 0 && idx != -1) {
        Slot *s = &t->x190[idx];
        s->b1 = 1;
        func_00167640(s->a, a2);
    }
}
