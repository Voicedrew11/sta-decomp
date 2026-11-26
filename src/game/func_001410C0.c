#include "m2c.h"
typedef struct { u8 pad[0x4A4]; void **p; } Obj;
#define H(a) (*(a)->p)
Obj *func_001A5460(s32 *);
s32 func_0013EE30(Obj *);
s32 func_0013EDE0(Obj *);
s32 func_0013ECA0(Obj *);
s32 func_00166F80(void *, s32, void *);
void func_00165070(void *, u8, s32, u32);
s8 func_00166C10(void *, s32);

void func_001410C0(u8 a0, u8 a1, u32 a2, u32 a3) {
    s32 it;
    Obj *cur;
    s32 id;
    it = 0;
    cur = func_001A5460(&it);
    if (cur != NULL) {
        do {
            if (!func_0013EE30(cur) && func_0013EDE0(cur) == a0 && (u8)func_0013ECA0(cur) == a1) {
                id = func_00166F80(H(cur), 0x2019, cur);
                func_00165070(H(cur), id, 0, a2);
                func_00165070(H(cur), id, 1, a3);
                while (func_00166C10(H(cur), id) != 0) {}
            }
            cur = func_001A5460(&it);
        } while (cur != NULL);
    }
}
