#include "common.h"
typedef struct { u8 b0:1; u8 b1:1; } F;
typedef struct { u8 pad[4]; f32 x4; u8 pad8[0x58]; f32 x60; u8 pad64[0x24]; f32 x88; u8 pad8c[0x28]; f32 xB4; u8 xB0p[4]; f32 xBC; u8 padc0[0x54]; F x114; } O;
s32 Sfx_IsLoaded_2_00169BB0(s32);
s8 *Sfx_Spawn_2_00169B50(s32, s32, s32, s32);
void Sfx_SetPosition_1_00167710(s8 *, void *);
static inline f32 u2f(u32 x) { return x; }

void FxProc_SpawnTimed_0_0014BE70(O *o) {
    s32 id;
    s8 *p;
    if (o->xBC && o->xB4 < o->x4) {
        id = o->x60;
        o->x88 = u2f(o->x114.b1 = 0);
        if (Sfx_IsLoaded_2_00169BB0(id)) {
            p = Sfx_Spawn_2_00169B50(id, 0, 0, 0);
            if (p) Sfx_SetPosition_1_00167710(p, (u8 *)o + 0xB0);
        }
    }
}
