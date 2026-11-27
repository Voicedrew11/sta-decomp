#include "common.h"
s32 *Script_GetArgPtr_2_00165130(void *, s32);
void MapCmd_CopyVar_0_0017D1C0(u8 *a0) {
    s32 *p = Script_GetArgPtr_2_00165130(a0, 0);
    s32 *q = Script_GetArgPtr_2_00165130(a0, 1);
    s32 m = *(s32 *)(a0 + 0x18);
    if (m == 0) *p = *(f32 *)q;
    if (m == 1) *(f32 *)q = *p;
}

