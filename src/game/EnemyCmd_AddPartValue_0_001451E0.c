#include "common.h"
typedef struct { char pad[0x610]; s8 x610; s8 x611; s8 x612; s8 x613; s32 x614; } P;
typedef struct { char pad[0x154]; P *p; } S;
extern S *D_00201FA8;
void EnemyCmd_AddPartValue_0_001451E0(u8 *arg0) {
    P *p;
    u8 a;
    s32 d;
    u8 b;
    u8 c;
    p = D_00201FA8->p;
    a = arg0[0x10];
    d = arg0[8];
    b = arg0[0x18];
    c = arg0[0x20];
    if (a != 0xFF) p->x610 = a;
    if ((b & 0xFF) != 0xFF) p->x612 = b;
    if (c & 0xFF) p->x613 = c;
    if (d != 0) {
        p->x611 = 0;
        p->x614 = 0;
    }
}
