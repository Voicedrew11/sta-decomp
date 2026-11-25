#include "m2c.h"
#include "actor.h"
void func_0014DAD0(s32);
s32 func_0014DAF0(s32);
void func_0014DAA0(void);
s32 func_0014DA90(s32, s32, s32, s32);
s32 func_0014DA80(s32, s32);
void func_001B6FC0(s32);
void func_001B6FB0(s32);
void func_001B4BD0(s32, s32 *);
extern s32 D_004B4B90[];
extern s32 D_004B4BB0[];
extern s32 D_004B4BB4[];
extern s32 D_004B4BB8[];
extern s16 D_004B4BBC[];
extern s16 D_004B4BBE[];
extern s32 D_004B4BC0[];
extern s32 D_004B4BC4[];
extern s32 D_004B4BC8[];
static inline void reset(void) {
    if (D_004B4BC0[0] != 0) {
        func_0014DAD0(D_004B4BC0[0]);
        D_004B4BC0[0] = 0;
    }
    D_004B4BB8[0] = 0;
    D_004B4BC0[0] = 0;
    D_004B4BB4[0] = -1;
    D_004B4BB0[0] = -1;
    D_004B4BBC[0] = 0;
    D_004B4BC4[0] = 0;
    D_004B4BBE[0] = 0;
}
static inline s32 status(void) {
    s32 r = 0;
    if (D_004B4BC0[0] != 0) r = func_0014DAF0(D_004B4BC0[0]);
    return r;
}

void func_001B0450(void) {
    s8 *p;
    s32 x;
    if (D_004B4BB4[0] != -1) {
        if ((u8)status() != 3 && (u8)status() != 6) {
            while (!D_004B4BBC[0]) {
                func_0014DAA0();
            }
        } else if (D_004B4BBC[0] == 0) {
            x = **(s32 **)(*(s8 **)D_004B4BC4[0] + 0x24);
            if (D_004B4BBE[0] == 0) {
                if (func_0014DA90(D_004B4BC0[0], x, x, D_004B4BC8[0])) {
                    D_004B4BBE[0] = 1;
                }
            }
            if (D_004B4BBE[0]) {
                while (func_0014DA80(D_004B4BC0[0], 2)) {
                }
            }
            func_001B6FC0(D_004B4BC4[0]);
            func_001B4BD0(*(s32 *)D_004B4BC4[0], D_004B4B90);
        }
        p = *(s8 **)D_004B4BC4[0];
        func_001B6FB0(D_004B4BC4[0]);
        ((Flags8_6x2 *)(**(s8 ***)*(s8 **)(p + 0x178) + 0x24))->f.b6 = 1;
        reset();
    }
}
