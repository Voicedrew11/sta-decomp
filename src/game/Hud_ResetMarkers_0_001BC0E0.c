#include "common.h"

typedef struct { s32 a; s32 wait; s32 c; char pc[4]; f32 f; char p14[0x18]; } E;
extern E D_004B4BE0[2];

void Hud_ResetMarkers_0_001BC0E0(void)
{
    s32 i;
    E *e = D_004B4BE0;
    for (i = 0; i < 2; i++, e++) {
        if (e->wait > 0) {
            e->wait--;
        } else if (e->a > 0) {
            if (e->a < e->c)
                e->f += (f32)e->a / (f32)e->c;
            e->a--;
        }
    }
}
