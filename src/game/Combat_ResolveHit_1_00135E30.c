#include "common.h"
void Combat_ApplyHitEffect_0_00132BA0(s32, u8, s8*, s8*, s8*, s8*);
void Combat_CalcDamage_1_00132DB0(s32, u8, s8*, s8*, s8*, s8*);
void Combat_ResolveHit_1_00135E30(s32 a, u8 mm, s8 *b, s8 *c, s8 *d, s8 *e) {
    *b = 0; *c = 0; *d = 0; *e = 0;
    switch (mm) {
    case 0: Combat_CalcDamage_1_00132DB0(a, mm, b, c, d, e); break;
    case 1: Combat_ApplyHitEffect_0_00132BA0(a, mm, b, c, d, e); break;
    }
}
