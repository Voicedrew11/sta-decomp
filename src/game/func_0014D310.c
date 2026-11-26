#include "actor.h"
typedef struct { u8 pad[0x10]; Vec v10; u8 pad20[0x40]; f32 x60; u8 pad64[0x58]; f32 xBC; } O;
extern s8 D_001F2160[];
void sceVu0SubVector(Vec *, s8 *, O *);
f32 sceVu0InnerProduct(Vec *, Vec *);
void func_00102870(Vec *, Vec *);
void sceVu0ScaleVector(Vec *, Vec *, f32);
void sceVu0AddVector(Vec *, Vec *, Vec *);
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
    sceVu0SubVector(&t, has() ? D_002022E4->unk518 + 0x1C0 : D_001F2160, o);
    len = sqrtf(sceVu0InnerProduct(&o->v10, &o->v10));
    func_00102870(&u, &t);
    sceVu0ScaleVector(&u, &u, -1.0f * r);
    sceVu0AddVector(&o->v10, &o->v10, &u);
    func_00102870(&o->v10, &o->v10);
    sceVu0ScaleVector(&o->v10, &o->v10, len);
    o->xBC -= d;
}
