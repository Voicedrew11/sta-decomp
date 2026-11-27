#include "m2c.h"
s8 *MapObj_Find_1_001B19A0(s32);
typedef struct { u8 pad[0x18]; u16 x18; u16 x1A; u8 pad2[0x30 - 0x1C]; } E;
static inline E *find(s32 a0, s32 a1) {
    s32 i;
    u16 n;
    E *q;
    s8 *p;
    E *e;
    p = MapObj_Find_1_001B19A0(a0);
    if (p == NULL) {
        return NULL;
    }
    n = M2C_FIELD(p, u16 *, 0x6E);
    i = 0;
    if (i < n) {
        e = M2C_FIELD(p, E **, 0x138);
        q = e;
        do {
            if (a1 == q->x1A % 100) {
                return &e[i];
            }
            i++;
            q++;
        } while (i < n);
    }
    return NULL;
}

s32 MapObj_GetNodeFlags_0_001B76C0(s32 a0, s32 a1) {
    s8 *s;
    E *r;

    s = MapObj_Find_1_001B19A0(a0);
    r = find(a0, a1);
    if (s == NULL || r == NULL) {
        return 0;
    }
    return M2C_FIELD(s, s32 *, 0x170) + (r->x18 << 6);
}
