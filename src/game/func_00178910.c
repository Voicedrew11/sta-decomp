#include "common.h"
typedef struct { u8 d[0x60]; } LI;
void FlushCache(s32);
void func_00101120(s32, s32);
void memset(void *, s32, s32);
void sceGsExecLoadImage(LI *, void *);
void sceGsSetDefLoadImage(LI *, s16, s16, s16, s16, s16, s16, s16);
void func_00178910(s32 y, s32 end) {
    LI li;
    u8 buf[0x10000];
    memset(buf, 0, 0x10000);
    for (; y < end; y += 0x100) {
        sceGsSetDefLoadImage(&li, y, 2, 0, 0, 0, 0x80, 0x80);
        FlushCache(0);
        sceGsExecLoadImage(&li, buf);
        func_00101120(0, 0);
    }
}
