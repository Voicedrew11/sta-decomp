#include "common.h"
typedef struct { s32 x0; s32 x4; s32 x8; u8 xC; u8 xD; u8 xE; u8 xF; } S;
extern S D_004B9FA0;
extern u8 D_004B9FAC;
void func_001D85D0(int, int, int);
s32 sceSifDmaStat(u32 id);
s32 func_001D9710(void) {
    S *s = &D_004B9FA0;
    if (D_004B9FA0.xC == 0) {
        return -1;
    }
    func_001D85D0(3, 0, 0x02060000);
    if (s->x4 != 0) {
        if (sceSifDmaStat(s->x4) >= 0) {
            return 0;
        }
        s->x4 = 0;
    }
    s->xC = 0;
    s->xE = 0;
    return 1;
}
