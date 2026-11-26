#include "common.h"
typedef struct { s8 b0; s8 b1; char rest[0x7E]; } E;
extern E D_0022CBC0[];
s32 func_001DA530(s32, s32, s32, s32, s32, s32, s32, s32);
static inline E *get(s32 i) {
    E *p;
    if (0 <= i && i < 0x3F) p = &D_0022CBC0[i]; else p = NULL;
    return p;
}
s32 func_001314A0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7) {
    E *p = get(arg0);
if (p == NULL) return -1; if (func_001DA530(p->b1, arg1, arg2, arg3, arg4, arg5, arg6, arg7) == -1) return -1; p->b0 = 0; return 0;
}
