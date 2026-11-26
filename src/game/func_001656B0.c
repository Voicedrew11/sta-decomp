#include "common.h"
typedef struct { s32 type; union { s32 i; u32 u; f32 f; } v; } Out;
void func_001656B0(u8 *a0, Out *out, s32 key, s32 off) {
    u16 type;
    u8 *p;
    p = (u8 *)(off + (s32)a0 + 0x14);
    type = (key & 0xFFFF00) >> 8;
    switch (type) {
    case 0: out->v.i = *(s8 *)p; break;
    case 1: out->v.i = *(u8 *)p; break;
    case 2: out->v.i = *(s16 *)p; break;
    case 3: out->v.i = *(u16 *)p; break;
    case 4: out->v.i = *(s32 *)p; break;
    case 5: out->v.u = *(u32 *)p; break;
    case 6: out->v.f = *(f32 *)p; break;
    }
    out->type = type;
}
