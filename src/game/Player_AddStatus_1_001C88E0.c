#include "common.h"
typedef struct { u8 pad[0x30]; u32 x30[8]; s32 x50[8]; } G;
extern G *D_00201E20;
extern Flags8 D_00222A53[];
extern u32 D_001F3860[][8];
s32 Player_GetStat_2_001CD450(s32, s32, s32, s32);
s32 Equip_FindSlot_0_001CD2D0(s32);

void Player_AddStatus_1_001C88E0(s32 a, u32 b) {
    G *g;
    u32 v;
    g = D_00201E20;
    if (a < 0 || a > 5) return;
    if (b == 1 || b == 2) {
        if (!D_00222A53[0].f.b7 && !Player_GetStat_2_001CD450(7, 0, 0, 1) && !Equip_FindSlot_0_001CD2D0(a)) {
            v = g->x30[a] >> 24;
            if (v < 2 && v < b) {
                v = D_001F3860[b][a];
                g->x30[a] = v | (b << 24);
                g->x50[a] = 0;
            }
        }
    }
}
