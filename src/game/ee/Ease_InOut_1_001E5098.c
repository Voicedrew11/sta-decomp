#include "common.h"

typedef struct { u32 start; char p[0x1C]; u32 end; } R;

f32 Ease_InOut_1_001E5098(R *r, u32 x)
{
    f32 t = (f32)(x - r->start) / (f32)(r->end - r->start);
    return t * (t * (t - 3.0f) + 3.0f);
}
