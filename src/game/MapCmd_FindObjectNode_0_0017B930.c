#include "common.h"
typedef struct { char p[0x1C]; u16 x1C; char q[0x12]; } E;
typedef struct { s32 a, b; } R;
typedef struct { char p[0x6C]; u16 x6C; char q[0x134-0x6E]; E *x134; char r[0x178-0x138]; R *x178; } O;
O *MapObj_Find_1_001B19A0(s32);
R *MapCmd_FindObjectNode_0_0017B930(s32 a, s32 id) {
    O *o;
    E *e;
    R *r;
    s32 i;
    o = MapObj_Find_1_001B19A0(a);
    if (o == NULL) return NULL;
    e = o->x134;
    r = o->x178;
    for (i = 0; i < o->x6C; i++) {
        if (e == NULL) return NULL;
        if (r == NULL) return NULL;
        if (e[0].x1C == id) return r;
        e++;
        r++;
    }
    return NULL;
}
