#include "common.h"
typedef struct { s32 x0; s32 pad[9]; s32 x28; } Sub;
typedef struct { u8 pad[8]; Sub s; u8 rest[0x310 - 8 - 0x2C]; } E;
extern E D_00437DC0[];
static inline Sub *find(s32 id) {
    s32 i;
    E *e = D_00437DC0;
    Sub *s;
    for (i = 0; i < 4; i++, e++) {
        s = &e->s;
        if (s->x0 == id) return s;
    }
    return NULL;
}
s32 func_00175850(s32 id) {
    Sub *s = find(id);
    return s ? s->x28 : 0;
}
