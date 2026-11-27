#include "common.h"
typedef struct { u128 a, b; } V2;
typedef struct { u8 p[0x6E]; u16 n; } O;
typedef struct { u8 p[0x24]; s32 x24; } Out;
s32 MapColl_SphereCastAll_0_001B34B0(O *o, Out *out, V2 *p, u8 f1, u8 f2);
s32 MapColl_SphereCast_0_001B2B90(O *o, Out *out, V2 *p, u16 idx, u8 f1, u8 f2);

s32 Enemy_RaycastMapA_0_0013D250(O *o, Out *out, V2 *v, u8 m2, u8 m1) {
    V2 c;
    u16 i;
    c = *v;
    if (m1 & 1) {
        MapColl_SphereCastAll_0_001B34B0(o, out, &c, m2, 0);
    }
    if ((m1 & 2) && o != 0) {
        for (i = 0; i < o->n; i++) {
            MapColl_SphereCast_0_001B2B90(o, out, &c, i, m2, 0);
        }
    }
    return out->x24;
}
