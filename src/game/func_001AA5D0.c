#include "common.h"
extern s16 D_001F37B0[];
typedef struct { s32 v[0x70]; } Rec;
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
void func_001AA5D0(s32 id, s16 k, s32 v) {
    u32 i = find(id);
    if (i != -1) {
        D_00201DC4[i].v[k] = v;
    }
}
