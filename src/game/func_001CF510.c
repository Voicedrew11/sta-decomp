#include "m2c.h"
typedef struct { u8 pad[0x20]; u16 type; u8 pad22[8]; u8 b[6]; u16 v[6]; f32 f[0x15]; } E;
typedef struct { u8 pad[0x4A]; u16 v[6]; } E2;
typedef struct { u16 v[6]; f32 f; } R;
void memset(void *, s32, s32);
void func_001D1240(void *, s16, u8);
void func_001D0610(R *, s32);
extern E D_004B5DD0[2];
extern E2 D_004B6130;
static inline s32 isType(u16 t) {
    switch (t) {
    case 2: case 4: case 6: case 9: case 0xB: case 0xC: case 0xD: case 0xF: case 0x10: case 0x11: case 0x12: case 0x13:
        return 1;
    }
    return 0;
}
static inline f32 u2f(u32 x) { return x; }
static inline void addv(R *a0, E *e, f32 k) {
    a0->v[0] = a0->v[0] + (s32)(u32)(k * u2f(e->v[0]));
    a0->v[1] = a0->v[1] + (s32)(u32)(k * u2f(e->v[1]));
    a0->v[2] = a0->v[2] + (s32)(u32)(k * u2f(e->v[2]));
    a0->v[3] = a0->v[3] + (s32)(u32)(k * u2f(e->v[3]));
    a0->v[4] = a0->v[4] + (s32)(u32)(k * u2f(e->v[4]));
    a0->v[5] = a0->v[5] + (s32)(u32)(k * u2f(e->v[5]));
}

void func_001CF510(R *a0, s32 *a1, s32 a2, s16 *a3, u8 *t0, s32 sel, s32 k) {
    E *e;
    s32 t;
    memset(a0, 0, 0x10);
    memset(a1, 0, 0x20);
    func_001D1240(&D_004B5DD0[0], a3[0], t0[0]);
    func_001D1240(&D_004B5DD0[1], a3[1], t0[4]);
    func_001D1240(&D_004B6130, a3[6], t0[0x18]);
    a0->f = D_004B5DD0[sel].f[k];
    addv(a0, &D_004B5DD0[sel], 1.0f);
    a1[0] += D_004B5DD0[sel].b[0];
    a1[1] += D_004B5DD0[sel].b[1];
    a1[2] += D_004B5DD0[sel].b[2];
    a1[3] += D_004B5DD0[sel].b[4];
    a1[4] += D_004B5DD0[sel].b[3];
    a1[5] += D_004B5DD0[sel].b[5];
    if (!isType(D_004B5DD0[sel].type)) {
        sel = !sel;
        addv(a0, &D_004B5DD0[sel], 0.1f);
    }
    if (a3[6] != -1) {
        t = D_004B6130.v[0]; a0->v[0] += t;
        t = D_004B6130.v[1]; a0->v[1] += t;
        t = D_004B6130.v[2]; a0->v[2] += t;
        t = D_004B6130.v[3]; a0->v[3] += t;
        t = D_004B6130.v[4]; a0->v[4] += t;
        t = D_004B6130.v[5]; a0->v[5] += t;
    }
    func_001D0610(a0, a2);
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
