#include "m2c.h"
typedef struct { u32 n; u8 *p; } L;
typedef struct { u128 q; u64 d; } W6;
void func_00182860(void *, f32);
void func_001828F0(void *, void *, void *);
void func_00181680(s32, void *, void *, void *, void *, s32);
extern W6 D_001F2790 __attribute__((aligned(16)));
#define CV(x, k) if (x < 0) x = 0; if (x > 255) x = 255; col[k] = (x >> 1) | (x >= 128);
void func_00182C10(u8 *o, L *l) {
    u8 col[4];
    f32 pos[7];
    W6 w;
    f32 C[8];
    f32 X[8];
    u32 i;
    u32 off;
    s16 r, g, b, a;
    for (i = 0, off = 0; i < l->n; i++, off += 0x30) {
        r = o[0x3C];
        g = o[0x3D];
        b = o[0x3E];
        a = o[0x3F];
        CV(r, 0)
        CV(g, 1)
        CV(b, 2)
        CV(a, 3)
        {
        u8 *e = l->p + off;
        f32 c = *(f32 *)(o + 0x34);
        f32 ax = *(f32 *)(o + 0x14);
        f32 d = *(f32 *)(o + 0x38);
        f32 ay = *(f32 *)(o + 0x18);
        f32 e0 = *(f32 *)(e + 0x10);
        f32 e1 = *(f32 *)(e + 0x14);
        f32 e3 = *(f32 *)(e + 0x1C);
        f32 e2 = *(f32 *)(e + 0x18);
        pos[0] = ax * (e0 * c) + *(f32 *)(o + 0xC);
        pos[1] = ay * (e1 * d) + *(f32 *)(o + 0x10);
        pos[2] = ax * (e2 * c) + *(f32 *)(o + 0xC);
        pos[3] = ay * (e3 * d) + *(f32 *)(o + 0x10);
        }
        w = D_001F2790;
        func_00182860(C, *(f32 *)(o + 0x24));
        func_001828F0(X, &w, C);
        X[4] = *(f32 *)(o + 0x2C);
        X[5] = *(f32 *)(o + 0x30);
        func_00181680(*(s32 *)(l->p + off + 4), pos, l->p + off + 0x20, col, X, *(s32 *)(l->p + off));
    }
}
