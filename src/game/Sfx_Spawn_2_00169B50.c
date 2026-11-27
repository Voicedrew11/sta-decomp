#include "common.h"
extern s32 *D_00201FE8;
extern s32 D_0033F6D0[];
extern s32 D_003406E0[];
s32 Sfx_Create_2_00169F40(s32 *, s32, s32, s32, s32, s32, u16);
s32 Sfx_Spawn_2_00169B50(s32 id, s32 a1, s32 a2, s32 a3) {
    if (id == 0) return 0;
    return Sfx_Create_2_00169F40(D_00201FE8, D_0033F6D0[id], (s32)D_003406E0, a1, a2, a3, id);
}

