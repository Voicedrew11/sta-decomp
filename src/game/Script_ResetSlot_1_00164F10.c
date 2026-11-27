#include "common.h"
typedef struct { s32 x0; u8 p[0x10]; u32 x14; } S;
void Script_ResetSlot_1_00164F10(S *a) {
    u8 i;
    u32 n;
    if (a != 0 && a->x0 != 0) {
        n = a->x14;
        for (i = 0; i < n; i++) {}
    }
}
