#include "m2c.h"
typedef struct { s32 x0, x4, x8; f32 xC, x10, x14, x18; s32 x1C, x20, x24; u8 c[4]; } P;
extern P D_004B4BE0[];
s32 rand(void);
u32 Rand_Next_3_0015ED20(void);

void Hud_RandomizeMarker_0_001BC170(u8 *col) {
    s32 i;
    P *p;
    for (i = 0, p = D_004B4BE0; i < 2; i++, p++) {
        p->x0 = 60;
        p->x4 = i * 2;
        p->x8 = 55 - (1 - i) * 2;
        p->xC = rand() % 100 - 50;
        p->x10 = rand() % 60 - 30;
        p->x14 = p->x18 = 1.5f + (u16)Rand_Next_3_0015ED20() * 1.5259022e-05f;
        p->x1C = rand() % 2 ? 1 : -1;
        p->x20 = rand() % 2 ? 1 : -1;
        p->x24 = i;
        p->c[0] = col[0];
        p->c[1] = col[1];
        p->c[2] = col[2];
        p->c[3] = col[3];
    }
}
