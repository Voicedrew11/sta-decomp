#include "actor.h"
#define WRAP(x) ((((3.1415927f + (x)) - 6.2831855f * (s32)(0.15915494f * (3.1415927f + (x)))) + ((3.1415927f + (x)) < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f)
typedef struct { f32 x, y, z, w; } Vec;
typedef struct { u8 pad[0x18]; s8 *o; u8 pad2[0x3A1 - 0x1C]; u8 r:7; u8 b7:1; } P;
f32 sqrtf(f32);
s32 func_001A9410(void);
void func_001029E8(Vec *, f32 *, s8 *);
f32 func_00102848(Vec *, Vec *);
f32 func_0011DBC0(f32, f32);
f32 func_0011D850(f32);
void func_001BC170(s32 *);
extern s32 D_001F38C0[];
static inline P *cur(void) {
    if (D_002022E4 == 0) return 0;
    if (D_002022E4->unk518 == 0) return 0;
    return (P *)(D_002022E4->unk518 + 0x180);
}

void func_001BC320(f32 *a0, s32 a1) {
    P *p;
    f32 y;
    f32 t;
    Vec v;
    p = cur();
    if (p == 0) return;
    if (p->b7) return;
    if (!func_001A9410()) return;
    if (a1 < 0 || a1 == 6 || a1 == 8) return;
    func_001029E8(&v, a0, p->o);
    if (!(sqrtf(func_00102848(&v, &v)) <= 400.0f)) return;
    func_001029E8(&v, a0, p->o);
    t = func_0011DBC0(-v.x, -v.z) - WRAP(*(f32 *)(p->o + 0x24));
    if (func_0011D850(WRAP(t)) <= 0.69813174f) {
        y = v.y;
        v.y = 0.0f;
        t = func_0011DBC0(-y, sqrtf(func_00102848(&v, &v))) - *(f32 *)(p->o + 0x20);
        if (func_0011D850(WRAP(t)) <= 0.69813174f) {
            func_001BC170(&D_001F38C0[a1]);
        }
    }
}
