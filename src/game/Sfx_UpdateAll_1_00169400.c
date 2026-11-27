#include "common.h"
typedef struct { u8 pad[0x2D]; Flags8 f2D; Flags8 f2E; u8 pad2[0x30 - 0x2F]; } M3;
typedef struct { M3 m[2]; } E;
typedef struct { u8 pad[0x188]; Flags8 f188; } Mgr;
typedef struct { u8 pad[0x90]; Mgr *f90; u8 pad2[0x114 - 0x94]; Flags8 f114; u8 pad3[0x120 - 0x115]; } B;
typedef struct { u16 prev; u16 next; u16 x4; } L;
s32 Sfx_UpdateTransforms_1_00169030(void);
s32 Fx_UpdateEmitter_0_00160370(B *, M3 *, f32);
s32 Sfx_UpdateInstance_0_00168D70(u16, B *, M3 *);
void GlowFx_Update_0_001E0C10(f32);
extern u8 D_00201FE0;
extern s32 D_00201FE4;
extern s32 D_00201FB0;
extern s32 D_00201F2C;
extern u16 D_00201C9C;
extern u16 D_00201CA4;
extern B *D_00201FC0;
extern L *D_00201FD4;
extern E *D_00201FD0;

void Sfx_UpdateAll_1_00169400(f32 dt) {

    u16 i;
    u16 idx;
    u16 next;
    B *o;
    M3 *e;
    s32 r;

    if (D_00201FE0 == 1) return;
    D_00201FB0 = Sfx_UpdateTransforms_1_00169030();
    {
    u16 h[2] = {0};
    h[0] = D_00201C9C;
    h[1] = D_00201CA4;
    for (i = 0; i < 2; i++) {
        idx = h[i];
        while (idx != 0xFFFF) {
            o = &D_00201FC0[idx];
            next = D_00201FD4[idx].next;
            if (o->f114.f.b0) {
                e = &D_00201FD0[idx].m[D_00201F2C];
                if (o->f90->f188.f.b4 || o->f114.f.b2) {
                    r = 1;
                    e->f2D.f.b3 = 0;
                } else {
                    if (e->f2E.f.b1) {
                        e->f2D.f.b3 = 1;
                        e->f2E.f.b1 = 0;
                    }
                    r = Fx_UpdateEmitter_0_00160370(o, e, dt);
                }
                if (r) Sfx_UpdateInstance_0_00168D70(idx, o, e);
            }
            idx = next;
        }
    }
    }
    GlowFx_Update_0_001E0C10(dt);
    if (D_00201FE0 == 2 && D_00201FE4 == D_00201F2C) D_00201FE0 = 1;
}
