#include "common.h"
extern s16 D_001F37B0[];
typedef struct { u8 pad[0x497E]; u16 t[1]; } S;
extern S *D_00201DC4;
static inline s32 find(s32 k) { u32 i; for (i = 0; i < 0x2A; i++) if (k == D_001F37B0[i]) return i; return -1; }
u16 func_001AA090(s32 a) {
 if (find(a) == -1) return 0; return D_00201DC4->t[a / 10];
}
