#include "m2c.h"
typedef struct { f32 v[4]; } V4;
typedef struct { f32 v[8]; } V8;
typedef struct { u8 b0:1; u8 b1:1; u8 r:6; } BF;
typedef struct {
    V4 a;
    V8 b;
    union { u32 w; u8 c[4]; struct { u8 x; BF f; u8 y, z; } s; } u;
    u8 pad[0xC];
} Buf;
typedef struct { u8 pad[4]; u32 w; u8 pad2[8]; V4 a; V8 b; } Src;
void memset(void *, s32, s32);
Src *func_001A8360(s32);
s32 func_001675D0(s8 *);
void func_0013BA60(s32, void *, s32, s32);
void func_001B85B0(void *, s32);

void func_001D3A90(s8 *a0, s8 *a1, s32 a2, s32 a3, s32 t0, u8 t1) {
    Src *s;
    void *p;
    s8 *o;
    Buf buf;
    o = *(s8 **)(a0 + 0x90);
    if (((BF *)(o + 0x18A))->b1) {
        p = o + 0xE80;
    } else {
        s = func_001A8360(((s32 *)(a1 + 8))[t1]);
        memset(&buf, 0, 0x40);
        p = &buf;
        buf.a = s->a;
        buf.b = s->b;
        buf.u.w = s->w;
        buf.u.s.f.b1 = 1;
    }
    if (a2 != 0) {
        func_0013BA60(func_001675D0(o), p, a2, t0);
    } else if (a3 != 0) {
        func_001B85B0(p, a3);
    }
}
