#include "m2c.h"
typedef struct { u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; u8 b4:1; } F;
typedef struct { u8 pad[0x10]; s32 x10; u8 pad14[0x28]; F f3C; } M;
typedef struct { M *m; } O;
typedef struct { u8 pad[0x40]; s32 x40; s32 x44; u8 pad48[0xC]; s32 x54; u8 pad58[0x28]; } E;
typedef struct { s32 p; s32 pad; } P8;
typedef struct {
    s32 pad0;
    O *o;
    s32 x8;
    s32 xC;
    u8 pad10[0x14];
    s32 x24;
    u8 pad28[0x46];
    u16 n6E;
    u16 n70;
    u8 pad72[4];
    u16 n76;
    u16 n78;
    u8 pad7A[8];
    u16 n82;
    u8 pad84[0x30];
    u8 xB4[0xC4];
    s32 *x178;
    P8 *x17C;
    E *x180;
    u8 pad184[8];
    s32 *x18C;
    P8 *x190;
    u8 pad194[4];
    s32 x198[16];
    u8 f1D8;
} S;
void func_00128580(s32, void *);
void func_0015DB60(s32);
void func_00167030(s32);
void func_00169D00(void *, s32);
void func_00170250(s32, O *);
void func_00170E90(O *);
void func_00178030(s32);
void func_001A6A10(s32);
void func_001AF740(S **);
void func_001B4F20(S *);
void func_001745D0(s32, s32);
extern S **D_002022BC;
extern s32 D_002022C4;
extern s32 D_002022D0;

void func_001B5640(S **a0) {
    S *s;
    O *o;
    s32 i;

    E *e;

    if (a0 == NULL || (s = *a0) == NULL) {
        return;
    }
    o = s->o;
    if (D_002022BC == a0) {
        D_002022BC = NULL;
    }
    if (s->f1D8 & 1) {
        func_001B4F20(*a0);
        for (i = 0; i < s->n6E; i++) {
            e = &s->x180[i];
            if (e->x54) {
                func_00167030(e->x54);
            }
            func_001745D0(D_002022D0, e->x40);
            if (e->x44) {
                func_001745D0(D_002022D0, e->x44);
            }
        }
        for (i = 0; i < s->n82; i++) {
            func_001A6A10(s->x198[i]);
        }
        for (i = 0; i < s->n70; i++) {
            if (s->x17C[i].p) {
                func_001A6A10(s->x17C[i].p);
            }
        }
        func_001AF740(a0);
        for (i = 0; i < s->n78; i++) {
            if (s->x190[i].p) {
                func_00167030(s->x190[i].p);
            }
        }
        func_00169D00(s->xB4, 0x20);
        for (i = 0; i < s->n76; i++) {
            func_0015DB60(s->x18C[i]);
        }
        func_00170E90(o);
        if (o->m->f3C.b4) {
            func_00178030(o->m->x10);
        }
        func_001745D0(D_002022D0, *s->x178);
        if (s->xC) {
            func_00128580(D_002022C4, (void *)s->xC);
        }
        func_00128580(D_002022C4, (void *)s->x8);
    } else if (o) {
        func_00170E90(o);
        if (o->m->f3C.b4) {
            func_00178030(o->m->x10);
        }
        func_00170250(D_002022D0, o);
    } else if (s->x24) {
        func_00128580(D_002022C4, (void *)s->x24);
    }
    func_00128580(D_002022C4, a0);
}
