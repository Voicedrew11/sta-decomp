#include "common.h"
typedef struct { char p[0x44]; f32 x44; char q[0x38]; } S;
extern S D_0022CBC0[];

s32 SndCh_SetRange_0_00131250(s32 arg0, f32 f) {
    S *s;
    if (!(0 > arg0) && arg0 < 0x3F) {
        s = &D_0022CBC0[arg0];
    } else {
        s = 0;
    }
    if (s == 0) {
        return -1;
    }
    if (f < 0.0f) {
        f = 0.0f;
    }
    s->x44 = f;
    return 0;
}

