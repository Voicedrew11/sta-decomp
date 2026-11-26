#include "common.h"
typedef struct { char p[0x14]; s16 x14; char r[0xA]; } A;
typedef struct { s32 x200; s32 x204; s32 x208; s32 x20C; } B;
extern struct { A a[16]; B b[8]; } D_004BA500;
s32 func_001D8680(s32 a, s32 b, s32 c, ...);
s32 func_001DA9A0(s32 j, s32 i) {
    A *a;
    B *b;
    if (i < 0 || i >= 16) return -1;
    if (j < 0 || j >= 8) return -1;
    a = &D_004BA500.a[i];
    if (a->x14 < 0 || a->x14 >= 8) return -1;
    b = &D_004BA500.b[j];
    b->x208 = i;
    b->x20C = a->x14;
    return -(func_001D8680(4, 1, 0x20000, b->x20C, b->x200) != 0);
}
