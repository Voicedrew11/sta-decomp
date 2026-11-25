#include "m2c.h"
typedef struct { s32 a; s32 b; s32 c8; s32 c; } H;
typedef struct { s32 st; s32 pad[3]; } S;
typedef struct { s32 x0; s32 x4; s32 x8; u16 xC; u16 xE; } B;
extern S D_0022F040[];
extern s8 D_00222BC0[];
extern s8 D_00222BC1[];
extern s8 D_00222BC4[];
extern s8 D_00222BC5[];
extern u8 D_0022EBD9[];
extern u8 D_0022F090[];
s32 func_001D8FC0(void *, void *, void *, s32, s8, s8, B *);
void func_001789E0(void *, s32, s32);
s32 func_001D98D0(s32, void *, s32, s32, u16, u16);
s32 func_001D9820(u16, u16);
s32 func_001D8FB0(void);
#define DATA(h) ((u8 *)((s32)(h) + 0x10) + (((h)->c + 15) & ~15))

s32 func_0012EA00(H *a0, u32 idx) {
    H *s3;
    H *s2;
    s32 ret;
    S *s0;
    s32 x0, x1, x2;
    B b;
    u16 v;

    s0 = &D_0022F040[idx];
    s3 = (H *)((u8 *)a0 + a0->a);
    s2 = (H *)((u8 *)s3 + s3->a);
    x0 = a0->b;
    x1 = s3->b;
    x2 = s2->b;
    if (x0 == 0 || x1 == 0 || x2 == 0) return -1;
    ret = -1;
    switch (s0->st) {
    case 0:
        if (func_001D8FC0(DATA(s2), DATA(a0), DATA(s3), x1, D_00222BC0[0], D_00222BC1[0], &b) == 0) {
            s0->st = 0;
            break;
        }
        func_001789E0(D_0022F090, b.x0, ((b.x8 + 15) & ~15) >> 4);
        if (func_001D98D0(0, D_0022F090, b.x8, b.x4, b.xC, b.xE) == 0) {
            s0->st = 0;
            break;
        }
        s0->st = 1;
        ret = 0;
        break;
    case 1:
        v = D_0022EBD9[0] * 129;
        if (func_001D9820(v, v) == 0) {
            s0->st = 0;
            break;
        }
        s0->st = 2;
        ret = 0;
        break;
    case 2:
        if (func_001D8FB0() == 7) {
            s0->st = 3;
        } else {
            ret = 0;
            break;
        }
    case 3:
        if (func_001D8FC0(DATA(s2), DATA(a0), DATA(s3), x1, D_00222BC4[0], D_00222BC5[0], &b) == 0) {
            s0->st = 0;
            break;
        }
        func_001789E0(D_0022F090, b.x0, ((b.x8 + 15) & ~15) >> 4);
        if (func_001D98D0(1, D_0022F090, b.x8, b.x4, b.xC, b.xE) == 0) {
            s0->st = 0;
            break;
        }
        s0->st = 4;
        ret = 0;
        break;
    case 4:
        v = D_0022EBD9[0] * 129;
        func_001D9820(v, v);
        s0->st = 5;
        ret = 0;
        break;
    case 5:
        if (func_001D8FB0() == 7) {
            s0->st = 6;
        } else {
            ret = 0;
            break;
        }
    case 6:
        s0->st = 0;
        ret = 1;
        break;
    default:
        s0->st = 0;
        break;
    }
    return ret;
}
