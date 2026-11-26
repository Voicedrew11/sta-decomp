#include "common.h"
typedef struct { u8 pad[0x1A]; u16 x1A; u8 pad2[0x14]; } E;
typedef struct { u8 pad[0x6E]; u16 n; u8 pad2[0xC8]; E *e; } P;
P *func_001B19A0(s32);
void func_001B8350(s32, s32, s32);

static inline s32 find(s32 a, s32 k) {
    P *p;
    E *e;
    s32 n;
    s32 i;
    p = func_001B19A0(a);
    if (p == NULL) return -1;
    n = p->n;
    i = 0;
    if (i < n) {
        e = p->e;
        do {
            if (k == e->x1A % 100) return i;
            i++;
            e++;
        } while (i < n);
    }
    return -1;
}
void func_001B7CD0(s32 a, s32 k) {
    func_001B8350(a, find(a, k), 0);
}

