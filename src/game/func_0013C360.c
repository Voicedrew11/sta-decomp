#include "common.h"
typedef struct { u8 p[0x5B5]; Flags8_4x2 f5B5; u8 q[0x6D2 - 0x5B6]; s16 x6D2; s8 x6D4; s8 x6D5; s8 x6D6; } A;
void func_0013C360(A *a, s16 v, s8 b, s8 c, s8 d) {
    a->x6D2 = v;
    a->x6D4 = b;
    a->x6D5 = c;
    a->x6D6 = d;
    if ((v >= 8 && v < 12) || (v >= 16 && v < 19) || (v >= 40 && v < 44) || (v >= 48 && v < 51)) a->f5B5.f.b6 = 1;
    else a->f5B5.f.b6 = 0;
}

