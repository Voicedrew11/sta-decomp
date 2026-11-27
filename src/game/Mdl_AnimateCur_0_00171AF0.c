#include "common.h"
typedef struct { u8 pad[6]; u16 x6; } A0;
extern s32 D_00201F2C;
void Mdl_Animate_2_00171BB0(void *, A0 *, u8, u8, s32);
void Mdl_AnimateCur_0_00171AF0(A0 *a, s32 b, s32 c, s32 d) {
    Mdl_Animate_2_00171BB0((u8 *)((s32)a + 0x40) + D_00201F2C * (a->x6 * 0x140 + 0x200), a, c, d, b);
}

