#include "common.h"
extern u16 D_001F1E60[];
typedef struct { s16 v; } S;
void func_0014D8A0(S *a0, u16 i) {
    S t;
    t.v = D_001F1E60[i];
    *a0 = t;
}

