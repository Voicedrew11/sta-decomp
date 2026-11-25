#include "common.h"
typedef struct { char p0[2]; u8 b2; char p3[2]; u8 b5; char p6[2]; } E;
typedef struct { char pad[0x5C00]; E e[1]; } S;
extern S *D_00201DC0;
u8 func_001AA6D0(s16 i) { if (D_00201DC0->e[i].b5) return D_00201DC0->e[i].b2; return 0; }
