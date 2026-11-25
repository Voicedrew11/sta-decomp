#include "m2c.h"
typedef struct { s32 v; u8 pad[0x4C]; } T;
typedef struct { u8 pad[0x1A]; s16 f1A; u8 pad2[0x14]; } E;
typedef struct { s32 pad[3]; T *tbl; s32 pad2[4]; } L;
typedef struct { u8 pad[0x10]; s32 *f10; } O;
typedef struct { s32 pad; O **f4; u8 pad2[0x12C]; E *f134; } A0;
typedef struct { u8 pad[0x20]; O *f20; s32 f24; u8 pad2[0x14]; s32 f3C; } A1;
void func_00171050(O *, L *);

E *func_001B1D00(A0 *arg0, A1 *arg1) {
    L l;
    E *r = NULL;
    O *o;
    s32 t;
    s32 base;
    s32 idx;
    E *e;

    if (arg1->f24 == 0) {
        return NULL;
    }
    o = *arg0->f4;
    if (arg1->f20 != o) {
        return NULL;
    }
    base = *o->f10;
    func_00171050(o, &l);
    idx = arg1->f3C;
    if (idx != -1) {
        e = &arg0->f134[idx];
        t = base + l.tbl[e->f1A].v;
        if (t == arg1->f24) {
            r = e;
        }
    }
    return r;
}
