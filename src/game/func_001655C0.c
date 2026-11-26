#include "m2c.h"
typedef struct { s32 type; union { s32 i; u32 u; f32 f; } v; } Out;
typedef struct { u8 pad[0xC]; u16 xC; u16 xE; } Hdr;

void func_001655C0(void *a0, Out *out, Hdr *h, s32 key, s32 off) {
    u16 type;
    u8 *p;
    u32 end;

    type = (key & 0xFFFF00) >> 8;
    end = (off + 7) & ~3;
    if (h->xE < end) {
        h->xE = end;
    }
    p = (u8 *)(off + (h->xC + (s32)h) + 0x158);
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
