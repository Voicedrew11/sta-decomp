#include "m2c.h"
typedef struct { u8 pad[0x613]; u8 b613; f32 f614; u8 pad2[0xA9]; u8 b6C1; } Obj613;
u32 func_0013E4D0(Obj613 *);
s32 func_0013EEE0(Obj613 *);
s32 func_0013FCC0(Obj613 *, s32);
s32 func_00135490(Obj613 *, f32 *, f32 *, f32 *);
void func_00141E10(Obj613 *, u8, f32, f32, f32, f32);
f32 func_00133D00(Obj613 *, f32 *, f32 *, f32 *);
u32 func_0013EAA0(Obj613 *);
u8 func_00140480(Obj613 *, u8, u32, f32, f32, f32, f32);
u32 func_0013EB60(Obj613 *);
void func_00134D70(Obj613 *, s32);
void func_00135240(Obj613 *, s32);
void func_00140350(Obj613 *, s8 *);
void func_00140330(Obj613 *, s8 *);
u8 func_00134960(Obj613 *);
s32 func_00134180(Obj613 *, f32);
#define B613(a) ((a)->b613)
#define F614(a) ((a)->f614)
static inline f32 u2f(u32 x) { return x; }
static inline void g(Obj613 *a, s32 k) {
    if (func_0013EB60(a)) {
        func_00134D70(a, k);
    } else {
        func_00135240(a, k);
    }
    func_00134960(a);
    F614(a) = u2f(B613(a)) / 10.0f;
}

void func_00136400(Obj613 *a, f32 dt) {
    f32 x0, y0, z0;
    f32 x1, y1, z1;
    f32 r;
    s32 busy;
    u8 m;

    if (func_0013E4D0(a) && func_0013EEE0(a)) {
        return;
    }
    busy = (u8)func_0013FCC0(a, 0);
    func_00141E10(a, func_00135490(a, &x0, &y0, &z0), x0, y0, z0, dt);
    r = func_00133D00(a, &x1, &y1, &z1);
    a->b6C1 = func_00140480(a, a->b6C1, func_0013EAA0(a), r, x1, y1, z1);
    F614(a) -= dt;
    if (F614(a) <= 0.0f) {
        if (func_0013EB60(a)) {
            func_00134D70(a, 0);
        } else {
            func_00135240(a, 0);
        }
        if (!func_0013EEE0(a) && !(u8)busy) {
            func_00140350(a, (s8 *)a + 0x620);
            func_00140330(a, (s8 *)a + 0x630);
            B613(a) = 0xFA;
        }
        func_00134960(a);
        F614(a) = u2f(B613(a)) / 10.0f;
    }
    if ((u8)func_00134180(a, dt)) {
        m = func_00134960(a);
        if (m == 1) {
            g(a, 1);
        } else if (m == 2) {
            g(a, 2);
        }
    }
}
