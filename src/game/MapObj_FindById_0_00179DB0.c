#include "common.h"
typedef struct { s16 id; s16 pad; s32 off; } Ent;
typedef struct { u8 pad[6]; s16 n; u8 pad8[8]; Ent e[1]; } Tbl;
typedef struct { s32 id; u8 pad[0x160]; Tbl *x164; } Mdl;
extern Mdl **D_00201E88[2];
u8 *MapObj_FindById_0_00179DB0(s32 id, s32 key) {
    Tbl *t;
    Ent *e;
    s32 i;
    Mdl **q;
    s32 j;
    Mdl ***pp;
    for (i = 0, pp = D_00201E88; i < 2; i++, pp++) {
        q = *pp;
        if (q != NULL && *q != NULL && (*q)->id == id) {
            t = (*q)->x164;
            if (t != NULL) {
                e = t->e;
                for (j = 0; j < t->n; j++, e++) {
                    if (e->id == key) return (u8 *)t + e->off;
                }
            }
        }
    }
    return NULL;
}
