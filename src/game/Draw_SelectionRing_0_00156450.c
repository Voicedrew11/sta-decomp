#include "common.h"
typedef struct { Vec a; Vec b; s32 mode; u32 c0; u32 c1; s32 pad; } V;
void memcpy(void *, void *, s32);
void Vu0_LoadMatrixVf1_3_001DC348(void *);
void Vu0_ProjectToScreen_5_001DC398(void *, Vec *);
void sceVu0CopyVector(Vec *, Vec *);
f32 cosf(f32);
f32 sinf(f32);

void Draw_SelectionRing_0_00156450(void *p, u32 col, f32 h) {
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
    memcpy(&v120, &v180, 0x30);
    memcpy(&v150, &v180, 0x30);
    Vu0_LoadMatrixVf1_3_001DC348(p);
    for (i = 0, a = 0.39269908f; i < 4; i++, a += 0.39269908f) {
        sn[i] = sinf(a);
        cs[i] = cosf(a);
    }
    for (i = 0, a = 0.0f; i < 7; i++, a += 0.8975979f) {
        if (i != 0) {
            memcpy(&v180, &v180.b, 0x10);
        } else {
            tx = cosf(a);
            ty = sinf(a);
            f0.x = tx;
            f0.y = ty;
            f0.z = 0.0f;
            f0.w = 1.0f;
            Vu0_ProjectToScreen_5_001DC398(&v180, &f0);
        }
        b = 0.8975979f + a;
        tx = cosf(b);
        ty = sinf(b);
        e0.x = tx;
        e0.y = ty;
        e0.z = 0.0f;
        e0.w = 1.0f;
        Vu0_ProjectToScreen_5_001DC398(&v180.b, &e0);
        for (j = 0; j < 4; j++) {
            if (j == 0) {
                memcpy(&v150, &v180.b, 0x10);
            } else {
                memcpy(&v150, &v150.b, 0x10);
            }
            d0.x = e0.x * cs[j];
            d0.y = e0.y * cs[j];
            if (h < 0.0f) d0.z = sn[j];
            else d0.z = -sn[j];
            d0.w = 1.0f;
            Vu0_ProjectToScreen_5_001DC398(&v150.b, &d0);
        }
        if (h != 0.0f) {
            if (i != 0) {
                memcpy(&v120, &v120.b, 0x10);
            } else {
                sceVu0CopyVector(&c0, &f0);
                c0.z = h;
                Vu0_ProjectToScreen_5_001DC398(&v120, &c0);
            }
            sceVu0CopyVector(&b0, &e0);
            b0.z = h;
            Vu0_ProjectToScreen_5_001DC398(&v120.b, &b0);
            memcpy(&v150, &v180, 0x10);
            memcpy(&v150.b, &v120, 0x10);
            for (j = 0; j < 4; j++) {
                if (j == 0) {
                    memcpy(&v150, &v120.b, 0x10);
                } else {
                    memcpy(&v150, &v150.b, 0x10);
                }
                d0.x = b0.x * cs[j];
                d0.y = b0.y * cs[j];
                if (h < 0.0f) d0.z = b0.z - sn[j];
                else d0.z = b0.z + sn[j];
                d0.w = 1.0f;
                Vu0_ProjectToScreen_5_001DC398(&v150.b, &d0);
            }
        } else {
            for (j = 0; j < 4; j++) {
                if (j == 0) {
                    memcpy(&v150, &v180.b, 0x10);
                } else {
                    memcpy(&v150, &v150.b, 0x10);
                }
                d0.x = e0.x * cs[j];
                d0.y = e0.y * cs[j];
                d0.z = sn[j];
                d0.w = 1.0f;
                Vu0_ProjectToScreen_5_001DC398(&v150.b, &d0);
            }
        }
    }
}
