#include "actor.h"
typedef struct { unsigned char p : 1; unsigned char v : 1; } BF_1_1;
void func_0013EE90(Actor *a0, int a1) {
    a0->flags5A1.f.b5 = a1;
}

void func_0013EEB0(Actor *a0, int a1) {
    ((BF_1_1 *)(*(char **)(a0->unk518 + 0x190) + 0x120))->v = a1;
}
