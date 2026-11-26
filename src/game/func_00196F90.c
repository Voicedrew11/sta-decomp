#include "m2c.h"
void func_00123C40(void *, s32, s32);
void func_00185390(f32, s32, s32, s32);
void func_00186440(f32, f32 *, f32 *, f32 *, f32 *);
f32 func_00187770(f32, f32, f32);
void func_0019A370(f32 *, f32 *, f32 *, f32 *, s32);
s32 func_001A9B40(s16);
void func_001DF470(f32, s32);
extern s32 D_00201D38;
extern s32 *D_00201D3C;
extern s32 D_00202198;
extern f32 D_0020219C;
extern f32 D_002021A0;
extern s32 D_004A1430[];
extern s32 D_004A1434[];

void func_00196F90(f32 arg0) {
    f32 a[4];
    f32 b[4];
    f32 c[4];
    f32 d[4];
    s32 id;
    s32 ok;
    s32 m;
    f32 t;

    func_0019A370(a, b, c, d, D_00201D3C[D_004A1430[0]]);
    id = D_00201D3C[D_004A1430[0]];
    if (id < 0) {
        ok = 0;
    } else {
        ok = func_001A9B40(id);
    }
    if (ok != 0) {
        func_00186440(arg0, a, b, c, d);
    } else {
        func_00123C40(a, -1, 0x10);
        func_00123C40(b, -1, 0x10);
        func_00186440(arg0, a, b, NULL, NULL);
    }
    if (D_004A1434[0] == 1) {
        D_002021A0 = 10.0f;
    }
    if (!(D_002021A0 <= 0.0f)) {
        D_002021A0 -= 1.0f;
        D_0020219C = func_00187770(D_0020219C, -2.99f, 3.5f);
    } else {
        D_0020219C = func_00187770(D_0020219C, -0.02f, 3.5f);
    }
    func_00185390(arg0 + D_0020219C, 1, D_00202198, D_004A1430[0]);
    t = arg0 + D_0020219C;
    m = D_00201D38;
    func_001DF470(t, m == 1 ? -1 : m);
}
