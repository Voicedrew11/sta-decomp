#include "m2c.h"
s32 sceIoctl(s32, s32, s32 *);
s32 sceGsSyncV(s32);
s32 sceCdSync(s32);
extern s32 D_00201F88;
extern s8 *D_00201F80;
extern s32 D_00201F8C;

s32 func_0015A3A0(s8 *a0, s32 a1) {
    s32 r = 1;
    if (D_00201F88) {
        if (!(*(u16 *)(a0 + 0x10) & 1)) a0 = D_00201F80;
        if (a1 == 0) {
            sceIoctl(*(s32 *)(a0 + 0x14), 1, &r);
            if (a0 == D_00201F80 && r == 0) D_00201F8C = 0;
        } else {
            do {
                sceIoctl(*(s32 *)(a0 + 0x14), 1, &r);
                sceGsSyncV(0);
            } while (r);
            if (a0 == D_00201F80) D_00201F8C = 0;
        }
    } else {
        r = sceCdSync(a1 != 1);
    }
    return r;
}
