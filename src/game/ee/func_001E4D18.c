#include "common.h"
typedef struct { u8 r, g, b, a; } C4;
typedef struct { u8 pad[9]; u8 type; u8 pada[0x12]; C4 a; u8 pad2[0x1C]; C4 b; } O;
extern f32 (*D_001F3AC8[])(O *, s32);
C4 func_001E4D18(s32 a1, O *o) {
    C4 r;
    if (D_001F3AC8[o->type]) {
        f32 t = D_001F3AC8[o->type](o, a1);
        r.r = o->a.r + t * ((f32)o->b.r - (f32)o->a.r);
        r.g = o->a.g + t * ((f32)o->b.g - (f32)o->a.g);
        r.b = o->a.b + t * ((f32)o->b.b - (f32)o->a.b);
        r.a = o->a.a + t * ((f32)o->b.a - (f32)o->a.a);
    }
    return r;
}
