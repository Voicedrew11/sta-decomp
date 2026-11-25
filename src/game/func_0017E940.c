#include "m2c.h"
typedef struct { s8 pad[0x1A]; u16 x1A; s8 pad2[0x10]; } Ent;
typedef struct {
    s32 id;
    s8 pad4[0x74];
    u16 n;
    s8 pad7A[0xD6];
    Ent *ents;
    s8 pad154[0x3C];
    s32 *x190;
    s8 pad194[0x44];
    u8 x1D8;
} Chr;
typedef struct { s32 p0; s32 p4; s32 id; s32 pC; s32 key; s32 p14; f32 x18; } Arg;
void func_00167270(f32, s32, Chr *, s32);
extern s32 D_00201E80;
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
    Chr *r = 0;
    if (ok(((Chr ***)&D_00201E80)[2]) && (*((Chr ***)&D_00201E80)[2])->id == id) {
        r = *((Chr ***)&D_00201E80)[2];
    }
    if (ok(((Chr ***)&D_00201E80)[3]) && (*((Chr ***)&D_00201E80)[3])->id == id) {
        r = *((Chr ***)&D_00201E80)[3];
    }
    return r;
}
static inline s32 lookup(Chr *c, s32 key) {
    s32 i;
    Ent *e;
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

void func_0017E940(Arg *a) {
    f32 fl = a->x18;
    s32 id = a->id;
    s32 key = a->key;
    Chr *t = find(id);
    s32 idx = lookup(find(id), key);

    if (t != 0 && idx != -1) {
        func_00167270(fl, t->x190[idx * 2], t, key);
    }
}
