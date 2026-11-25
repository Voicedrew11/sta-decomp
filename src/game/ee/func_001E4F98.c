#include "common.h"

typedef struct { u32 start; char p[0x1C]; u32 end; } R;

f32 func_001E4F98(R *r, u32 x)
{
    f32 t = (f32)(x - r->start) / (f32)(r->end - r->start);
    return t * (2.0f - t);
}
