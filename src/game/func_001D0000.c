#include "m2c.h"
typedef struct { u8 pad[0x20]; u16 type; u8 pad22[8]; u8 b[6]; u16 v[6]; } E;
typedef struct { u8 pad[0x4A]; u16 v[6]; } E2;
void memset(void *, s32, s32);
void func_001D1240(void *, s16, u8);
void func_001D0610(u16 *, s32);
extern E D_004B5DD0;
extern E D_004B5E60;
extern E2 D_004B6130;
static inline s32 isType(u16 t) {
    switch (t) {
    case 2: case 4: case 6: case 9: case 0xB: case 0xC: case 0xD: case 0xF: case 0x10: case 0x11: case 0x12: case 0x13:
        return 1;
    }
    return 0;
}

void func_001D0000(u16 *a0, s32 *a1, s32 a2, s16 *a3, u8 *t0, u32 f) {
    s32 f1;
    s32 f2;
    s32 t;

    memset(a0, 0, 0x10);
    func_001D1240(&D_004B5DD0, a3[0], t0[0]);
    func_001D1240(&D_004B5E60, a3[1], t0[4]);
    func_001D1240(&D_004B6130, a3[6], t0[0x18]);
    f1 = f & 1;
    if (f1) {
        t = D_004B5DD0.v[0]; a0[0] += t;
        t = D_004B5DD0.v[1]; a0[1] += t;
        t = D_004B5DD0.v[2]; a0[2] += t;
        t = D_004B5DD0.v[3]; a0[3] += t;
        t = D_004B5DD0.v[4]; a0[4] += t;
        t = D_004B5DD0.v[5]; a0[5] += t;
    }
    f2 = f & 2;
    if (f2) {
        t = D_004B5E60.v[0]; a0[0] += t;
        t = D_004B5E60.v[1]; a0[1] += t;
        t = D_004B5E60.v[2]; a0[2] += t;
        t = D_004B5E60.v[3]; a0[3] += t;
        t = D_004B5E60.v[4]; a0[4] += t;
        t = D_004B5E60.v[5]; a0[5] += t;
    }
    if (isType(D_004B5DD0.type)) {
        a0[0] = D_004B5DD0.v[0];
        a0[1] = D_004B5DD0.v[1];
        a0[2] = D_004B5DD0.v[2];
        a0[3] = D_004B5DD0.v[3];
        a0[4] = D_004B5DD0.v[4];
        a0[5] = D_004B5DD0.v[5];
    }
    if (a3[6] != -1) {
        t = D_004B6130.v[0]; a0[0] += t;
        t = D_004B6130.v[1]; a0[1] += t;
        t = D_004B6130.v[2]; a0[2] += t;
        t = D_004B6130.v[3]; a0[3] += t;
        t = D_004B6130.v[4]; a0[4] += t;
        t = D_004B6130.v[5]; a0[5] += t;
    }
    func_001D0610(a0, a2);
    if (a1 != NULL) {
        memset(a1, 0, 0x20);
        if (f1) {
            a1[0] += D_004B5DD0.b[0];
            a1[1] += D_004B5DD0.b[1];
            a1[2] += D_004B5DD0.b[2];
            a1[3] += D_004B5DD0.b[4];
            a1[4] += D_004B5DD0.b[3];
            a1[5] += D_004B5DD0.b[5];
        }
        if (f2) {
            a1[0] += D_004B5E60.b[0];
            a1[1] += D_004B5E60.b[1];
            a1[2] += D_004B5E60.b[2];
            a1[3] += D_004B5E60.b[4];
            a1[4] += D_004B5E60.b[3];
            a1[5] += D_004B5E60.b[5];
        }
        if (isType(D_004B5DD0.type)) {
            a1[0] = D_004B5DD0.b[0];
            a1[1] = D_004B5DD0.b[1];
            a1[2] = D_004B5DD0.b[2];
            a1[3] = D_004B5DD0.b[4];
            a1[4] = D_004B5DD0.b[3];
            a1[5] = D_004B5DD0.b[5];
        }
        if ((s16)a1[0] < 0) a1[0] = 0;
        if ((s16)a1[0] > 100) a1[0] = 100;
        if ((s16)a1[1] < 0) a1[1] = 0;
        if ((s16)a1[1] > 100) a1[1] = 100;
        if ((s16)a1[2] < 0) a1[2] = 0;
        if ((s16)a1[2] > 100) a1[2] = 100;
        if ((s16)a1[3] < 0) a1[3] = 0;
        if ((s16)a1[3] > 100) a1[3] = 100;
        if ((s16)a1[4] < 0) a1[4] = 0;
        if ((s16)a1[4] > 100) a1[4] = 100;
        if ((s16)a1[5] < 0) a1[5] = 0;
        if ((s16)a1[5] > 100) a1[5] = 100;
    }
}
