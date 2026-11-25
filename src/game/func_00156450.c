#include "common.h"
typedef struct { Vec a; Vec b; s32 mode; u32 c0; u32 c1; s32 pad; } V;
void func_00123A88(void *, void *, s32);
void func_001DC348(void *);
void func_001DC398(void *, Vec *);
void func_00102A60(Vec *, Vec *);
f32 func_0011D778(f32);
f32 func_0011DA18(f32);

void func_00156450(void *p, u32 col, f32 h) {
    V v180;
    V v150;
    V v120;
    f32 sn[4];
    f32 cs[4];
    Vec f0;
    Vec e0;
    Vec d0;
    Vec c0;
    Vec b0;
    s32 i;
    s32 j;
    s32 k;
    f32 a;
    f32 b;
    s32 x;
    f32 tx;
    f32 ty;

    x = 0;
    if ((col >> 24) < 0x80) x = 1;
    v180.c0 = col;
    v180.c1 = col;
    v180.mode = ((u64)x << 6) | 2;
    func_00123A88(&v120, &v180, 0x30);
    func_00123A88(&v150, &v180, 0x30);
    func_001DC348(p);
    for (i = 0, a = 0.39269908f; i < 4; i++, a += 0.39269908f) {
        sn[i] = func_0011DA18(a);
        cs[i] = func_0011D778(a);
    }
    for (i = 0, a = 0.0f; i < 7; i++, a += 0.8975979f) {
        if (i != 0) {
            func_00123A88(&v180, &v180.b, 0x10);
        } else {
            tx = func_0011D778(a);
            ty = func_0011DA18(a);
            f0.x = tx;
            f0.y = ty;
            f0.z = 0.0f;
            f0.w = 1.0f;
            func_001DC398(&v180, &f0);
        }
        b = 0.8975979f + a;
        tx = func_0011D778(b);
        ty = func_0011DA18(b);
        e0.x = tx;
        e0.y = ty;
        e0.z = 0.0f;
        e0.w = 1.0f;
        func_001DC398(&v180.b, &e0);
        for (j = 0; j < 4; j++) {
            if (j == 0) {
                func_00123A88(&v150, &v180.b, 0x10);
            } else {
                func_00123A88(&v150, &v150.b, 0x10);
            }
            d0.x = e0.x * cs[j];
            d0.y = e0.y * cs[j];
            if (h < 0.0f) d0.z = sn[j];
            else d0.z = -sn[j];
            d0.w = 1.0f;
            func_001DC398(&v150.b, &d0);
        }
        if (h != 0.0f) {
            if (i != 0) {
                func_00123A88(&v120, &v120.b, 0x10);
            } else {
                func_00102A60(&c0, &f0);
                c0.z = h;
                func_001DC398(&v120, &c0);
            }
            func_00102A60(&b0, &e0);
            b0.z = h;
            func_001DC398(&v120.b, &b0);
            func_00123A88(&v150, &v180, 0x10);
            func_00123A88(&v150.b, &v120, 0x10);
            for (j = 0; j < 4; j++) {
                if (j == 0) {
                    func_00123A88(&v150, &v120.b, 0x10);
                } else {
                    func_00123A88(&v150, &v150.b, 0x10);
                }
                d0.x = b0.x * cs[j];
                d0.y = b0.y * cs[j];
                if (h < 0.0f) d0.z = b0.z - sn[j];
                else d0.z = b0.z + sn[j];
                d0.w = 1.0f;
                func_001DC398(&v150.b, &d0);
            }
        } else {
            for (j = 0; j < 4; j++) {
                if (j == 0) {
                    func_00123A88(&v150, &v180.b, 0x10);
                } else {
                    func_00123A88(&v150, &v150.b, 0x10);
                }
                d0.x = e0.x * cs[j];
                d0.y = e0.y * cs[j];
                d0.z = sn[j];
                d0.w = 1.0f;
                func_001DC398(&v150.b, &d0);
            }
        }
    }
}
