#include "m2c.h"
typedef struct { u8 b0:1; u8 b1:1; u8 rest:6; } BFa;
typedef struct { s8 pad[0x31]; BFa f31; } A2;
u8 func_0013D6B0(void);
s32 func_0013EE30(s8 *);
s32 func_001C99A0(void);
void func_001C7DC0(A2 *);
s32 func_001C8070(A2 *, s8 *);
void func_0013EB70(s8 *, s32);
u8 func_0013E220(s8 *);
void func_001423E0(s8 *, u8);
void func_0013C7B0(s8 *);
s32 func_00135E90(s8 *, s32, A2 *, u8, s32 *);
u8 func_0013F620(s8 *);
void func_00142320(s8 *, u8, u8);
void func_001C73B0(s8 *, s32, s32, u8);
void func_001C73C0(s8 *, s32, s32, u8);

void func_00138FB0(s8 *a0, A2 *a1, s8 *a2, s32 a3) {
    u8 r;
    u8 q;
    s32 out;

    if (func_0013D6B0()) return;
    if (a2 == 0) return;
    if (func_0013EE30(a2)) {
        r = 1;
        if (func_001C99A0()) return;
        if (a1->f31.b1) {
            func_001C7DC0(a1);
        } else {
            r = (u8)func_001C8070(a1, a0);
        }
        if (a0 == 0) return;
        if (func_0013EE30(a0)) return;
        func_0013EB70(a0, 0);
        if (r) {
            func_001423E0(a0, func_0013E220(a2));
        } else {
            func_0013C7B0(a0);
        }
    } else {
        r = (u8)func_00135E90(a2, a3, a1, func_0013E220(a0), &out);
        q = func_0013F620(a2);
        func_00142320(a2, func_0013E220(a0), q);
        if (a0 == 0) return;
        if (!r) return;
        if (func_0013EE30(a0)) {
            if (a1->f31.b1) {
                func_001C73B0(a2, out, a3, (u8)r - 1);
            } else {
                func_001C73C0(a2, out, a3, (u8)r - 1);
            }
        } else {
            func_0013EB70(a0, 0);
            func_001423E0(a0, func_0013E220(a2));
        }
    }
}
