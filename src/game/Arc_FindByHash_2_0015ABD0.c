#include "m2c.h"
typedef struct { s32 x0; s32 x4; s32 x8; s32 xC; u16 flags; s16 x12; s32 fd; s32 size; } F;
typedef struct { u8 c[4]; s32 x4; s32 x8; s32 xC; s32 x10; s32 x14; s32 x18; s32 x1C; } E;
typedef struct { s32 a, b, n, c; E e[1]; } T;
extern s32 D_00201C7C;
extern F *D_00201F80;
extern s32 D_00201F88;
extern T D_002F20C0;
extern s32 D_002F20C8[];
extern F D_0030A0D0[];
static inline F *findFree(void) {
    s32 i;
    for (i = 0; i < 16; i++) {
        if (D_0030A0D0[i].size == 0) {
            return &D_0030A0D0[i];
        }
    }
    return NULL;
}

F *Arc_FindByHash_2_0015ABD0(s32 key) {
    s32 n;
    E *e;
    s32 i;
    F *f;

    n = D_002F20C8[0];
    e = NULL;
    if (D_00201C7C == 3 && D_00201F88 == 0) {
        return NULL;
    }
    for (i = 0; i < n; i++) {
        e = &D_002F20C0.e[i];
        if (key == e->x14) break;
    }
    if (i == n) {
        return NULL;
    }
    f = findFree();
    f->x0 = D_00201F80->x0 + (e->x18 << 11);
    f->x4 = f->x0;
    f->x8 = e->x14;
    f->xC = (s32)e;
    f->flags = D_00201F80->flags;
    f->flags &= 0x300;
    f->x12 = e->c[3] - 0x30;
    f->fd = -1;
    f->size = e->x8;
    return f;
}
