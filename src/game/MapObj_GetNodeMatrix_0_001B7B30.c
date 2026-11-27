#include "common.h"
typedef struct { s8 pad[0x1A]; u16 x1A; s8 pad2[0x14]; } Ent;
typedef struct {
    s8 pad[0x6E];
    u16 n;
    s8 pad70[0xC8];
    Ent *ents;
    s8 pad13C[0x44];
    s8 *x180;
} Chr;
Chr *MapObj_Find_1_001B19A0(s32);
void sceVu0CopyMatrix(void *, void *);
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

void MapObj_GetNodeMatrix_0_001B7B30(s32 id, s32 key, void *out) {
    Chr *t = MapObj_Find_1_001B19A0(id);
    u32 idx = lookup(MapObj_Find_1_001B19A0(id), key);
    if (t != 0 && idx < t->n) {
        sceVu0CopyMatrix(out, t->x180 + idx * 0x80);
    }
}
