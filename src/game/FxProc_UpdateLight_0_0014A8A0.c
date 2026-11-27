#include "common.h"
typedef struct { u8 pad[0x188]; Flags8 x188; } P;
typedef struct {
    Vec x0; u8 pad10[0x40]; Vec x50; f32 x60; f32 x64; f32 x68; u8 pad6C[0x24];
    P *x90; u8 pad94[0x1C]; f32 xB0; u8 padB4[0x60]; Flags8 x114;
} O;
s32 GlowFx_Start_0_001E1050(s32);
void GlowFx_Stop_0_001E0D30(f32, s32);
void GlowFx_SetParams_0_001E0F30(f32, f32, s32, Vec *, Vec *);
void Fx_GetWorldMatrix_1_00163C80(O *, Mtx *);
void sceVu0CopyVector(void *, void *);

void FxProc_UpdateLight_0_0014A8A0(O *o) {
    Vec v;
    Mtx m;
    if (o->x90->x188.f.b2) {
        if ((s32)o->xB0 == -1) {
            o->xB0 = GlowFx_Start_0_001E1050((s32)o->xB0);
        }
    } else {
        if ((s32)o->xB0 != -1) {
            GlowFx_Stop_0_001E0D30(o->x68, (s32)o->xB0);
            o->xB0 = -1.0f;
        }
    }
    if ((s32)o->xB0 != -1) {
        if (o->x114.f.b5) {
            Fx_GetWorldMatrix_1_00163C80(o, &m);
            sceVu0CopyVector(&v, &m.m[3]);
        } else {
            sceVu0CopyVector(&v, o);
        }
        GlowFx_SetParams_0_001E0F30(o->x60, o->x64, (s32)o->xB0, &v, &o->x50);
    }
}
