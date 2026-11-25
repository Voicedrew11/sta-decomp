#include "m2c.h"
typedef union { u128 q; u64 d[2]; u32 w[4]; f32 f[4]; } Q;
typedef struct { s32 x0; s32 x4; } A0;
typedef struct { f32 x[4]; f32 f10; f32 f14; f32 f18; f32 f1C; } A3;
s32 func_00154A80(s32);
void func_00123C40(s32, s32, s32);
void func_00154A70(void);
void func_00176AE0(void);

void func_001323C0(A0 *a0, u32 a1, u32 a2, A3 *a3) {
    Q *p;
    Q q;
    f32 f;

    p = (Q *)func_00154A80(0x23);
    func_00123C40((s32)p, 0, 0x230);
    q.q = 0;
    q.w[0] = 0x10000022;
    q.w[3] = 0x6C228121;
    p[0].q = q.q;
    q.d[0] = 0x8001 | ((u64)0x24000 << 32);
    q.d[1] = 0x4E4E4E44 | ((u64)0x4E4E44E4 << 32);
    p[1].q = q.q;
    p[0x12].q = q.q;
    q.w[0] = a0->x4 - 1;
    q.w[1] = 0x11;
    q.w[2] = 0;
    q.w[3] = 0;
    p[2].q = q.q;
    q.d[0] = 0x240;
    q.d[1] = 0x1B;
    p[4].q = q.q;
    q.d[0] = 0x40;
    q.d[1] = 0x1B;
    p[6].q = q.q;
    q.f[0] = 1728.0f;
    q.f[1] = 1824.0f;
    q.w[2] = 0;
    q.w[3] = 0;
    p[3].q = q.q;
    q.f[0] = (f32)a1 / 640.0f;
    q.f[1] = (f32)a2 / 448.0f;
    q.f[2] = 1.0f;
    q.f[3] = 1.0f;
    p[5].q = q.q;
    f = a3->f1C;
    q.f[0] = a3->f10 * f;
    q.f[1] = a3->f14 * f;
    q.f[2] = a3->f18 * f;
    q.f[3] = f;
    p[0x11].q = q.q;
    func_00154A70();
    func_00176AE0();
}
