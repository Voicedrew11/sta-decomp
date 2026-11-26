#include "common.h"
typedef struct { u8 pad[0x5B8]; f32 a; f32 b; } O;
void func_0013DA90(O *o, f32 f) {
    f32 b;
    f32 a;
    a = o->a;
    b = o->b;
    if (a != b) {
        if (a > b) {
            b += f / 0.5f;
            if (!(b <= a)) b = a;
        } else {
            b -= f / 0.5f;
            if (b < a) b = a;
        }
        o->b = b;
    }
}

