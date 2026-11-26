#include "obj3d.h"
s32 func_001A9D50(u32, u16);
void func_001A9E10(s32, u16, u8);
void func_001A9CA0(s32, s16);
void func_001AF4A0(Obj3D *);
void func_001AE510(void);
void func_001AF3F0(Obj3D *o) {
    if (o->x9E == 0) {
        s32 *p = *o->x8C;
        if (o->xA9.f.b2) {
            func_001A9E10(*p, o->xAC, func_001A9D50(*p, o->xAC) | 2);
        } else {
            func_001A9CA0(*p, o->xAC);
        }
    }
    func_001AF4A0(o);
    if (o->x9E == 1) func_001AE510();
}
