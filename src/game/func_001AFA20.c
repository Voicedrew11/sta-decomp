#include "m2c.h"
typedef struct { u8 pad[0x9C]; s16 a; s16 type; u8 p[7]; s8 c; u8 p2[6]; s16 d; u8 p3[4]; f32 f; u8 p4[0x18]; } E;
void func_00123C40(void *, s32, s32);
extern E D_004AC5A0[];
extern E D_004AC630[4];
extern E D_004AC970[2][16];
extern E D_004AE370[2][64];
static inline void init(E *e, s16 t) { e->a = -1; e->type = t; e->f = 1.0f; e->d = -1; e->c = -1; }

void func_001AFA20(void) {
    u32 i;
    func_00123C40(D_004AC5A0, 0, 0x88);
    func_00123C40(D_004AE370, 0, 0x6800);
    func_00123C40(D_004AC970, 0, 0x1A00);
    func_00123C40(D_004AC630, 0, 0x340);
    for (i = 0; i < 64; i++) { init(&D_004AE370[0][i], 0); init(&D_004AE370[1][i], 0); }
    for (i = 0; i < 16; i++) { init(&D_004AC970[0][i], 1); init(&D_004AC970[1][i], 1); }
    init(&D_004AC630[0], 2); init(&D_004AC630[1], 2); init(&D_004AC630[2], 2); init(&D_004AC630[3], 2);
}
