#include "common.h"
typedef struct { void *p; s32 x; } E;
extern E D_0047F080[8];
void *func_00177BB0(u64 a, void *b, s32 c);
void *func_00177B20(u64 a) {
    s32 i;
    void *r = NULL;
    if (a == (u64)-1) return r;
    for (i = 0; i < 8; i++) {
        if (D_0047F080[i].p != NULL && (r = func_00177BB0(a, D_0047F080[i].p, D_0047F080[i].x)) != NULL) break;
    }
    return r;
}
