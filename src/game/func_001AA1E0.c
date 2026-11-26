#include "common.h"
typedef struct { s32 v[8]; u32 n[0x68]; } E;
extern s16 D_001F37B0[];
extern E *D_00201DC4;

static inline s32 find(s32 a) {
    u32 i;
    for (i = 0; i < 0x2A; i++) {
        if (a == D_001F37B0[i]) return i;
    }
    return -1;
}

s32 func_001AA1E0(s32 arg0, s16 arg1) {
    s32 i = find(arg0);
    if (i == -1) return 0;
    return (D_00201DC4[i].n[arg1 / 8] >> (arg1 % 8 * 4)) & 0xF;
}

