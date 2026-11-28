#include "common.h"
#include "game/ee.h"
extern GsTextState *D_00201E5C;
#define BIT 0x1000000000000ULL
void GsText_Kick_1_001E24A0(void) {
    s32 v;
    if (D_00201E5C->x8 != 0) {
        if (D_00201E5C->u.h.b != 0) {
            D_00201E5C->xC -= 0x34;
            if (!(D_00201E5C->u.d & BIT)) {
                D_00201E5C->xC -= 4;
            }
            *D_00201E5C->xC = 0xC;
            if (!(D_00201E5C->u.d & BIT)) {
                (*D_00201E5C->xC)++;
            }
        } else {
            *D_00201E5C->xC = 0;
        }
        if (!(D_00201E5C->u.d & BIT)) *D_00201E5C->xC |= 0x60000000; else *D_00201E5C->xC |= 0x70000000;
        D_00201E5C->xC[1] = 0;
    }
}
