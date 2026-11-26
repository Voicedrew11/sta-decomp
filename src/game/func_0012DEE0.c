#include "common.h"
void func_00128580(s32, u8 **);
void func_0012E730(s32);
void func_00159DD0(s32, s32, u8 ***, s32 *);
s32 func_0012E6B0(u8 *);
extern u8 **D_00201EBC;
extern s8 D_00201ED4;
s32 func_0012DEE0(s32 a) {
    s32 sz;
    u8 *p;
    D_00201ED4 = 1;
    func_0012E730(0);
    func_00159DD0(0xE728760E, a, &D_00201EBC, &sz);
    p = *D_00201EBC;
    switch (*(s32 *)p) {
    case 0x4D415453:
        if (func_0012E6B0(p) == -1) {
            func_00128580(a, D_00201EBC);
            return -1;
        }
    }
    func_00128580(a, D_00201EBC);
    return 0;
}
