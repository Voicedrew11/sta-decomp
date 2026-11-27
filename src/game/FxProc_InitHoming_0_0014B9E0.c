#include "common.h"

typedef struct {
    char pad[0x5C]; f32 scale; char p60[4]; f32 v64; char p68[0x40];
    s32 a8; char pac[4]; f32 b0; f32 b4; f32 b8;
} Obj;
extern void *D_002022E4;
void Actor_GetYawPitch_1_00145F40(void *a, f32 *b, s32 c);

void FxProc_InitHoming_0_0014B9E0(Obj *o)
{
    o->scale = 1.0f;
    o->b0 = o->v64;
    o->b8 = 100000.0f;
    o->a8 = 0;
    Actor_GetYawPitch_1_00145F40(D_002022E4, &o->b4, 0);
}
