#include "common.h"
typedef struct { u8 pad[0x24]; f32 x24; } H;
typedef struct { u8 pad[0x18]; H *x18; } R;
typedef struct { u8 pad[0x180]; R r; } Sub;
typedef struct { u8 pad[0x518]; Sub *x518; } S;
extern S *D_002022E4;
s8 *Script_GetArgPtr_2_00165130(s32 a, s32 b);
void MapCmd_GetPlayerRot_1_0017D240(s32 a) {
    R *s = &D_002022E4->x518->r;
    f32 *p = (f32 *)Script_GetArgPtr_2_00165130(a, 0);
    f32 t;
    if (s != NULL) {
        t = 3.1415927f + s->x18->x24;
        *p = 180.0f * ((t - 6.2831855f * (s32)(0.15915494f * t)) + (t < 0.0f ? 6.2831855f : 0.0f) - 3.1415927f) / 3.1415927f;
    }
}
