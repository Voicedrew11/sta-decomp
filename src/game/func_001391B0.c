#include "m2c.h"
typedef struct { u8 b0:1; u8 b1:1; u8 rest:6; } BFa;
typedef struct { s8 pad[0x31]; BFa f31; } A2;
typedef struct { s32 a, b, c; f32 dist; s8 pad[0x3C - 0x10]; } R;
s32 func_0013D6B0(void);
s32 func_0013EE30(s8 *);
void func_001C7850(s32, A2 *);
s8 *func_001A5460(s32 *);
u8 func_001C7320(s8 *);
s32 func_00138CA0(s8 *, s32, s8 *, R *);
void func_00138FB0(s8 *, A2 *, s8 *, u8);

void func_001391B0(s8 *arg0, s32 arg1, A2 *arg2) {
    s32 it;
    R r;
    f32 best;
    s8 *bestObj;
    s32 bestRes;
    s8 *cur;
    s32 res;

    if (func_0013D6B0() == 0) {
        if (func_0013EE30(arg0) != 0) {
            func_001C7850(arg1, arg2);
        }
        best = 2.0f;
        it = 0;
        bestObj = NULL;
        bestRes = 0;
        cur = func_001A5460(&it);
        while (cur != NULL) {
            res = -1;
            if (func_0013EE30(arg0) != 0 && arg2->f31.b1 == 0) {
                if (func_001C7320(cur) <= 0) {
                    res = func_00138CA0(arg0, arg1, cur, &r);
                }
            } else {
                res = func_00138CA0(arg0, arg1, cur, &r);
            }
            if (res != -1) {
                if (!(best <= r.dist)) {
                    bestObj = cur;
                    bestRes = res;
                    best = r.dist;
                }
            }
            cur = func_001A5460(&it);
        }
        func_00138FB0(arg0, arg2, bestObj, bestRes);
    }
}
