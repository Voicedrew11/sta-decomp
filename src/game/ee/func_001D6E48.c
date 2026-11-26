#include "common.h"

extern struct { s32 st[0x18]; s32 res[0xE]; s32 x98; } D_004B63B8;

s32 func_001D6E48(s32 a, s32 b)
{
    s32 s;
    s32 r;
    s32 n;

    s = D_004B63B8.st[a * 4 + b];
    if (s == 1) {
        D_004B63B8.x98 = 1;
        return -1;
    }
    r = D_004B63B8.res[a * 4 + b];
    if (r < -2) {
        D_004B63B8.x98 = 1;
        return -2;
    }
    if (s != 2 && s != 3) {
        D_004B63B8.x98 = 1;
        return -5;
    }
    n = -r;
    if (s == 3) {
        switch (n) {
        case 3: D_004B63B8.x98 = 0x14; break;
        case 4: D_004B63B8.x98 = 0x16; break;
        case 5: D_004B63B8.x98 = 0x15; break;
        default: D_004B63B8.x98 = 1; break;
        }
    } else {
        switch (n) {
        case 0: D_004B63B8.x98 = 0; break;
        case 1: D_004B63B8.x98 = 2; break;
        case 2: D_004B63B8.x98 = 3; break;
        default: D_004B63B8.x98 = 1; break;
        }
    }
    if (D_004B63B8.x98 == 1)
        return -6;
    return n;
}

