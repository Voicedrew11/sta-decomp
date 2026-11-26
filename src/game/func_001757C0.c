#include "common.h"
typedef struct { f32 x; f32 y; u8 pad[0x24]; } V;
typedef struct { s32 id; u8 pad[0x1B4]; V v[8]; } S;
typedef struct { u8 pad[8]; S s; u8 pad2[0x310 - 8 - sizeof(S)]; } E;
extern E D_00437DC0[];
static inline S *find(s32 id) {
    s32 i;
    E *e;
    S *s;
    i = 0;
    e = D_00437DC0;
    for (; i < 4; i++, e++) {
        s = &e->s;
        if (s->id == id) return s;
    }
    return NULL;
}
void func_001757C0(s32 id, s32 k, f32 x, f32 y) {
    S *s;
    if (k < 0 || k >= 8) return;
    s = find(id);
    if (s != NULL) {
        s->v[k].x = x;
        s->v[k].y = y;
    }
}

