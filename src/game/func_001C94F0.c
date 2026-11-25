#include "actor.h"
#define WRAP(x) ((((3.1415927f + (x)) - 6.2831855f * (s32)(0.15915494f * (3.1415927f + (x)))) + ((3.1415927f + (x)) < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f)
typedef struct { u8 pad[0x18]; s8 *o; } P;
extern s8 D_003139A0[];
void func_00102A60(void *, void *);
static inline P *cur(void) {
    if (D_002022E4 == 0) return 0;
    if (D_002022E4->unk518 == 0) return 0;
    return (P *)(D_002022E4->unk518 + 0x180);
}

void func_001C94F0(f32 *a0) {
    P *p;
    Vec v;
    p = cur();
    if (p == 0) return;
    v.x = 0.0f;
    v.y = WRAP(a0[3]);
    v.z = v.w = 0.0f;
    func_00102A60(p->o, a0);
    func_00102A60(p->o + 0x10, a0);
    func_00102A60(p->o + 0x20, &v);
    func_00102A60(p->o + 0x30, &v);
    func_00102A60(p->o + 0x40, D_003139A0);
}
