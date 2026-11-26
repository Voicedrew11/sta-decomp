#include "common.h"
typedef struct { s32 id; s32 o1; s32 o2; } Ent;
typedef struct { s32 x0; u32 n; s32 x8; s32 xC; Ent e[1]; } Tbl;
extern s8 D_001FD268[];
extern Tbl *D_0020215C;
static inline Tbl *get(void) {
    if (D_0020215C != NULL) {
        return (Tbl *)D_0020215C->x0;
    }
    return 0;
}
static inline s8 *find1(Tbl *t, s32 id) {
    Ent *e;
    u32 i;
    if (t == 0) {
        return D_001FD268;
    }
    e = t->e;
    for (i = 0; i < t->n; i++, e++) {
        if (e->id == id) {
            return (s8 *)t + e->o1;
        }
    }
    return D_001FD268;
}
s8 *func_00195AA0(s32 id) {
    return find1(get(), id);
}
