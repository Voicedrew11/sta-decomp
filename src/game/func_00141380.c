#include "m2c.h"
typedef struct { u8 pad[0x4A4]; void **p; } Obj;
#define H(a) (*(a)->p)
Obj *func_001A5460(s32 *);
s32 func_0013EE30(Obj *);
s32 func_0013EDE0(Obj *);
s32 func_0013E220(Obj *);
s32 func_0013EEE0(Obj *);
s32 func_00166F80(void *, s32, void *);
void func_00165070(void *, u8, s32, u32);
s8 func_00166C10(void *, s32);
s32 func_00164FC0(void *, u8, s32);

u8 func_00141380(u32 a0, u32 a1) {
    s32 it;
    u8 n;
    Obj *cur;
    s32 k;
    s32 id;
    u8 v;
    n = 0;
    it = 0;
    cur = func_001A5460(&it);
    if (cur != NULL) {
        do {
            if (!func_0013EE30(cur)) {
                k = (u8)func_0013EDE0(cur);
                v = func_0013E220(cur);
                if (v >= 0x25 && v <= 0x28 && !func_0013EEE0(cur)) {
                    id = func_00166F80(H(cur), 0x2015, cur);
                    func_00165070(H(cur), id, 0, 0);
                    func_00165070(H(cur), id, 1, k);
                    func_00165070(H(cur), id, 2, a0);
                    func_00165070(H(cur), id, 3, a1);
                    while (func_00166C10(H(cur), id) != 0) {}
                    n += (u8)func_00164FC0(H(cur), id, 0);
                }
            }
            cur = func_001A5460(&it);
        } while (cur != NULL);
    }
    return n;
}
