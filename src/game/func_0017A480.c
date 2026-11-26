#include "common.h"
f32 sqrtf(f32);
void func_0013DD50(char *, f32 *, f32 *);
void func_00145780(Vec *);
void func_00140470(char *, Vec *);
void sceVu0SubVector(Vec *, Vec *, Vec *);
f32 sceVu0InnerProduct(Vec *, Vec *);
f32 cosf(f32);
void func_001456B0(Vec *);
void func_001403D0(char *, Vec *);

s32 func_0017A480(char *a0, f32 *a1, f32 *a2) {
    f32 bc;
    f32 b8;
    Vec va0;
    Vec v90;
    Vec v80;
    Vec v70;
    Vec v60;
    f32 len;
    f32 c;
    f32 d;
    u8 r = 0;

    func_0013DD50(a0, &bc, &b8);
    func_00145780(&va0);
    func_00140470(a0, &v90);
    va0.y = 0.0f;
    v90.y = 0.0f;
    sceVu0SubVector(&v80, &v90, &va0);
    len = sqrtf(sceVu0InnerProduct(&v80, &v80));
    if (a1) *a1 = len;
    if (len < bc) {
        c = cosf(1.0471976f);
        func_001456B0(&v70);
        if (!(len <= 0.0f)) {
            v80.x /= len;
            v80.y /= len;
            v80.z /= len;
        }
        d = sceVu0InnerProduct(&v80, &v70);
        if (a2) *a2 = d;
        if (!(d <= c)) {
            c = cosf(1.0471976f);
            v80.x = -v80.x;
            v80.y = -v80.y;
            v80.z = -v80.z;
            func_001403D0(a0, &v60);
            if (!(sceVu0InnerProduct(&v80, &v60) <= c)) r = 1;
        }
    }
    return r;
}
