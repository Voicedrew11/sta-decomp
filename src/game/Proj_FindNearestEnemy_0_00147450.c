#include "common.h"
extern Vec D_001F2160;
s8 *ActorList_Next_2_001A5460(s32 *);
s32 Enemy_IsBusy_0_0013EE40(s8 *);
f32 Vec_Distance_3_00146940(void *, void *);
s8 *Proj_FindNearestEnemy_0_00147450(void *pos, f32 d) {
    s32 it;
    s8 *e;
    s8 *r;
    f32 t;
    it = 0;
    e = ActorList_Next_2_001A5460(&it);
    r = NULL;
    while (e != NULL) {
        if (*(u16 *)e != 0 && Enemy_IsBusy_0_0013EE40(e) == 0) {
            t = Vec_Distance_3_00146940(e ? (void *)(*(s8 **)(e + 0x518) + 0x90) : (void *)&D_001F2160, pos);
            if (t < d) { d = t; r = e; }
        }
        e = ActorList_Next_2_001A5460(&it);
    }
    return r;
}
