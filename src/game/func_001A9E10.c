#include "common.h"
extern s16 D_001F37B0[];
typedef struct { u8 pad[0x180]; s32 w[16]; } Rec;
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
void func_001A9E10(s32 id, u16 k, u8 v) {
    u32 i = find(id);
    if (i != -1) {
        s32 b = k * 2;
        D_00201DC4[i].w[b / 32] |= (v & 3) << (b % 32);
    }
}
