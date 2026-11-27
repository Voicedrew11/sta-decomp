#include "common.h"
typedef struct { char p[0x38]; u8 x38; s8 x39; char q[6]; } S;
typedef struct { char p[0x7C]; u16 n; char q[0x168 - 0x7E]; S *s; } O;
S *Map_FindSfxEntry_0_001B7300(O *o, s32 id) {
    s32 i;
    S *s;
    u16 n;
    if (o == NULL || id < 0 || id > 127) {
        return NULL;
    }
    n = o->n;
    s = o->s;
    for (i = 0; i < n; i++, s++) {
        if (s->x38 == 1 && s->x39 >= 0 && id == s->x39) break;
    }
    if (i == n) return NULL;
    return s;
}
