#include "actor.h"
#define WRAP(x) ((((3.1415927f + (x)) - 6.2831855f * (s32)(0.15915494f * (3.1415927f + (x)))) + ((3.1415927f + (x)) < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f)
typedef struct { u8 pad[0x30]; f32 x30; } O18;
typedef struct { u8 pad[0x18]; O18 *x18; } S;
f32 func_0011D850(f32);
extern Actor *D_002022E4;

f32 func_001C7CA0(f32 a) {
    S *s;
    f32 lim;
    f32 c;
    if (D_002022E4 == NULL) {
        s = NULL;
    } else if (D_002022E4->unk518 == NULL) {
        s = NULL;
    } else {
        s = (S *)((u8 *)D_002022E4->unk518 + 0x180);
    }
    if (s) {
        lim = func_0011D850(-1.0471976f);
        c = func_0011D850(WRAP(s->x18->x30));
        if (!(c <= lim)) c = lim;
        a *= 1.0f + c / lim;
    }
    return a;
}
