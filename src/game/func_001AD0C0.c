#include "common.h"
typedef struct { u8 p[0x10]; u8 **tbl; u8 p14[2]; u16 n; } M;
typedef struct { u8 p[0x84]; M ****m; u8 p88[8]; s32 x90; u8 p94[0x14]; Flags8 f; } O;
void func_001710D0(M ***, s16, f32, f32, f32);

void func_001AD0C0(O *o, s32 id) {
    u8 v;
    s32 w;
    if (o != NULL && (o->f.b & 1)) {
        if (o->x90 != 0) {
            v = (u8)id;
        } else {
            v = (*(***o->m)->tbl + o->x90 * 16)[id];
        }
        w = v;
        if ((***o->m)->n != 0) {
            func_001710D0(*o->m, w, 1.0f, 0.0f, 0.0f);
            o->f.f.b3 = 1;
            o->f.f.b4 = 0;
            o->f.f.b5 = 0;
        }
    }
}
