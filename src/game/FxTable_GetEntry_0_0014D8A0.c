#include "common.h"
typedef struct { s16 v; } S;
typedef struct { void (*a)(s32); void (*b)(s32); void (*c)(s32); } E;
extern u16 D_001F1E60[];
extern E D_001F1EA0[];
void FxTable_GetEntry_0_0014D8A0(S *a0, u16 i);
s32 FxTable_CallA_0_0014D8E0(u16 i, s32 v);
s32 FxTable_CallB_0_0014D940(u16 i, s32 v);
s32 FxTable_CallC_0_0014D9A0(u16 i, s32 v);

/* FxTable_GetEntry_0_0014D8A0 */
void FxTable_GetEntry_0_0014D8A0(S *a0, u16 i) {
    S t;
    t.v = D_001F1E60[i];
    *a0 = t;
}

/* FxTable_CallA_0_0014D8E0 */
s32 FxTable_CallA_0_0014D8E0(u16 i, s32 v)
{
    if (i >= 29)
        return 0;
    D_001F1EA0[i].c(v);
    return 1;
}

/* FxTable_CallB_0_0014D940 */
s32 FxTable_CallB_0_0014D940(u16 i, s32 v)
{
    if (i >= 29)
        return 0;
    D_001F1EA0[i].b(v);
    return 1;
}

/* FxTable_CallC_0_0014D9A0 */
s32 FxTable_CallC_0_0014D9A0(u16 i, s32 v)
{
    if (i >= 29)
        return 0;
    D_001F1EA0[i].a(v);
    return 1;
}
