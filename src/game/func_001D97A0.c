#include "common.h"
typedef struct { u8 pad[0xC]; u8 c; u8 d; u8 e; } S;
extern S D_004B9FA0[];
extern u8 D_004B9FAC[];
void func_001D85D0(s32, s32, s32);
s32 func_001D97A0(void) {
    S *s = D_004B9FA0;
    if (D_004B9FAC[0] == 7) {
        func_001D85D0(3, 0, 0x02010000);
        s->e = 1;
        s->c = 2;
    } else if (s->c == 6) {
        s->c = 1;
    } else {
        return 0;
    }
    return 1;
}
