#include "common.h"
extern void *D_00201FA0;

void Fx_FreeSpriteBuffer_0_00164330(s32 arg0, s32 arg1) {
    Tex_Release_1_00177570(D_00201FA0, (s16 *) arg1);
    D_00201FA0 = NULL;
}
