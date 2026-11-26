#include "actor.h"
typedef struct { Vec a; Vec b; u8 pad20[4]; s32 x24; u8 pad28[0x18]; } Big;
void sceVu0CopyVector(void *, void *);
void sceVu0AddVector(Vec *, Vec *, void *);
void sceVu0SubVector(Vec *, Vec *, Vec *);
void sceVu0ScaleVector(Vec *, Vec *, f32);
void memset(void *, s32, s32);
void func_00137730(Actor *, Vec *);
s32 func_00138920(Actor *, u8, s32, s32, Vec *, s32);
void func_0013D250(s32, Big *, Vec *, u8, u8);
void func_0013E670(Actor *, s32);
u8 func_0013FC00(Actor *);
u32 func_0013E750(Actor *);
u32 func_0013E880(Actor *);
u32 func_0013E8E0(Actor *);
extern s32 D_00201E80;
typedef struct { u8 pad[0x2AC]; u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; u8 b4:1; u8 b5:1; } Sub4B0;

void func_0013A450(Actor *a) {
    u8 found;
    s8 *base = a->unk518 + 0x180;
    s32 m1 = 1;
    s32 m2 = 2;
    s8 i;
    f32 *w;
    s32 n;
    s32 ok;
    Vec A = {0};

    sceVu0CopyVector(&a->pad60C[0x94], &A);
    if (((Sub4B0 *)a->unk4B0)->b5 && !func_0013E880(a)) {
        if (!func_0013E8E0(a)) {
            m1 |= 2;
        }
        if (!(u8)func_0013E750(a)) {
            m2 |= 0x10;
        }
        {
        Vec E = {0};
        Vec C[2];
        Big B;
        found = 0;
        n = func_0013FC00(a);
        if (n > 0) {
            w = &A.w;
            for (i = n - 1; i >= 0; i--) {
                ok = (u8)func_00138920(a, i, m2, m1, &A, 1);
                *w = 0.0f;
                if (ok) {
                    *w = 0.0f;
                    sceVu0AddVector((Vec *)(base + 0x40), (Vec *)(base + 0x40), &A);
                    func_00137730(a, &A);
                    func_0013E670(a, 1);
                    sceVu0CopyVector(&a->pad60C[0x94], &A);
                }
            }
        } else {
            sceVu0CopyVector(C, base + 0x40);
            C[0].y -= 100.0f;
            w = &C[0].w;
            *w = 100.0f;
            memset(&B, 0, 0x40);
            if ((&D_00201E80)[2]) {
                func_0013D250(*(s32 *)(&D_00201E80)[2], &B, C, m2, m1);
            }
            if ((&D_00201E80)[3]) {
                func_0013D250(*(s32 *)(&D_00201E80)[3], &B, C, m2, m1);
            }
            if (B.x24) {
                sceVu0ScaleVector(&E, &B.b, *w);
                sceVu0AddVector(&E, &E, &B);
                sceVu0SubVector(&E, &E, C);
                found = 1;
            }
        }
        if (found) {
            E.y = 0.0f;
            E.w = 0.0f;
            sceVu0AddVector((Vec *)(base + 0x40), (Vec *)(base + 0x40), &E);
            func_00137730(a, &E);
            func_0013E670(a, 1);
        }
        }
    }
}
