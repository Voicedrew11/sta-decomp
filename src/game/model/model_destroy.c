#include "common.h"
#include "game/gfx.h"
void Mdl_DestroyInstance_0_001745D0(s32 arg0, s32 **arg1);
s32 Mdl_InitPool_0_00174620(u8 *o, s32 x);
void Pool_MarkDead_0_001536F0(s32 x, u8 *p);

/* Mdl_DestroyInstance_0_001745D0 */
void Mdl_DestroyInstance_0_001745D0(s32 arg0, s32 **arg1) {
    Mdl_Free_0_00170250((s32 *) arg0, (void **) **arg1);
    Pool_FreeChunk_0_001531A0(arg0 + 0x34, arg1);
}

/* Mdl_InitPool_0_00174620 */
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
