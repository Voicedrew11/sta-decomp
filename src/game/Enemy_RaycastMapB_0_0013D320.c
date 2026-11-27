#include "common.h"
typedef struct { u128 a, b; } Ray;
typedef struct { u8 pad[0x24]; s32 hit; } Res;
typedef struct { u8 pad[0x6E]; u16 n; } Obj;
s32 MapColl_CapsuleCastAll_1_001B3240(Obj *, Res *, Ray *, s32, s32);
s32 MapColl_CapsuleCast_1_001B2800(Obj *, Res *, Ray *, u16, s32, s32);

s32 Enemy_RaycastMapB_0_0013D320(Obj *o, Res *res, Ray *ray, s32 a3, u8 f) {
    Ray r;
    u16 j;
    r = *ray;
    if (f & 1) {
        MapColl_CapsuleCastAll_1_001B3240(o, res, &r, a3, 1);
        if (res->hit) return res->hit;
    }
    if ((f & 2) && o) {
        for (j = 0; j < o->n; j++) {
            MapColl_CapsuleCast_1_001B2800(o, res, &r, j, a3, 1);
            if (!(res->hit != 0) == 0) return res->hit;
        }
    }
    return res->hit;
}
