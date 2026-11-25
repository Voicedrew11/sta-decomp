#include "m2c.h"
typedef struct { s8 *p; u8 pad[0x28]; } S2C;
typedef struct { s32 id; u32 n; u32 ref; u8 pad[0x20]; s32 key; u8 s[0x2E0]; } E;
typedef struct { s32 total; s32 pad; E e[4]; } G;
extern G D_00437DC0;
void func_00123A88(u8 *, void *, u32);
void func_001754C0(E *, s32);
static inline E *find(s32 a0, s32 a1) {
    s32 i;
    for (i = 0; i < 4; i++) {
        E *e = &D_00437DC0.e[i];
        if (a1 != 0) {
            if (e->id == a0 && e->key == a1) return e;
        } else {
            if (e->id == a0) return e;
        }
    }
    return NULL;
}
static inline E *findfree(void) {
    s32 i;
    for (i = 0; i < 4; i++) {
        E *e = &D_00437DC0.e[i];
        if (e->id == -1) return e;
    }
    return NULL;
}

void func_001759D0(s32 id, u32 n, void *src, s32 key) {
    E *e = find(id, key);
    if (e != NULL) {
        e->ref++;
        return;
    }
    e = findfree();
    e->id = id;
    e->ref = 1;
    if (n >= 8) n = 8;
    e->n = n;
    e->key = key;
    func_00123A88(e->s, src, n * 0x30);
    func_001754C0(e, 1);
    D_00437DC0.total++;
}
