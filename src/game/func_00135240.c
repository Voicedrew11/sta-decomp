#include "m2c.h"
typedef struct { f32 x, y, z, w; } V;
u16 func_001416B0(s8 *, s32, s32 *, s32 *, s32 *);
void func_00145760(s8 *);
void func_00140470(s8 *, s8 *);
void func_00140350(s8 *, s8 *);
void func_00140310(s8 *, s8 *);
s8 *func_0013DD10(s8 *);
s8 *func_0013DCE0(s8 *);
s8 *func_00140460(s8 *);
u8 func_00143150(s8 *, s8 *, s8 *);
s8 *func_00143840(s8 *, u8);
void sceVu0AddVector(s8 *, s8 *, s8 *);
void func_00145720(s8 *);
void func_00140440(s8 *, s8 *);
s8 *func_00145730(void);
void sceVu0SubVector(V *, s8 *, s8 *);
f32 func_0013FC10(V *);
void func_00140330(s8 *, s8 *);
void func_00140300(s8 *, s8 *);

void func_00135240(s8 *a0, s32 a1) {
    s32 x, y, z;
    u16 r;
    u8 lo, hi;
    r = func_001416B0(a0, a1, &x, &y, &z);
    lo = r & 0xFF;
    hi = r >> 8;
    switch (lo) {
    case 1:
        func_00145760(a0 + 0x620);
        break;
    case 2:
        func_00140470(a0, a0 + 0x620);
        break;
    case 7:
        break;
    case 8:
        func_00140350(a0, a0 + 0x620);
        break;
    case 11:
        func_00140310(a0, a0 + 0x620);
        break;
    case 12: {
        s8 *s3 = func_0013DD10(a0);
        s8 *s2 = func_0013DCE0(a0);
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
        break;
    case 1:
        func_00145720(a0 + 0x630);
        break;
    case 2:
        func_00140440(a0, a0 + 0x630);
        break;
    case 3: {
        V v;
        s8 *p = func_00145730();
        sceVu0SubVector(&v, p, func_00140460(a0));
        *(s32 *)&v.y = 0;
        *(f32 *)(a0 + 0x634) = func_0013FC10(&v);
        break;
    }
    case 4: {
        V v;
        sceVu0SubVector(&v, func_00140460(a0), func_00145730());
        *(s32 *)&v.y = 0;
        *(f32 *)(a0 + 0x634) = func_0013FC10(&v);
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
