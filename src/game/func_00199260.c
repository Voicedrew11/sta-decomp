#include "common.h"
typedef struct { u16 v[8]; } H;
typedef union { s32 w; Flags8 f; } FW;
typedef struct { u8 pad[8]; u8 x8; } O;
s8 *func_001C9BA0(void);
s8 *func_001C9B60(void);
s32 func_001C9BF0(void);
void func_0019A370(H *, H *, H *, H *, s32);
void func_0019A500(H *, H *, s32 *, s32 *, s32 *, s32, s32, s32);
void func_00186440(f32, H *, H *, H *, H *);
void func_00185B30(s32, s32);
void func_00185510(f32, s8 *);
void func_00185B40(f32, s8 *);
void func_00185390(f32, s32, s32, s32);
f32 func_00187770(f32, f32, f32);
void func_001DD7F0(s32, s32, f32);
void func_001DF360(s32, s32);
void func_00184DF0(s32, f32);
void func_00184040(s32, f32);
void func_00184960(s8 *, f32);
s16 func_001CCD90(s32);
void func_001DF470(f32, s32);
extern s32 D_00201D48;
extern s32 *D_00201D4C;
extern f32 D_00201D54;
extern f32 D_00201D58;
extern s32 D_002021B4;
extern f32 D_002021B8;
extern f32 D_002021BC;
extern s32 D_004A28C0[];
extern s32 D_004A28C4[];
extern FW D_004A28D0[];

void func_00199260(O *o, f32 f) {
    s32 eC;
    s32 e8;
    s32 e4;
    s32 e0;
    s32 dC;
    H c0;
    H b0;
    H a0;
    H x90;
    H x80;
    H x70;
    s8 *s3;
    s8 *s2;
    s8 *s1;
    s32 id;
    s32 i;

    s3 = func_001C9BA0();
    s2 = func_001C9BA0();
    s1 = func_001C9B60();
    id = D_00201D4C[D_004A28C0[0]];
    if (D_002021B4 <= 0) id = -1;
    if (o->x8 == 0x16) {
        if (D_004A28D0[0].f.f.b3) {
            D_00201D54 = func_00187770(D_00201D54, -0.02f, 3.5f);
            D_00201D58 = func_00187770(D_00201D58, -2.99f, 3.5f);
        } else {
            D_00201D54 = func_00187770(D_00201D54, -2.99f, 3.5f);
            D_00201D58 = func_00187770(D_00201D58, -0.02f, 3.5f);
        }
    } else {
        D_00201D54 -= (D_00201D54 - -2.99f) / 3.5f;
        D_00201D58 -= (D_00201D58 - -2.99f) / 3.5f;
    }
    func_001DD7F0(id, -1, D_00201D54);
    func_001DF360(D_004A28D0[0].f.f.b3, id);
    func_00184DF0(D_00201D48, -D_00201D58 / 2.0f);
    func_00184040(id, D_00201D58);
    func_00184960(s3 + 0x80, -D_00201D58 / 2.0f);
    if (D_004A28D0[0].f.f.b2) {
        func_0019A370(&a0, &x90, &x80, &x70, id);
        func_00186440(f, &a0, &x90, &x80, &x70);
        func_00185B30(0, 0);
    } else {
        if (func_001C9BF0()) func_0019A500(&c0, &b0, &eC, &e8, &e4, -1, -1, 0);
        if (D_002021B4 <= 0) func_0019A500(&x80, &x70, &eC, &e0, &dC, -1, -1, 0);
        else func_0019A500(&x80, &x70, &eC, &e0, &dC, D_00201D48, id, 0);
        for (i = 0; i < 8; i++) {
            x80.v[7 - i] -= c0.v[7 - i];
            x70.v[7 - i] -= b0.v[7 - i];
        }
        if (id == func_001CCD90(D_00201D48)) {
            func_00185B30(0, 0);
            func_00186440(f, &c0, &b0, 0, 0);
        } else {
            func_00185B30(e0 - e8, dC - e4);
            func_00186440(f, &c0, &b0, &x80, &x70);
        }
    }
    func_00185510(f, s2);
    func_00185B40(f, s1);
    if (D_004A28C4[0] == 1) D_002021BC = 10.0f;
    if (!(D_002021BC <= 0.0f)) {
        D_002021BC -= 1.0f;
        D_002021B8 = func_00187770(D_002021B8, -2.99f, 3.5f);
    } else {
        D_002021B8 = func_00187770(D_002021B8, -0.02f, 3.5f);
    }
    func_00185390(f + D_002021B8, 1, D_002021B4, D_004A28C0[0]);
    func_001DF470(f + D_002021B8, D_00201D48);
}
