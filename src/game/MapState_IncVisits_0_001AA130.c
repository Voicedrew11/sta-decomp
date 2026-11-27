#include "common.h"
extern s16 D_001F37B0[];
typedef struct { u8 pad[0x4980]; u16 a[16]; u16 b[16]; } Big;
extern Big *D_00201DC4;
static inline u32 find(s32 id) {
    u32 i;
    for (i = 0; i < 42; i++) {
        if (id == D_001F37B0[i]) {
            return i;
        }
    }
    return -1;
}
void MapState_IncVisits_0_001AA130(s32 id) {
    u32 i = find(id);
    if (i != -1) {
        s32 k = id / 10 - 1;
        D_00201DC4->a[k]++;
        if (D_00201DC4->b[k] < D_00201DC4->a[k]) D_00201DC4->b[k] = D_00201DC4->a[k];
    }
}
