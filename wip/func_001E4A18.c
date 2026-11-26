/* NEAR 2 of 104 words: loads/regs now match retail (x->f3, y->f0); only the swc1 order of o.x/o.y is swapped (stores y first). Stores x-first flip the regs back. */
#include "common.h"
typedef struct { f32 x, y, w, h; } R4;
typedef struct { f32 x, y, w, h; } __attribute__((aligned(8))) R;
typedef struct { f32 x, y, z, w; u8 pad[0xC]; } V;
R4 func_001E4BB8(s32, s32);

void func_001E4A18(s32 a, s32 b, V *v, u8 flags) {
    R4 t; R r; R o; f32 x, y, w, h;
    t = func_001E4BB8(a, b); x = t.x; y = t.y; w = t.w; h = t.h; o.y = y; o.x = x; o.w = w; o.h = h; r = o;
    switch (flags & 0xF) {
    case 0: default: r.x -= r.w * 0.5f; break;
    case 1: break;
    case 2: r.x -= r.w; break;
    }
    switch (flags >> 4) {
    case 0: default: r.y -= r.h * 0.5f; break;
    case 1: break;
    case 2: r.y -= r.h; break;
    }
    v[0].z = v[1].z = v[2].z = v[3].z = 0.0f;
    v[0].w = v[1].w = v[2].w = v[3].w = 1.0f;
    v[0].x = v[2].x = r.x + -0.5f;
    v[1].x = v[3].x = r.x + r.w + -0.5f;
    v[0].y = v[1].y = r.y + -0.5f;
    v[2].y = v[3].y = r.y + r.h + -0.5f;
}
