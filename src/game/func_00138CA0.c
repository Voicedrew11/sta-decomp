#include "common.h"
typedef struct { Vec p; Vec d; } Seg;
typedef struct { Vec a; Vec b; f32 c[2]; s32 hit; f32 pad; } Res;
typedef struct { u128 q[3]; } R3;
typedef struct { u8 pad[0xA]; u16 xA; u8 padC[2]; u16 xE; } Info;
typedef struct { u8 pad[0x7C]; s32 x7C; u8 pad80[0x4B0 - 0x80]; Info *x4B0; } Ent;
typedef struct { u8 pad[0x2C]; u8 lo:3; u8 x2Cr:5; u8 b0:5; u8 b5:1; } El;
typedef struct { u8 pad[0x160]; u8 x160; } Q;
s32 func_0013D6B0(void);
s32 func_0013EEE0(Ent *);
s32 func_0013EAD0(Ent *);
s32 func_0013EE30(Ent *);
s32 func_0013E220(Ent *);
u8 func_00142820(Ent *, s32);
void func_00150020(Seg *, s8 *, s8 *);
void func_00140470(Ent *, Vec *);
s32 func_0014EC00(Seg *, Vec *, f32, f32);
El *func_0013DCA0(Ent *, u8);
s8 *func_0013DC70(Ent *, u8);
void func_00151900(Res *, s8 *, s8 *, s8 *, s8 *, f32);
static inline u8 can(Ent *a0, Ent *a2) {
    if (func_0013EE30(a0)) {
        if (func_0013EE30(a2)) return 0;
        return 1;
    }
    return func_00142820(a0, func_0013E220(a2));
}

s32 func_00138CA0(Ent *a0, s8 *a1, Ent *a2, Res *a3) {
    Res r;
    Seg sg;
    Vec v;
    s32 best;
    s32 n;
    s32 i;
    El *e;
    s8 *q;
    u8 ok;
    u8 c;

    best = -1;
    n = a2->x7C;
    r.hit = 0;
    a3->hit = 0;
    a3->a.w = 2.0f;
    if (func_0013D6B0()) return best;
    if (a0 == a2) return best;
    if (func_0013EEE0(a2)) return best;
    if (func_0013EAD0(a2)) return best;
    if (func_0013D6B0()) {
        ok = 0;
    } else {
        ok = can(a0, a2);
    }
    if (ok == 0) return -1;
    func_00150020(&sg, a1 + 0x60, a1 + 0x40);
    func_00140470(a2, &v);
    if (!func_0014EC00(&sg, &v, a2->x4B0->xA, a2->x4B0->xE)) return -1;
    for (i = 0; i < n; i++) {
        e = func_0013DCA0(a2, i);
        if (!e->b5) continue;
        if (e->lo == 2) continue;
        c = func_0013EE30(a2); if (c != (e->lo == 1)) continue;
        q = func_0013DC70(a2, i);
        if (*(u8 *)(q + 0x160) & 1) continue;
        func_00151900(&r, a1 + 0x60, a1 + 0x40, q + 0x20, q, 0.95f);
        if (r.hit && i != 0xFF && r.a.w < a3->a.w) {
            best = i;
            *(R3 *)a3 = *(R3 *)&r;
            a3->a.w = r.a.w;
        }
    }
    return best;
}
