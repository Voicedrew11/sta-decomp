#include "common.h"

typedef struct { char pad[8]; u32 a; char p1[4]; u32 b; char p2[4]; f32 x; char p3[4]; f32 y; } S;
void TexAnim_SetScroll_0_001757C0(u32 a, u32 b, f32 x, f32 y);

void MapCmd_SetTexScroll_1_0017CAA0(S *s)
{
    TexAnim_SetScroll_0_001757C0(s->a, s->b, s->x, s->y);
}
