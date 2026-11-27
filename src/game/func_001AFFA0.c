#include "common.h"
s32 func_00159DD0(s32 id, void *a, void *out, void *size);
extern u8 *D_002022B0;

s32 func_001AFFA0(void *a) {
    s32 sz;
    u32 **h;
    u32 *p;
    s32 q;
    func_00159DD0(0x48F91304, a, &h, &sz);
    p = *h;
    switch (p[0]) {
    case 0x4D505449:
        q = (s32)p + 0x10;
        D_002022B0 = (u8 *)(q + 0x10 + ((*(u32 *)(q + 0xC) + 0xF) & ~0xF));
        break;
    }
    return 0;
}
