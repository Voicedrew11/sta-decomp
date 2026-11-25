#include "m2c.h"
typedef struct { f32 x, y, z, w; } Vec;
f32 func_0011DA18(f32);
f32 func_0011DB90(f32);
u64 func_0011F8C0(f32);
u64 func_0011D200(u64);
s32 func_001001E0(u64, u64);
void func_00102A60(Vec *, Vec *);
void func_0015DFA0(Vec *out, Vec *a, Vec *b, f32 t) {
    Vec A;
    Vec B;
    f32 *pay, *paz, *paw, *pby, *pbz, *pbw;
    f32 s;
    f32 inv;
    f32 k1;
    f32 k2;
    if (!func_001001E0(0x3E80000000000000ULL, func_0011D200(func_0011F8C0(func_0011DA18(a->x * b->x + a->y * b->y + a->z * b->z + a->w * b->w))))) {
        func_00102A60(&A, a);
        func_00102A60(&B, b);
        pay=&A.y;paz=&A.z;paw=&A.w;pby=&B.y;pbz=&B.z;pbw=&B.w;
        s = func_0011DB90(A.x * B.x + *pay * *pby + *paz * *pbz + *paw * *pbw);
        inv = 1.0f / func_0011DA18(s);
        k1 = func_0011DA18((1.0f - t) * s);
        k2 = func_0011DA18(t * s);
        out->x = inv * (A.x * k1 + B.x * k2);
        out->y = inv * (*pay * k1 + *pby * k2);
        out->z = inv * (*paz * k1 + *pbz * k2);
        out->w = inv * (*paw * k1 + *pbw * k2);
    }
}
