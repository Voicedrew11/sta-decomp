#include "common.h"
extern s16 D_001F37B0[];
typedef struct { s8 pad[0x50]; u8 b0 : 1; u8 r : 7; s8 rest[0x1C0 - 0x51]; } Rec;
extern Rec *D_00201DC4;
static inline u32 find(s32 id) {
    u32 i;
    for (i = 0; i < 42; i++) {
        if (id == D_001F37B0[i]) {
            return i;
        }
    }
    return -1;
}
void MapState_SetVisited_0_001AA4C0(s32 id) {
    u32 i = find(id);
    if (i != -1) {
        D_00201DC4[i].b0 = 1;
    }
}
