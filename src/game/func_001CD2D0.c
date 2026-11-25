#include "m2c.h"
s8 *func_001C9BA0();
u8 *func_001AFC90(void);
static inline s16 slot(s32 arg0) {
    s8 *v = func_001C9BA0();
    if (arg0 >= 0 && arg0 < 10) {
        return *(s16 *)(v + 0x80 + arg0 * 2);
    }
    return -1;
}
typedef struct { u8 pad0[0xA]; u16 xA; u8 pad1[0x1A]; u8 s[6]; u8 pad2[0x90-0x2C]; } E;

s32 func_001CD2D0(s32 a0) {
    E *base = (E *)func_001AFC90();
    s32 i;
    s16 idx;
    for (i = 2; i <= 8; i++) {
        idx = slot(i);
        if (idx > 0 && base[idx].xA == 1) {
            switch (a0) {
            case 0: if (base[idx].s[0] >= 100) return 1; break;
            case 1: if (base[idx].s[1] >= 100) return 1; break;
            case 2: if (base[idx].s[2] >= 100) return 1; break;
            case 3: if (base[idx].s[4] >= 100) return 1; break;
            case 4: if (base[idx].s[3] >= 100) return 1; break;
            case 5: if (base[idx].s[5] >= 100) return 1; break;
            }
        }
    }
    return 0;
}
