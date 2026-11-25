#include "m2c.h"
typedef struct { u8 pad[0x14]; u16 cnt; } P;
typedef struct { P **pp; u16 pad4; u16 n; s8 pad8[0x38]; s8 data[1]; } O;
typedef struct { O *o; s32 base; } H;
extern s32 D_00201F2C;
void func_00102A70(s8 *, s8 *);
inline s8 *get(H *h, s32 sel) {
    O *o;
    s8 *p;
    if (h == NULL || (o = h->o) == NULL) {
        return NULL;
    }
    p = (s8 *)((s32)o->data + sel * (o->n * 0x140 + 0x200));
    *(s32 *)(p + 0xB0) = h->base - (s32)o;
    return p;
}

void func_00171610(H *h) {
    P **pp;
    s32 i;
    s8 *b;
    s8 *a;

    a = get(h, D_00201F2C);
    b = get(h, !D_00201F2C);
    if (a == NULL || b == NULL) {
        return;
    }
    if (h == NULL || h->o == NULL) {
        return;
    }
    pp = h->o->pp;
    if (pp == NULL || *pp == NULL) {
        return;
    }
    for (i = 0; i < (*pp)->cnt + 1; i++) {
        func_00102A70(a + 0x140, b + 0x140);
        func_00102A70(a + 0xC0, b + 0xC0);
        b += 0x140;
        a += 0x140;
    }
}
