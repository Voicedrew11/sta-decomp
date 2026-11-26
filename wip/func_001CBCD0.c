/* round 2 near-miss: 1 word: retail has a hand-written addi $3,$3,-7 at the switch range check (ASM-ONLY) */
#include "common.h"
typedef struct { char p0[0xA]; u16 h; char pc[0x14]; u16 x20; char p22[0x1A]; u8 b3c; u8 b3d; u8 b3e; u8 b3f; char rest[0x50]; } E;
typedef struct { u8 b0, b1, b2, b3; } F;
typedef struct { char pad[0xA0]; F f[0x400]; } T;
E *func_001AFC90(s16 i);
T *func_001C9BA0(void);
void func_001CBED0(s16 i, s32 a, u8 v);

static inline F *getf(T *t, s16 i) {
    if (i >= 0 && i < 0x400) return &t->f[i];
    return NULL;
}

void func_001CBCD0(s16 i) {
    E *e = func_001AFC90(i);
    u8 v = 0;
    s32 r;
    if (i < 0 || i >= 0x400)
        return;
    switch (e[i].h) {
    case 0: break;
    case 1: v = e[i].b3c; break;
    case 2: v = e[i].b3c; break;
    }
    func_001CBED0(i, 1, v);
    r = 2;
    if (e[i].h == 2) {
        switch (e[i].x20) {
        case 7: case 8: case 10: case 11: case 12: case 13: case 14: case 15: case 16: case 17: case 18:
            r = 1; break;
        case 9: case 19: r = 2; break;
        default: r = 0; break;
        }
        if (r == 1) {
            getf(func_001C9BA0(), i)->b3 = e[i].b3f;
        }
    }
}

