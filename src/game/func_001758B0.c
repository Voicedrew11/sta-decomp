#include "m2c.h"
typedef struct { s8 *p; u8 pad[0x28]; } S2C;
typedef struct { s32 id; u32 n; u32 ref; u8 pad[0x20]; s32 key; u8 pad2[0x1D0-0x30]; S2C s[7]; u8 pad3[0xC]; } E;
typedef struct { s32 total; s32 pad; E e[4]; } G;
extern G D_00437DC0;
void func_00177570(s8 *);
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

void func_001758B0(s32 arg0, s32 arg1) {
    E *e = find(arg0, arg1);
    u32 i;
    if (e->ref >= 2) {
        e->ref--;
        return;
    }
    if (e->ref == 1) {
        D_00437DC0.total--;
        e->ref = 0;
        e->id = -1;
        for (i = 0; i < e->n; i++) {
            if (e->s[i].p != NULL) func_00177570(e->s[i].p);
        }
    }
}
