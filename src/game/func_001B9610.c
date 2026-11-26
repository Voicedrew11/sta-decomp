#include "common.h"
#define WRAP(x) ((((3.1415927f + (x)) - 6.2831855f * (s32)(0.15915494f * (3.1415927f + (x)))) + ((3.1415927f + (x)) < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f)
typedef struct { f32 m[4][4]; } MtxF;
typedef struct { f32 a[4]; f32 b[4]; } Ray;
typedef struct { s32 w[16]; } Res;
typedef struct { u8 pad[0x18]; u16 x18; u8 pad1A[0x16]; } E30;
typedef struct { u8 pad[0xC]; u16 xC; u16 xE; u8 pad10[2]; Flags8 f12; Flags8 f13; u8 pad14[0x2C]; } E40;
typedef struct { u8 pad[0x40]; s32 x40; u8 pad44[0xC]; u8 x50; u8 pad51; Flags8 f52; u8 pad53[0x2D]; } E80;
typedef struct { u8 pad[0x138]; E30 *x138; u8 pad13C[0x34]; E40 *x170; u8 pad174[0xC]; E80 *x180; } S;
typedef struct { u8 pad[0x18]; Vec *o; } P;
extern MtxF D_001F2170;
extern Vec D_003139A0;
u8 *func_001715B0(s32);
P *func_001C9B60(void);
void func_001C9410(f32 *);
void func_001029E8(f32 *, f32 *, void *);
f32 func_00102848(f32 *, f32 *);
void func_00102A70(MtxF *, void *);
void func_00102A60(void *, void *);
void func_001028F8(MtxF *, MtxF *);
void func_001027B0(f32 *, MtxF *, f32 *);
f32 func_0011DBC0(f32, f32);
f32 func_0011D850(f32);
void func_00102A18(f32 *, f32 *, f32);
void func_00102C20(MtxF *, MtxF *, f32);
void func_00102B78(MtxF *, MtxF *, f32);
void func_00102CC8(MtxF *, MtxF *, f32);
void func_001029D0(f32 *, void *, f32 *);
void func_00123C40(void *, s32, s32);
s32 func_001B2800(S *, Res *, Ray *, u16, s32, s32);
f32 sqrtf(f32);
static inline f32 u2f(u32 x) { return x; }

s32 func_001B9610(S *a, s32 idx) {
    f32 v140[4];
    f32 v130[4];
    f32 v120[4];
    MtxF m;
    Res res;
    Ray ray;
    E80 *s5;
    E40 *s4;
    u8 *s2;
    P *p;
    f32 d;

    s5 = &a->x180[idx];
    s4 = &a->x170[*(u16 *)((u8 *)a->x138 + idx * 0x30 + 0x18)];
    s2 = func_001715B0(s5->x40);
    p = func_001C9B60();
    if (p == 0) return 0;
    if (!s5->f52.f.b3) return 0;
    if (s5->x50 & 3) return 0;
    func_001C9410(v140);
    func_001029E8(v120, v140, s2 + 0x230);
    if (!s4->f13.f.b3) v120[1] = 0.0f;
    d = sqrtf(func_00102848(v120, v120));
    if (!(d <= u2f(s4->xE))) return 0;
    func_00102A70(&m, s2 + 0x200);
    func_00102A60(m.m[3], &D_003139A0);
    m.m[3][3] = 1.0f;
    func_001028F8(&m, &m);
    func_001027B0(v130, &m, v120);
    d = func_0011D850(func_0011DBC0(-v130[0], -v130[2]));
    if (!(d <= 3.1415927f * u2f(s4->xC) / 180.0f)) return 0;
    if (!s4->f12.f.b6) {
        func_00102A18(v120, v120, -1.0f);
        d = func_0011DBC0(-v120[0], -v120[2]) - WRAP(p->o[2].y);
        if (func_0011D850(WRAP(d)) <= 0.5235988f) return 1;
    } else {
        func_00102C20(&m, &D_001F2170, WRAP(WRAP(p->o[2].x)));
        func_00102B78(&m, &m, WRAP(WRAP(p->o[2].z)));
        func_00102CC8(&m, &m, WRAP(WRAP(3.1415927f + p->o[2].y)));
        v130[0] = 0.0f;
        v130[1] = 0.0f;
        v130[2] = u2f(s4->xE);
        v130[3] = 1.0f;
        func_001027B0(v130, &m, v130);
        func_00102A60(ray.a, p->o);
        func_001029D0(ray.b, p->o, v130);
        func_00123C40(&res, 0, 0x40);
        if (func_001B2800(a, &res, &ray, idx, 6, 1)) return 1;
    }
    return 0;
}
