#include "m2c.h"
typedef struct {
    s16 m[16];
    f32 f20;
    union {
        u32 w;
        struct {
            u32 a:1; u32 b:1; u32 c:1; u32 d:1; u32 e:2; u32 f:2;
            u32 g:2; u32 h:2; u32 i:8; u32 rest:12;
        } bf;
    } u24;
    u64 x28;
    u64 x30;
    u8 pad[8];
} S;
void memset(void *, s32, s32);

void func_00129EE0(S *p) {
    s32 z;
    memset(p, 0, 0x40);
    p->m[0] = 0x1000; p->m[1] = 0x1000; p->m[2] = 0x1000; p->m[3] = 0x1000;
    p->m[4] = 0x1000; p->m[5] = 0x1000; p->m[6] = 0x1000; p->m[7] = 0x1000;
    p->m[8] = 0x1000; p->m[9] = 0x1000; p->m[10] = 0x1000; p->m[11] = 0x1000;
    p->m[12] = 0x1000; p->m[13] = 0x1000; p->m[14] = 0x1000; p->m[15] = 0x1000;
    p->f20 = 1.0f;
    p->u24.w = 0;
    z = 0;
    p->u24.bf.a = 1;
    p->u24.bf.b = 1;
    p->u24.bf.c = z;
    p->u24.bf.d = z;
    p->u24.bf.e = z;
    p->u24.bf.f = 1;
    p->u24.bf.g = 2;
    p->u24.bf.h = 1;
    p->u24.bf.i = 0x80;
    p->x28 = -1;
    p->x30 = -1;
}
