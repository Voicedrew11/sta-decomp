#include "m2c.h"
u16 Rand_Next_3_0015ED20(void);
s32 Sfx_IsLoaded_2_00169BB0(s32);
s8 *Sfx_Spawn_2_00169B50(s32, s32, s32, s32);
void Fx_GetWorldMatrix_1_00163C80(void *, u8 *);
void Sfx_SetMatrixOrAim_0_00167740(s8 *, u8 *);
typedef struct { u8 a:2; u8 f:1; u8 r:5; } BF;
typedef struct {
    u8 pad0[0x60];
    f32 f60, f64, f68;
    u8 pad6c[0x8C - 0x6C];
    f32 f8c;
    s8 * volatile p90;
    u16 i94;
    u8 pad96[0xB0 - 0x96];
    f32 fb0, fb4;
} Obj;

void FxProc_SpawnRandomChild_0_00148B30(Obj *arg0) {
    u8 sp40[0x40];
    s32 var_s0;
    u16 *temp_s2;
    s32 id;
    s8 *p;

    var_s0 = 0;
    if (0.0f != arg0->f60 && ((BF *)(arg0->p90 + 0x188))->f) {
        if (0.0f == arg0->f8c) {
            if (arg0->f64) {
                temp_s2 = ((u16 **)(arg0->p90 + 0x210))[arg0->i94];
                { f32 a = arg0->f64 * (0.000015259022f * (f32)(u32)Rand_Next_3_0015ED20()); arg0->fb0 = 0.033333335f * (a * (f32)(u32)*temp_s2); }
                arg0->fb4 = 0.0f;
            } else {
                var_s0 = 1;
            }
        }
        if (arg0->f64 && !arg0->fb4 && arg0->fb0 < arg0->f8c) {
            var_s0 = 1;
            arg0->fb4 = 1.0f;
        }
        if (var_s0 != 0) {
            id = arg0->f68;
            if (Sfx_IsLoaded_2_00169BB0(id) != 0) {
                p = Sfx_Spawn_2_00169B50(id, 0, 0, 0);
                Fx_GetWorldMatrix_1_00163C80(arg0, sp40);
                Sfx_SetMatrixOrAim_0_00167740(p, sp40);
            }
        }
    }
}
