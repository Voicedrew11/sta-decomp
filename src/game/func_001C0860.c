#include "m2c.h"
extern f32 D_001F2170[];
void func_001ADC60(s32, f32 (*)[4]);
void sceVu0CopyVector(f32 *, f32 *);
void func_0015E290(f32 *, f32 (*)[4]);
void func_001C0660(f32 (*)[4], s32, s32, u32);
void sceVu0InterVector(f32 *, f32 *, f32 *, f32);
void func_001ADBA0(s32, f32 *);
void sceVu0CopyMatrix(f32 (*)[4], void *);
void func_0015DFA0(f32 *, f32 *, f32 *, f32);
void func_0015E180(f32 (*)[4], f32 *);
void sceVu0MulMatrix(f32 (*)[4], f32 (*)[4], f32 (*)[4]);

void func_001C0860(f32 (*out)[4], s32 a1, u32 a2, s32 flag, f32 t) {
    f32 m[4][4] __attribute__((aligned(16)));
    f32 c[4] __attribute__((aligned(16)));
    f32 b[4] __attribute__((aligned(16)));
    f32 q1[4] __attribute__((aligned(16)));
    f32 q2[4] __attribute__((aligned(16)));
    f32 s[4] __attribute__((aligned(16)));
    f32 q[4] __attribute__((aligned(16)));
    f32 v[4] __attribute__((aligned(16)));

    if (flag == 0) {
        func_001ADC60(a1, m);
        sceVu0CopyVector(c, m[3]);
        func_0015E290(q1, m);
        func_001C0660(m, a1, 0, a2);
        sceVu0CopyVector(b, m[3]);
        func_0015E290(q2, m);
        sceVu0InterVector(v, b, c, t);
        v[3] = 1.0f;
        func_001ADBA0(a1, s);
        sceVu0CopyMatrix(m, D_001F2170);
        m[0][0] = s[0];
        m[1][1] = s[1];
        m[2][2] = s[2];
        func_0015DFA0(q, q1, q2, t);
        func_0015E180(out, q);
        sceVu0MulMatrix(out, m, out);
        sceVu0CopyVector(out[3], v);
    } else {
        func_001C0660(m, a1, 0, a2);
        sceVu0CopyVector(c, m[3]);
        func_001C0660(m, a1, 1, a2);
        sceVu0CopyVector(b, m[3]);
        sceVu0InterVector(v, b, c, t);
        v[3] = 1.0f;
        sceVu0CopyMatrix(out, m);
        sceVu0CopyVector(out[3], v);
    }
}
