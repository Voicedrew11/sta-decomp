#include "common.h"
typedef struct { u8 pad[0x24]; Flags8 x24; } Anim;
typedef struct { u8 pad[0xA]; u16 xA; u16 xC; u8 padE[0x42]; u16 x50; u8 pad52[6]; s16 x58[2]; s8 x5C[2][2]; u8 pad60[0x30]; } Ent;
typedef struct { Anim *a; } M84;
typedef struct {
    u8 pad0[0x84];
    M84 *x84;
    u8 pad88[0x14];
    s16 idx;
    u8 pad9E[0xA];
    Flags8 xA8;
    Flags8 xA9;
    u8 padAA[0xE];
    s8 *xB8;
    s8 *xBC;
    s8 *xC0[2][2];
} Node;
M84 *func_00174230(s32, s32, s32, s32);
void func_00171540(Anim *, Node *);
s32 func_00169BB0(s32);
s8 *func_00169B50(s32, s32, s32, s32);
void func_001677C0(s8 *, void *);
extern Ent *D_002022B0;
extern s32 D_002022A0;
extern s32 D_00201F2C;
static inline Ent *ent(s16 i) {
    if (D_002022B0 != NULL && i > 0 && i < 0x400) return &D_002022B0[i];
    return NULL;
}

void func_001ABCC0(Node *o, s32 a1) {
    s8 *s;
    s32 k;
    s32 j;
    Ent *e;
    s32 save;
    s32 i;

    e = ent(o->idx);
    o->x84 = func_00174230(D_002022A0, a1, -1, -1);
    o->x84->a->x24.f.b2 = 0;
    save = D_00201F2C;
    for (i = 0; i < 2; i++) {
        D_00201F2C = i;
        func_00171540(o->x84->a, o);
    }
    D_00201F2C = save;
    o->xA8.f.b1 = 0;
    o->xA8.f.b0 = 1;
    o->xA8.f.b7 = 1;
    o->xA9.f.b0 = 0;
    if (e->xC && func_00169BB0(e->xC)) {
        s = func_00169B50(e->xC, 0, 0, 0);
        if (s) func_001677C0(s, o);
        o->xB8 = s;
    }
    if (e->xA == 2 && e->x50 && func_00169BB0(e->x50)) {
        s = func_00169B50(e->x50, 1, 0, 0);
        if (s) func_001677C0(s, o);
        o->xBC = s;
    }
    if (e->xA == 1) {
        for (k = 0; k < 2; k++) {
            if (e->x58[k]) {
                for (j = 0; j < 2; j++) {
                    if (!(e->x5C[k][j] <= -1) && func_00169BB0(e->x58[k])) {
                        s = func_00169B50(e->x58[k], 1, 0, 0);
                        if (s) func_001677C0(s, o);
                        o->xC0[k][j] = s;
                    }
                }
            }
        }
    }
}
