#include "common.h"
extern s8 *D_00201FA8;
s8 *func_00165130(s8 *, s32);
s8 func_001CA960(void);
s8 func_001CAB20(s16, u8, Vec *, Vec *);
void func_00140470(s8 *, Vec *);
void func_001403D0(s8 *, Vec *);
void func_00140360(s8 *, Vec *);
void func_00140440(s8 *, Vec *);

void func_00144A00(s8 *a0) {
    Vec A;
    Vec B;
    Vec C;
    s8 *o = *(s8 **)(D_00201FA8 + 0x154);
    u16 id = *(u16 *)(a0 + 8);
    s32 k = *(u8 *)(a0 + 0x10);
    s8 *res = func_00165130(a0, 2);
    f32 f1 = *(f32 *)(a0 + 0x20);
    f32 f2 = *(f32 *)(a0 + 0x28);
    f32 f3 = *(f32 *)(a0 + 0x30);
    s8 r = func_001CA960();
    if (r == -1) {
        func_00140470(o, &A);
        func_001403D0(o, &B);
        A.x = A.x + B.x * f1;
        A.z = A.z + B.z * f1;
        A.y = A.y + f2;
        func_00140360(o, &B);
        A.x = A.x + B.x * f3;
        A.z = A.z + B.z * f3;
        func_00140440(o, &C);
        r = func_001CAB20(id, k, &A, &C);
    }
    if (r == 0) {
        *res = 0;
    } else {
        *res = 1;
    }
}
