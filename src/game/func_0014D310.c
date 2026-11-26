#include "actor.h"
typedef struct { u8 pad[0x10]; Vec v10; u8 pad20[0x40]; f32 x60; u8 pad64[0x58]; f32 xBC; } O;
extern s8 D_001F2160[];
void func_001029E8(Vec *, s8 *, O *);
f32 func_00102848(Vec *, Vec *);
void func_00102870(Vec *, Vec *);
void func_00102A18(Vec *, Vec *, f32);
void func_001029D0(Vec *, Vec *, Vec *);
f32 sqrtf(f32);
inline s32 has(void) {
    return D_002022E4 != NULL && D_002022E4->unk518 != NULL;
}

void func_0014D310(O *o) {
    Vec t;
    Vec u;
    f32 d;
    f32 r;
    f32 len;

    d = o->x60;
    r = o->xBC;
    func_001029E8(&t, has() ? D_002022E4->unk518 + 0x1C0 : D_001F2160, o);
    len = sqrtf(func_00102848(&o->v10, &o->v10));
    func_00102870(&u, &t);
    func_00102A18(&u, &u, -1.0f * r);
    func_001029D0(&o->v10, &o->v10, &u);
    func_00102870(&o->v10, &o->v10);
    func_00102A18(&o->v10, &o->v10, len);
    o->xBC -= d;
}
