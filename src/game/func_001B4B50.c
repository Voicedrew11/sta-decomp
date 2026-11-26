#include "common.h"
void func_00166CC0(s32);
void func_00171540(s32, s32 *);
void func_001B41C0(u8 *);
void func_001B43A0(u8 *);
void func_001BAB70(u8 *, f32);
extern s32 D_001F2170[];
void func_001B4B50(u8 *arg0, f32 f) {
    s32 *t;
    func_00171540(***(s32 ***)(arg0 + 0x178), D_001F2170);
    func_001BAB70(arg0, f);
    func_001B43A0(arg0);
    func_001B41C0(arg0);
    t = *(s32 **)(arg0 + 0xC);
    if (t != NULL) func_00166CC0(*t);
}
