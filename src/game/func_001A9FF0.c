#include "common.h"
extern s16 D_001F37B0[];
typedef struct { u8 pad[0x499E]; u16 t[1]; } Rec;
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
u16 func_001A9FF0(s32 id) {
    u32 i = find(id);
    if (i == -1) {
        return 0;
    }
    return D_00201DC4->t[id / 10];
}

