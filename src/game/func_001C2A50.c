#include "actor.h"
#define WRAP(x) ((((3.1415927f + (x)) - 6.2831855f * (s32)(0.15915494f * (3.1415927f + (x)))) + ((3.1415927f + (x)) < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f)
typedef struct { u8 pad[0x50]; Vec v50; u8 p60[0x380 - 0x60]; f32 f380; f32 f384; f32 f388; u32 u38C; u8 p390[0x3A1 - 0x390];
    Flags8 f3A1; Flags8 f3A2; u8 p3A3[0x3BF - 0x3A3]; u8 u3BF; u8 p3C0[0x454 - 0x3C0]; f32 f454; } P;
f32 sqrtf(f32);
void sceVu0CopyVector(Vec *, Vec *);
f32 sceVu0InnerProduct(Vec *, Vec *);
f32 fabsf(f32);
f32 func_0011DA18(f32);
s32 func_001A9440(void);
void func_001CA4A0(u8, u8);

void func_001C2A50(Actor *a) {
    P *p;
    Vec v;
    f32 x;
    p = (P *)(a->unk518 + 0x180);
    sceVu0CopyVector(&v, &p->v50);
    v.y = 0.0f;
    x = sqrtf(sceVu0InnerProduct(&v, &v));
    p->f454 = p->f380;
    if (x <= 100.0f && fabsf(p->f380) < 0.2f) {
        p->f384 = 0.0f;
        p->f388 = 0.0f;
        p->f380 = 0.0f;
        p->u38C = 0;
        p->f3A2.f.b2 = 0;
        return;
    }
    p->f384 *= 0.5f;
    p->f388 *= 0.5f;
    if (p->f3A1.f.b5) {
        x = WRAP(0.3f * p->u38C);
    } else {
        x = WRAP(0.2f * p->u38C);
    }
    p->f388 += 0.5f * func_0011DA18(x);
    p->f384 += p->f388;
    p->u38C++;
    p->f380 = func_001A9440() ? p->f384 : 0.0f;
    if (!(p->f384 <= 1.5f)) {
        if (!p->f3A2.f.b2) {
            func_001CA4A0(p->f3A1.f.b7 ? 0x10 : p->u3BF, p->f3A1.f.b5);
        }
        p->f3A2.f.b2 = 1;
    } else {
        p->f3A2.f.b2 = 0;
    }
}
