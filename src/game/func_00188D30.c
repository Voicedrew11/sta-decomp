#include "m2c.h"
static inline s32 hexval(s32 c) {
    if (c >= 0x30 && c < 0x3A) {
        return c - 0x30;
    }
    if (c >= 0x61 && c < 0x67) {
        return c - 0x57;
    }
    if (c >= 0x41 && c < 0x47) {
        return c - 0x37;
    }
    return -1;
}

u16 *func_00188D30(u16 *s, u8 *out) {
    s32 v;

    v = *s - 0x100;
    if ((u16)v < 0x100) {
        out[3] = v;
        v = *++s - 0x100;
        if ((u16)v > 0xFF) {
            return s;
        }
        out[2] = v;
        v = *++s - 0x100;
        if ((u16)v > 0xFF) {
            return s;
        }
        out[1] = v;
        v = *++s - 0x100;
        if ((u16)v > 0xFF) {
            return s;
        }
        out[0] = v;
        return s + 1;
    }
    v = hexval(*s);
    if (v >= 0) {
        u8 b[8] = {0};
        s32 i;
        u8 *p;

        b[0] = v;
        s++;
        p = &b[1];
        for (i = 1; i < 8; i++) {
            v = hexval(*s);
            if (v < 0) {
                return s;
            }
            *p = v;
            s++;
            p++;
        }
        out[0] = (b[0] << 4) | b[1];
        out[1] = (b[2] << 4) | b[3];
        out[2] = (b[4] << 4) | b[5];
        out[3] = (b[6] << 4) | b[7];
    }
    return s;
}
