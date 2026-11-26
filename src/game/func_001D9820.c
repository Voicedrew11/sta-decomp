#include "common.h"
typedef struct { s32 x0; s32 x4; s32 x8; u8 xC; u8 xD; u8 xE; u8 xF; s32 x10; s32 x14; } S;
extern S D_004B9FA0;
extern s32 D_00202310;
void func_001D8680(s32 a, s32 b, s32 c, ...);
s32 func_001D9820(u16 a, u16 b) {
    S *s = &D_004B9FA0;
    if (D_00202310 == 0) {
        return 0;
    }
    switch (s->xC) {
    case 1:
    case 2:
    case 3:
    case 6:
        return 0;
    }
    func_001D8680(3, 0, 0x020A0000, s->x14, s->x10, a, b);
    s->xC = 6;
    s->xE = 0;
    return 1;
}
