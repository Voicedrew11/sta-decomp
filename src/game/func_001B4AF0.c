#include "common.h"
typedef struct { s32 **obj; } P8;
typedef struct { u8 pad[0x178]; P8 *x178; } S;
extern s32 D_001F2170[];
void func_00171540(s32 *, s32 *);
void func_001BAAA0(S *);
void func_001B4AF0(S *a) {
    if (a == NULL || a->x178 == NULL) return;
    func_00171540(*a->x178->obj, D_001F2170);
    func_001BAAA0(a);
}
