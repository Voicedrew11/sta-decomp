#include "m2c.h"
f32 func_0015DEB0(void *, s32);
f32 func_0015DF20(void *, s32);
void func_001C9410(void *);
u16 *func_001A5710(void);
u16 *func_001A5660(void);
void func_00140470(u16 *, void *);

s32 func_001B9E00(s32 arg0, s32 arg1, f32 r) {
    f32 sp40[4];
    u16 *p;

    r = r * r;
    func_001C9410(sp40);
    if (arg1 != 0) {
        if (func_0015DF20(sp40, arg0) <= r) return 1;
    } else {
        if (func_0015DEB0(sp40, arg0) <= r) return 1;
    }
    p = func_001A5710();
    if (p != NULL) {
        do {
            if (*p != 0) {
                func_00140470(p, sp40);
                if (arg1 != 0) {
                    if (func_0015DF20(sp40, arg0) <= r) return 1;
                } else {
                    if (func_0015DEB0(sp40, arg0) <= r) return 1;
                }
            }
            p = func_001A5660();
        } while (p != NULL);
    }
    return 0;
}
