#include "common.h"
typedef struct { u8 b[0x60]; } Buf;
typedef struct { u128 q[4]; } D40;
extern D40 D_001F25F0;
extern u8 D_001FB980[];
void sceGsSetDefLoadImage(Buf *, s32, s32, s32, s32, s32, s32, s32);
void FlushCache(s32);
void sceGsExecLoadImage(Buf *, void *);
void sceGsSyncPath(s32, s32);

void func_00181240(void) {
    Buf a;
    Buf b;
    D40 d;
    sceGsSetDefLoadImage(&a, 0x3020, 1, 0x14, 0, 0, 0x80, 0x40);
    FlushCache(0);
    sceGsExecLoadImage(&a, D_001FB980);
    sceGsSyncPath(0, 0);
    d = D_001F25F0;
    sceGsSetDefLoadImage(&b, 0x3032, 1, 0, 0, 0, 8, 2);
    FlushCache(0);
    sceGsExecLoadImage(&b, &d);
    sceGsSyncPath(0, 0);
}
