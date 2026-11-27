#include "m2c.h"
#include "common.h"
typedef struct { u16 x0; u8 pad[0x92]; u8 x94; } P;
typedef struct {
    u8 pad[0x174]; f32 x174; u8 p178[0x10]; Flags8 f188; u8 p189; Flags8 f18A; u8 p18B[0x85];
    P *x210; u8 p214[0x5C]; u8 x270[0xC]; s8 x27C;
} O;
static inline f32 u2f(u32 x) { return x; }
void Fx_UpdateChildren_1_00162700(O *, f32, s8);
void Sfx_ResetTree_0_001698E0(O *, u8 *);

s32 Sfx_UpdateNode_1_001697A0(O *o, f32 dt) {
    P *p;
    f32 lim;

    p = o->x210;
    lim = 0.033333335f * u2f(p->x0);
    if (p == NULL) return 0;
    if (o->f188.f.b3) return 0;
    if (lim < o->x174 + dt) {
        if (!(p->x94 & 1)) {
            o->x174 = lim;
            return 1;
        }
        o->x174 = 0.0f;
        Sfx_ResetTree_0_001698E0(o, o->x270);
    }
    if (o->f188.f.b2 && o->f18A.f.b0 && o->x27C != 0) {
        Fx_UpdateChildren_1_00162700(o, dt, o->x27C);
    }
    if (o->f188.f.b2) {
        o->x174 += dt;
    }
    return 0;
}
