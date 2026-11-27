#include "m2c.h"
void sceVu0AddVector(void *, void *, f32 *);
void sceVu0CopyVector(void *, f32 *);
typedef struct { u8 pad[0x30]; f32 v[4]; u8 pad2[0x188-0x40]; u8 flags; u8 pad3[0xED0-0x189]; } A;
typedef struct { u8 m[0x100]; u8 m2[0x14]; u8 f0 : 1; u8 f1:1; u8 f2:1; u8 f3:1;u8 f4:1;u8 f5:1;u8 f6:1;u8 f7:1; u8 pad[0x120-0x115]; } B;
typedef struct { f32 x, y, z; u8 pad[0x30-12]; } C;
typedef struct { C c[2]; } CC;
extern s32 D_00201F2C;
extern u32 D_00201FAC;
extern B *D_00201FC0;
extern CC *D_00201FD0;
extern u8 D_003406D0[];
extern A D_003407E0[];

void Sfx_OffsetAll_1_00167850(f32 *arg0) {
    s32 i;
    A *a;

    a = D_003407E0;
    for (i = 0; i < 0x100; i++, a++) {
        if (a->flags & 1) {
            sceVu0AddVector(a->v, a->v, arg0);
            a->v[3] = 1.0f;
        }
    }
    sceVu0CopyVector(D_003406D0, arg0);
    for (i = 0; i < D_00201FAC; i++) {
        if (D_00201FC0[i].f0 && !D_00201FC0[i].f5) {
            sceVu0AddVector(&D_00201FC0[i], &D_00201FC0[i], arg0);
            sceVu0AddVector(D_00201FC0[i].m2, D_00201FC0[i].m2, arg0);
            D_00201FD0[i].c[D_00201F2C].x += arg0[0];
            D_00201FD0[i].c[D_00201F2C].y += arg0[1];
            D_00201FD0[i].c[D_00201F2C].z += arg0[2];
        }
    }
}
