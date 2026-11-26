#include "common.h"
typedef struct { u8 pad[6]; u16 m6; u8 pad8[0x38]; u8 m40[1]; } Mdl;
typedef struct { u8 pad[0xB0]; Mdl **pB0; } Sub;
typedef struct { u8 pad[0x2A]; u8 m2A; } Src;
typedef struct { u8 pad[0x4B4]; Src *m4B4[0x19]; Sub *m518; } A;
void func_001A8B10(A *a, u8 id) {
    Mdl *m;
    s32 o;
    s8 *t;
    m = *a->m518->pB0;
    t = (s8 *)m->m40;
    o = (a->m4B4[id]->m2A + 1) * 0x140;
    ((Flags8 *)(t + o))[0x1F8].f.b4 = 1;
    ((Flags8 *)(t + (m->m6 * 0x140 + 0x200) + o))[0x1F8].f.b4 = 1;
}
