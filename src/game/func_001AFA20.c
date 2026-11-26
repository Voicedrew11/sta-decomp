#include "obj3d.h"
void memset(void *, s32, s32);
extern u8 D_004AC5A0[];
static inline void init(Obj3D *e, s16 t) { e->x9C = -1; e->x9E = t; e->xB4 = 1.0f; e->xAE = -1; e->xA7 = -1; }

void func_001AFA20(void) {
    u32 i;
    memset(D_004AC5A0, 0, 0x88);
    memset(D_004AE370, 0, 0x6800);
    memset(D_004AC970, 0, 0x1A00);
    memset(D_004AC630, 0, 0x340);
    for (i = 0; i < 64; i++) { init(&D_004AE370[0][i], 0); init(&D_004AE370[1][i], 0); }
    for (i = 0; i < 16; i++) { init(&D_004AC970[0][i], 1); init(&D_004AC970[1][i], 1); }
    init(&D_004AC630[0], 2); init(&D_004AC630[1], 2); init(&D_004AC630[2], 2); init(&D_004AC630[3], 2);
}
