#include "common.h"

void Pool_MarkDead_0_001536F0(s32 x, u8 *p);
void TexAnim_InitTables_0_001746A0(void);

s32 Mdl_InitPool_0_00174620(u8 *o, s32 x)
{
    if (x == 0)
        return 0;
    if (o == NULL)
        return 0;
    *(s32 *)o = x;
    Pool_MarkDead_0_001536F0(x, o + 4);
    Pool_MarkDead_0_001536F0(x, o + 0x34);
    TexAnim_InitTables_0_001746A0();
    return 1;
}
