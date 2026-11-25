#include "m2c.h"
typedef struct { s8 pad[0x1C]; u16 key; s8 pad2[0x12]; } Ent;
typedef struct { s32 id; s8 pad[0xA8]; Ent *cur; s8 pad1[0x134 - 0xB0]; Ent *ents; } Obj;
extern Obj **D_002022BC;

static inline s32 idx(s32 *out) {
    Obj *o;
    if (D_002022BC != NULL) {
        o = *D_002022BC;
        if (D_002022BC == NULL) {
            if (out) *out = -1;
            return -1;
        }
        if (out) *out = o->id;
        if (o->cur) return o->cur - o->ents;
        return -1;
    }
    return -1;
}

s32 func_001B17E0(s32 *out) {
    Obj *o;
    s32 i;
    if (D_002022BC != NULL) {
        o = *D_002022BC;
    } else {
        return -1;
    }
    i = idx(out);
    if (i == -1) {
        return -1;
    } else {
        return o->ents[i].key;
    }
}
