#include "m2c.h"
extern f32 D_001F2160[];
s8 *ActorList_Next_2_001A5460(s32 *);
s32 Enemy_IsBusy_0_0013EE40(s8 *);
double pow(double, double);
double fptodp(f32);
double dpadd(double, double);
f32 dptofp(double);
s8 *Sfx_Spawn_2_00169B50(s32, s32, s32, s32);
void Sfx_SetPosition_1_00167710(s8 *, f32 *);
void Proj_SpawnAttack_0_00146A70(s32, s8 *, s32, u16);
float sqrtf(float);
#define POS(p) ((p) ? (f32 *)(*(s32 *)((p) + 0x518) + 0x90) : D_001F2160)

void FxProc_SplashDamage_0_0014A5F0(s8 *a0) {
    f32 *q;
    s32 it;
    s8 *p;
    u32 id;
    s32 n;
    s32 ok;
    f32 *pos;
    double dz;
    s8 *e;
    if (*(s32 *)(a0 + 0xA8) == 0) {
        it = 0;
        p = ActorList_Next_2_001A5460(&it);
        id = (u32)*(f32 *)(a0 + 0x60);
        while (p) {
            n = 0;
            if (*(u16 *)p != 0 && !Enemy_IsBusy_0_0013EE40(p)) {
                pos = POS(p);
                q = POS(p);
                dz = pow(fptodp(pos[2] - *(f32 *)(a0 + 8)), 2.0);
                n += sqrtf(dptofp(dpadd(pow(fptodp(q[0] - *(f32 *)(a0 + 0)), 2.0), dz))) < *(f32 *)(a0 + 0x50);
                ok = 0;
                if (*(f32 *)(a0 + 4) + *(f32 *)(a0 + 0x54) <= POS(p)[1] && POS(p)[1] <= *(f32 *)(a0 + 4) + *(f32 *)(a0 + 0x58)) {
                    ok = 1;
                }
                n *= ok;
                if (n) {
                    if (id && (e = Sfx_Spawn_2_00169B50(id, 0, 0, 0))) {
                        Sfx_SetPosition_1_00167710(e, POS(p));
                    }
                    Proj_SpawnAttack_0_00146A70(*(s32 *)(a0 + 0x90), p, 0, (s32)*(f32 *)(a0 + 0x64));
                }
            }
            p = ActorList_Next_2_001A5460(&it);
        }
        *(s32 *)(a0 + 0xA8) = 1;
    }
}
