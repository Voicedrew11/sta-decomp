#include "m2c.h"
typedef struct { f32 v[4]; } V4;
typedef struct { f32 v[8]; } V8;
typedef struct { u8 b0:1; u8 b1:1; u8 r:6; } BF;
typedef struct {
    V4 a;
    V8 b;
    union { u32 w; u8 c[4]; } u;
    u8 pad[0xC];
} Buf;
typedef struct { u8 pad[4]; u32 w; u8 pad2[8]; V4 a; V8 b; } Src;
void func_00123C40(void *, s32, s32);
Src *func_001A8360(u16);
s32 func_001675D0(s8 *);
void func_0013BA60(s32, void *, s32, s32);

void func_00146A70(s8 *o, s32 a1, s32 a2, u32 id) {
    Src *s;
    void *p;
    Buf buf;
    if (((BF *)(o + 0x18A))->b1) {
        p = o + 0xE80;
    } else {
        s = func_001A8360(id);
        func_00123C40(&buf, 0, 0x40);
        if (s) {
            buf.a = s->a;
            buf.b = s->b;
            buf.u.w = s->w;
        }
        p = &buf;
    }
    func_0013BA60(func_001675D0(o), p, a1, a2);
}
