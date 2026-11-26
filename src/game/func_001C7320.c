#include "actor.h"
typedef struct { u8 pad[0x3E0]; u16 ids[8]; } S;
static inline S *getp(void) {
    if (D_002022E4 == 0) return 0;
    if (D_002022E4->unk518 == 0) return 0;
    return (S *)(D_002022E4->unk518 + 0x180);
}
s32 func_001C7320(u16 *a0) {
    S *p;
    s32 i;
    p = getp();
    if (p == 0) return 0;
    for (i = 0; i < 8; i++) {
        if (p->ids[i] == a0[1]) return 1;
    }
    return 0;
}

