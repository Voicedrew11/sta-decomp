#include "common.h"
#include "actor.h"
typedef struct { u8 pad[8]; s32 x8; s32 pC; s32 x10; } Arg;
f32 *func_00165130(Arg *, s32);
s32 func_001B7840(s32, s32);
s8 *func_001B19A0(s32);
s8 *func_001715B0(s32);
void func_00102A60(Vec *, void *);
void func_00102A70(Mtx *, void *);
void func_001029E8(Vec *, Vec *, Vec *);
f32 func_00102848(Vec *, Vec *);
f32 sqrtf(f32);

void func_0017D000(Arg *a0) {
    Vec b;
    Mtx m;
    Vec a;
    f32 *out;
    s32 idx;
    s8 *o;
    s8 *e;
    s8 *mm;
    s8 *p;

    out = func_00165130(a0, 2);
    idx = func_001B7840(a0->x8, a0->x10);
    if (idx >= 0) {
        o = func_001B19A0(a0->x8);
        if (o != NULL) {
            e = *(s8 **)(o + 0x180) + idx * 0x80;
            if (e != NULL) {
                mm = func_001715B0(*(s32 *)(e + 0x40));
                if (mm != NULL) {
                    p = D_002022E4->unk518 + 0x180;
                    if (p != NULL) {
                        func_00102A60(&b, p + 0x40);
                        func_00102A70(&m, mm + 0x200);
                        func_001029E8(&a, &m.m[3], &b);
                        *out = sqrtf(func_00102848(&a, &a));
                    }
                }
            }
        }
    }
}
