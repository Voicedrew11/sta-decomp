#include "common.h"
typedef struct { s16 x0; s16 x2; s16 x4; } S;
typedef struct { u8 pad[0x3A2]; Flags8 x3A2; u8 pad3A3[0x7B]; s16 x41E; } O;
S *func_001C9BA0(void);
O *func_001C9B60(void);
s32 func_0012C020(void);
void func_0018A330(s32);
u32 func_0015ED20(void);
void func_00131600(s32, s32);

void func_001CEAA0(s32 d) {
    S *s;
    O *o;
    s = func_001C9BA0();
    o = func_001C9B60();
    if (o && s->x4 > 0 && !func_0012C020()) {
        s->x4 += (s16)d;
        if (s->x4 < 0) s->x4 = 0;
        if (s->x0 < s->x4) s->x4 = s->x0;
        if (s->x4 <= 0) {
            func_0018A330(0);
            func_00131600(func_0015ED20() % 3 + 0x128, 0x7F);
            o->x41E = 0;
            o->x3A2.f.b4 = 1;
        }
    }
}
