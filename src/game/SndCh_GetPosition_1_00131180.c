#include "common.h"
typedef struct { char p[0x24]; f32 x24; f32 x28; char q[0x54]; } S;
extern S D_0022CBC0[];

s32 SndCh_GetPosition_1_00131180(s32 arg0, f32 *arg1) {
    S *s;
    if (!(0 > arg0) && arg0 < 0x3F) {
        s = &D_0022CBC0[arg0];
    } else {
        s = 0;
    }
    if (s == 0) {
        return -1;
    }
    s->x24 = arg1[0];
    s->x28 = arg1[1];
    return 0;
}

