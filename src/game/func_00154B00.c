#include "m2c.h"
void func_001549D0(s32);
extern s32 D_002F1990[];
extern s32 D_002F1994[];
typedef struct { u32 w0, w1, w2, w3; } T4;

void func_00154B00(s32 arg0) {
    T4 t;
    u128 *p = (u128 *)D_002F1994[0];
    if (p == 0) {
        p = (u128 *)D_002F1990[0];
        D_002F1994[0] = (s32)p;
    }
    *(u128 *)&t = 0;
    D_002F1994[0] += 0x10;
    t.w0 = 0x30000010;
    t.w1 = arg0;
    t.w3 = 0x6C100000;
    *p = *(u128 *)&t;
    func_001549D0(arg0);
}
