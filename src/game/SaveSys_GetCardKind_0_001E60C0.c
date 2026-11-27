#include "common.h"
typedef struct { s32 a; s32 b; char pad[0x3F8]; } R;
extern R D_004BC384[];
s32 SaveSys_GetCardKind_0_001E60C0(s32 i) { s32 r; if (D_004BC384[i].a == 0) return 1; if (D_004BC384[i].b) r = 0; else r = 2; return r; }

