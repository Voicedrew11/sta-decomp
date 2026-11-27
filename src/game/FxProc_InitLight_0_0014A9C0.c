#include "common.h"
typedef struct { u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; u8 b4:1; u8 b5:1; u8 b6:1; u8 b7:1; } BF8;
typedef struct { u8 pad[0x188]; BF8 x188; } P90;
typedef struct {
    Vec v0;
    u8 pad10[0x40];
    Vec v50;
    f32 x60;
    f32 x64;
    f32 x68;
    s32 x6C[3];
    s32 x5C_dummy;
    u8 pad7C[0x14];
    P90 *x90;
    u8 pad94[0x1C];
    f32 xB0;
    u8 padB4[0x60];
    BF8 x114;
} O;
s32 GlowFx_Start_0_001E1050(void);
void GlowFx_Stop_0_001E0D30(f32, s32);
void GlowFx_SetParams_0_001E0F30(f32, f32, s32, Vec *, Vec *);
void Fx_GetWorldMatrix_1_00163C80(O *, Mtx *);
void sceVu0CopyVector(Vec *, Vec *);

void FxProc_InitLight_0_0014A9C0(O *o) {
    Vec v;
    Mtx m;

    *(s32 *)((u8 *)o + 0x5C) = 0;
    o->xB0 = -1.0f;
    if (o->x90->x188.b2) {
        if ((s32)o->xB0 == -1) {
            o->xB0 = GlowFx_Start_0_001E1050();
        }
    } else {
        if ((s32)o->xB0 != -1) {
            GlowFx_Stop_0_001E0D30(o->x68, o->xB0);
            o->xB0 = -1.0f;
        }
    }
    if ((s32)o->xB0 != -1) {
        if (o->x114.b5) {
            Fx_GetWorldMatrix_1_00163C80(o, &m);
            sceVu0CopyVector(&v, &m.m[3]);
        } else {
            sceVu0CopyVector(&v, &o->v0);
        }
        GlowFx_SetParams_0_001E0F30(o->x60, o->x64, o->xB0, &v, &o->v50);
    }
}
