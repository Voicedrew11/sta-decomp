#include "common.h"
typedef struct { u16 v[8]; } H;
extern s32 D_004A3320[];
extern s32 D_004A4330[];
extern s32 D_004A4334[];
extern Flags8 D_004A4340[];
extern s32 *D_00201D7C;
extern s32 D_00202224;
extern s32 D_00202238;
extern f32 D_00201D84;
extern f32 D_00201D88;
extern f32 D_00202228;
extern f32 D_0020222C;
H *func_001C9BA0(void);
s8 *func_001C9B60(void);
s32 func_001C9BF0(void);
f32 func_00187770(f32, f32, f32);
void func_001DD7F0(s32, s32, f32);
void func_001DF360(s32, s32);
void func_001DEB00(s32, s32, f32);
void func_00184960(void *, f32);
void func_001DE0D0(s32, f32);
void func_0019A370(H *, H *, H *, H *, s32);
void func_0019A500(H *, H *, s32 *, s32 *, s32 *, s32, s32, s32);
void func_00186440(f32, H *, H *, H *, H *);
void func_00185B30(s32, s32);
void func_00185510(f32, H *);
void func_00185B40(f32, s8 *);
s32 func_001CCD90(s32);
void func_00185390(f32, s32, s32, s32);
void func_001DF470(f32, s32);
static inline s32 cls(s32 x) {
    s32 r;
    switch (x) {
    case 0: r = 0; break;
    case 1: r = 0; break;
    case 2: r = 2; break;
    case 3: r = 2; break;
    case 4: r = 1; break;
    case 5: r = 2; break;
    case 6: r = 2; break;
    default: r = -1; break;
    }
    return r;
}
static inline s32 mp(s32 x) { if (x == 1) return 1; if (x == 9) return 100; return x; }

void func_001A1550(u8 *a0, f32 f) {
    s32 rFC;
    s32 rF8;
    s32 rF4;
    s32 rF0;
    s32 rEC;
    H d0;
    H c0;
    H b0;
    H a0_;
    H m90;
    H m80;
    s32 mode;
    H *s2;
    H *s1;
    s8 *s5;
    s32 id;
    s32 i;
    s32 x;
    f32 hi;
    f32 lo;

    mode = D_004A3320[0];
    s2 = func_001C9BA0();
    s1 = func_001C9BA0();
    s5 = func_001C9B60();
    id = D_00201D7C[D_004A4330[0]];
    if (D_00202224 <= 0) id = -1;
    if (a0[8] == 0x22) {
        if (D_004A4340[0].f.b2) {
            hi = 3.5f;
            D_00201D84 = func_00187770(D_00201D84, -0.02f, hi);
            lo = -2.99f;
            D_00201D88 = func_00187770(D_00201D88, lo, 3.5f);
        } else {
            hi = 3.5f;
            lo = -2.99f;
            D_00201D84 = func_00187770(D_00201D84, lo, hi);
            D_00201D88 = func_00187770(D_00201D88, -0.02f, 3.5f);
        }
    } else {
        hi = 3.5f;
        lo = -2.99f;
        D_00201D84 = func_00187770(D_00201D84, lo, hi);
        D_00201D88 = func_00187770(D_00201D88, -2.99f, 3.5f);
    }
    func_001DD7F0(id, mode, D_00201D84);
    func_001DF360(D_004A4340[0].f.b2, id);
    func_001DEB00(D_00202238, mode, -D_00201D88 / 2.0f);
    func_00184960((s8 *)s2 + 0x80, -D_00201D88 / 2.0f);
    func_001DE0D0(id, D_00201D88);
    if (D_004A4340[0].f.b3) {
        func_0019A370(&m90, &m80, &b0, &a0_, id);
        func_00186440(f, &m90, &m80, &b0, &a0_);
        func_00185B30(0, 0);
    } else {
        if (func_001C9BF0()) {
            func_0019A500(&d0, &c0, &rFC, &rF8, &rF4, -1, -1, 0);
        }
        if (D_00202224 <= 0) {
            func_0019A500(&b0, &a0_, &rFC, &rF0, &rEC, -1, -1, 0);
        } else {
            func_0019A500(&b0, &a0_, &rFC, &rF0, &rEC, D_00202238, id, cls(mode) != 2);
        }
        for (i = 0; i < 8; i++) {
            b0.v[7 - i] -= d0.v[7 - i];
            a0_.v[7 - i] -= c0.v[7 - i];
        }
        if (id == (s16)func_001CCD90(D_00202238)) {
            func_00185B30(0, 0);
            func_00186440(f, &d0, &c0, NULL, NULL);
        } else {
            func_00185B30(rF0 - rF8, rEC - rF4);
            func_00186440(f, &d0, &c0, &b0, &a0_);
        }
    }
    func_00185510(f, s1);
    func_00185B40(f, s5);
    if (D_004A4334[0] == 1) D_0020222C = 10.0f;
    if (D_0020222C > 0.0f) {
        D_0020222C -= 1.0f;
        D_00202228 = func_00187770(D_00202228, lo, hi);
    } else {
        D_00202228 = func_00187770(D_00202228, -0.02f, hi);
    }
    func_00185390(f + D_00202228, 1, D_00202224, D_004A4330[0]);
    func_001DF470(f + D_00202228, mp(D_00202238));
}
