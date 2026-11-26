#include "common.h"
typedef struct { u8 p[0x58]; f32 x58; u8 p5c[0x24]; } N;
typedef struct { u8 p[0x180]; N *n; } Obj;
typedef struct { u8 pad[8]; s32 x8; s32 pC; s32 x10; s32 p14; f32 x18; } Arg;
s32 func_001B7840(s32, s32);
Obj *func_001B19A0(s32);

void func_0017D3D0(Arg *a) {
    f32 f;
    s32 id;
    s32 i;
    Obj *o;
    N *n;
    f = a->x18;
    id = a->x8;
    i = func_001B7840(id, a->x10);
    if (i >= 0) {
        o = func_001B19A0(id);
        if (o != NULL) {
            n = &o->n[i];
            if (n != NULL) {
                if (f < 0.0f || f > 255.0f) return; n->x58 = f / 255.0f;
            }
        }
    }
}

