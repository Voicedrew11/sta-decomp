#include "common.h"

typedef struct { u32 start; char p[0x1C]; u32 end; } R;

f32 Ease_Linear_2_001E4F20(R *r, u32 x)
{
    return (f32)(x - r->start) / (f32)(r->end - r->start);
}
