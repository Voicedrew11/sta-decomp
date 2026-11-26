#include "common.h"
extern s16 D_001F37B0[];
typedef struct { s8 pad[0x180]; u32 bits[16]; } Rec;
extern Rec *D_00201DC4;
static inline u32 find(s32 id) {
    u32 i;
    for (i = 0; i < 42; i++) {
        if (id == D_001F37B0[i]) {
            return i;
        }
    }
    return -1;
}
u32 func_001A9D50(s32 id, u16 k) {
    u32 i = find(id);
    s32 sh;
    s32 n;
    if (i == -1) {
        return 0;
    }
    n = k * 2;
    sh = n % 32;
    return ((3 << sh) & D_00201DC4[i].bits[n / 32]) >> sh;
}
