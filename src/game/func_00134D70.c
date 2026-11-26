#include "common.h"
u16 func_001409A0(s8 *, s32, f32 *, f32 *, f32 *);
void func_00145760(s8 *);
void func_00140470(s8 *, s8 *);
void func_00140350(s8 *, s8 *);
void func_00140310(s8 *, s8 *);
f32 *func_0013DCE0(s8 *);
void func_001456B0(Vec *);
void func_00145640(Vec *);
void func_001403D0(s8 *, Vec *);
void func_00140360(s8 *, Vec *);
s8 *func_0013DD10(s8 *);
s8 *func_00140460(s8 *);
u8 func_00143150(s8 *, s8 *, s8 *);
s8 *func_00143840(s8 *, u8);
void sceVu0AddVector(s8 *, s8 *, s8 *);
void func_00145720(s8 *);
void func_00140440(s8 *, s8 *);
s8 *func_00145730(void);
void sceVu0SubVector(Vec *, s8 *, s8 *);
f32 func_0013FC10(Vec *);
void func_00140330(s8 *, s8 *);
void func_00140300(s8 *, s8 *);
#define F(o) (*(f32 *)(a0 + (o)))

void func_00134D70(s8 *a0, s32 a1) {
    f32 x, y, z;
    u16 r;
    u8 lo, hi;
    r = func_001409A0(a0, a1, &x, &y, &z);
    lo = r & 0xFF;
    hi = r >> 8;
    switch (lo) {
    case 0: {
        f32 *p;
        func_00140470(a0, a0 + 0x620);
        p = func_0013DCE0(a0);
        F(0x620) = x;
        F(0x628) = y;
        if (p) {
            F(0x620) += p[0];
            F(0x628) += p[2];
        }
        break;
    }
    case 1:
        func_00145760(a0 + 0x620);
        break;
    case 2:
        func_00140470(a0, a0 + 0x620);
        break;
    case 3:
        func_00145760(a0 + 0x620);
        F(0x620) += x;
        F(0x628) += y;
        break;
    case 4:
        func_00140470(a0, a0 + 0x620);
        F(0x620) += x;
        F(0x628) += y;
        break;
    case 5: {
        Vec v;
        func_00145760(a0 + 0x620);
        func_001456B0(&v);
        F(0x620) += v.x * x;
        F(0x628) += v.z * x;
        func_00145640(&v);
        F(0x620) += v.x * y;
        F(0x628) += v.z * y;
        break;
    }
    case 6: {
        Vec v;
        func_00140470(a0, a0 + 0x620);
        func_001403D0(a0, &v);
        F(0x620) += v.x * x;
        F(0x628) += v.z * x;
        func_00140360(a0, &v);
        F(0x620) += v.x * y;
        F(0x628) += v.z * y;
        break;
    }
    case 7:
        break;
    case 8:
        func_00140350(a0, a0 + 0x620);
        break;
    case 9:
        func_00140350(a0, a0 + 0x620);
        F(0x620) += x;
        F(0x628) += y;
        break;
    case 10: {
        Vec v;
        func_00140350(a0, a0 + 0x620);
        func_001403D0(a0, &v);
        F(0x620) += v.x * x;
        F(0x628) += v.z * x;
        func_00140360(a0, &v);
        F(0x620) += v.x * y;
        F(0x628) += v.z * y;
        break;
    }
    case 11:
        func_00140310(a0, a0 + 0x620);
        break;
    case 12: {
        s8 *s3 = func_0013DD10(a0);
        s8 *s2 = (s8 *)func_0013DCE0(a0);
        func_00140350(a0, a0 + 0x620);
        if (s3) {
            u8 k = func_00143150(s3, s2, func_00140460(a0));
            if (k != 0xFF) {
                sceVu0AddVector(a0 + 0x620, func_00143840(s3, k), s2);
            }
        }
        break;
    }
    }
    switch (hi) {
    case 0:
        func_00140440(a0, a0 + 0x630);
        F(0x634) = z;
        break;
    case 1:
        func_00145720(a0 + 0x630);
        break;
    case 2:
        func_00140440(a0, a0 + 0x630);
        break;
    case 3: {
        Vec v;
        s8 *p = func_00145730();
        sceVu0SubVector(&v, p, func_00140460(a0));
        *(s32 *)&v.y = 0;
        F(0x634) = func_0013FC10(&v);
        break;
    }
    case 4: {
        Vec v;
        sceVu0SubVector(&v, func_00140460(a0), func_00145730());
        *(s32 *)&v.y = 0;
        F(0x634) = func_0013FC10(&v);
        break;
    }
    case 5:
        break;
    case 6:
        func_00140330(a0, a0 + 0x630);
        break;
    case 7:
        func_00140300(a0, a0 + 0x630);
        break;
    }
}
