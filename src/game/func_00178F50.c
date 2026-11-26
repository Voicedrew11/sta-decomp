#include "common.h"
typedef struct { s8 c0, c1, c2, c3; s32 x4; s32 x8; s32 xC; } S;
typedef struct { S *s; s32 x4; s32 x8; s32 xC; s32 x10; } T;
s32 func_00178F50(T *a, s32 b, s32 c) { S *s = a->s; s32 e, d, f; if (s == 0) return 0; e = s->xC; d = s->x8; f = s->x4;  if ((u8)(s->c3 - '0')) { if (c == b) c += (e - (d + 1)) & ~0xF; } else { return 0; } a->x4 = b; a->x8 = c; a->xC = f; a->x10 = 0; return 1; }

