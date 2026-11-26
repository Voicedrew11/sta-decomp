#include "common.h"
typedef struct { u8 pad[8]; u16 h8; } Key;
extern u8 *D_002022D4;
void func_001D1E80(s32, s32, Key *, s32, s32);
void func_001D1F20(s32, u8 *, s32, s32, Key *, s32, s32);
void func_001BAA10(s32 a0, s32 a1, s32 a2, Key *a3, s32 t0, s32 t1) {
    if (t1 != 0) {
        switch (a3->h8) {
        case 0:
            func_001D1E80(a0, a2, a3, t0, t1);
            break;
        case 1:
            func_001D1F20(a0, D_002022D4 + 0xB4, a1, a2, a3, t0, t1);
            break;
        }
    }
}

