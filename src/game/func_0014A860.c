#include "common.h"
typedef struct { u8 pad[0x68]; f32 x68; u8 pad6C[0x44]; f32 xB0; } O;
void func_001E0D30(f32, s32);
void func_0014A860(O *o) {
    if ((s32)o->xB0 != -1) {
        func_001E0D30(o->x68, (s32)o->xB0);
    }
}
