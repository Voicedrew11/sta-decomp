#include "m2c.h"
extern f32 D_00222850[];
extern f32 D_003139A0[];
extern f32 D_001F2170[];
void func_001028F8(f32 (*)[4], f32 *);
void func_00102A60(f32 *, f32 *);
void func_001027B0(f32 *, f32 (*)[4], f32 *);
void func_001029D0(f32 *, f32 *, f32 *);
void func_00102A70(f32 (*)[4], f32 *);
void func_001ADBA0(s32, f32 *);
void func_00102CC8(f32 (*)[4], f32 (*)[4], f32);
void func_001027E0(f32 *, f32 (*)[4], f32 (*)[4]);
#define WRAP(x) ((((3.1415927f + (x)) - 6.2831855f * (s32)(0.15915494f * (3.1415927f + (x)))) + ((3.1415927f + (x)) < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f)

void func_001C0660(f32 *out, s32 a1, s32 flag, u32 n) {
    f32 m2[4][4] __attribute__((aligned(16)));
    f32 m1[4][4] __attribute__((aligned(16)));
    f32 w[4] __attribute__((aligned(16)));
    f32 v[4] __attribute__((aligned(16)));
    f32 ang;

    ang = -12.0f * (3.1415927f * n) / 180.0f;
    func_001028F8(m1, D_00222850);
    func_00102A60(w, D_003139A0);
    w[2] = 180.0f;
    w[1] = 30.0f;
    func_001027B0(w, m1, w);
    func_001029D0(m1[3], m1[3], w);
    func_00102A70(m2, D_001F2170);
    func_001ADBA0(a1, v);
    m2[0][0] = v[0];
    m2[1][1] = v[1];
    m2[2][2] = v[2];
    func_00102CC8(m2, m2, WRAP(ang));
    m1[3][3] = 1.0f;
    if (flag != 0) {
        m2[3][2] -= 150.0f;
        m2[3][0] += 70.0f;
        m2[3][1] += 150.0f;
    }
    func_001027E0(out, m1, m2);
}
