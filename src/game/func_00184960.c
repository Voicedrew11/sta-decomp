#include "m2c.h"
typedef struct { s32 idx; u8 pad[0x28]; f32 x, z; u8 pad2[0xC]; } Obj;
typedef struct { u32 n; Obj *e; } L;
typedef struct { u8 pad[0x10]; L *l; } R;
typedef struct { f32 x, z; } V2;
R *func_00189050(s32);
u8 *func_00189020(s32);
void func_00187B20(s32);
f32 func_0011D4A8(f32);
f32 func_0011DA18(f32);
f32 func_0011D778(f32);
f32 func_0011D850(f32);
f32 func_00187770(f32, f32, f32);
void func_001829B0(Obj *, u8 *, void *, s32);
void func_00184CF0(void);
void func_00181420(void);
void func_001545D0(void);
void func_001543E0(s32, u64);
void func_001544C0(void);
extern f32 sqrtf(f32);
extern f32 D_00202088, D_0020208C, D_00202090, D_00202094, D_00202098, D_0020209C;
extern f32 D_002020B0, D_002020B4, D_002020B8, D_002020BC;

void func_00184960(s32 a0, f32 ang) {
    u32 i;
    L *l;
    u8 *t;
    Obj o;
    f32 v;

    l = func_00189050(2)->l;
    t = func_00189020(2);
    func_00187B20(0);
    for (i = 0; i < l->n; i++) {
        o = l->e[i];
        {
        V2 c = {0};
        f32 d, dx, dz, a, r;
        f32 ox, oz;
        f32 fx, fz;
        c.x = 108.0f;
        c.z = 72.0f;
        fx = o.x; fz = o.z; ox = fx - 108.0f; oz = fz - 72.0f;
        d = sqrtf(ox * ox + oz * oz);
        dx = fx - c.x;
        dz = fz - c.z;
        if (dx == 0.0f) {
            a = 0.0f;
        } else {
            a = func_0011D4A8(dx / dz);
        }
        if (dz < 0.0f) {
            a += 3.141592f;
        }
        r = a + ang;
        o.x = 108.0f + d * func_0011DA18(r);
        o.z = 72.0f + d * func_0011D778(r);
        }
        func_001829B0(&o, t + (l->e[i].idx << 3), func_00184CF0, a0);
    }
    func_00181420();
    func_001545D0();
    func_001543E0(0x42, 0x48);
    func_001544C0();
    func_00189020(0);
    v = D_0020208C;
    D_00202088 += v;
    D_0020208C = v - (v - (v - 1.0f) / 10.0f);
    D_00202090 = func_00187770(D_00202090, D_002020BC, 10.0f);
    D_00202094 = func_00187770(D_00202094, D_002020B8, 10.0f);
    if (!(func_0011D850(D_002020BC - D_00202090) <= 5.0f)) {
        D_0020208C = 0.0f;
    }
    func_0011D778(D_00202088);
    func_0011DA18(D_00202088);
    D_00202098 = func_00187770(D_00202098, D_002020B4, 10.0f);
    D_0020209C = func_00187770(D_0020209C, D_002020B0, 10.0f);
    func_0011D778(3.14f + D_00202088);
    func_0011DA18(3.14f + D_00202088);
    func_00181420();
    func_001545D0();
    func_001543E0(0x42, 0x44);
    func_001544C0();
}
