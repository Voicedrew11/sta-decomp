#include "common.h"
typedef struct { union { u64 d; struct { u32 a; u16 b; u16 c; } h; } u; s32 x8; s32 *xC; } S;
extern S *D_00201E5C;
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
