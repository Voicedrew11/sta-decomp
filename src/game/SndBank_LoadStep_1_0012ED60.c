#include "m2c.h"
typedef struct { s32 a; s32 b; } H;
typedef struct { s32 st; s32 pad[3]; } S;
extern S D_0022F040[];
extern s8 D_0022EBC0[];
extern s8 D_0022EBC8[];
s32 SndBank_IopTransferC_0_0012F3A0(H *, u32);
s32 SndBank_IopTransferB_0_0012F0F0(H *, u32);
s32 SndBank_IopTransferA_0_0012EF40(H *, u32);
s32 Se_SetChannel_0_001DAEF0(u32, s8, s32);
s32 Se_BindBank_0_001DA9A0(s8, s8);

s32 SndBank_LoadStep_1_0012ED60(H *a0, u32 idx) {

    H *s3;
    H *s2;
    s32 ret;
    s32 r;
    S *s0;
    s32 x0, x1, x2;

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
        r = SndBank_IopTransferC_0_0012F3A0(a0, idx);
        if (r == 1) {
            s0->st = 1;
        } else if (r == 0) {
            ret = 0;
            break;
        } else {
            break;
        }
    case 1:
        r = SndBank_IopTransferB_0_0012F0F0(s3, idx);
        if (r == 1) {
            s0->st = 2;
        } else if (r == 0) {
            ret = 0;
            break;
        } else {
            break;
        }
    case 2:
        if (Se_SetChannel_0_001DAEF0(idx, D_0022EBC0[idx], 0) == -1) break;
        s0->st = 3;
    case 3:
        r = SndBank_IopTransferA_0_0012EF40(s2, idx);
        if (r == 1) {
            s0->st = 4;
        } else if (r == 0) {
            ret = 0;
            break;
        } else {
            break;
        }
    case 4:
        if (Se_BindBank_0_001DA9A0(D_0022EBC8[idx], D_0022EBC0[idx]) == -1) break;
        s0->st = 5;
    case 5:
        s0->st = 0;
        ret = 1;
        break;
    default:
        s0->st = 0;
        break;
    }
    return ret;
}
