#include "actor.h"
#define WRAP(x) ((((3.1415927f + (x)) - 6.2831855f * (s32)(0.15915494f * (3.1415927f + (x)))) + ((3.1415927f + (x)) < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f)
typedef struct { u8 pad[0x18]; s8 *o; u8 pad2[0x3A1 - 0x1C]; u8 r:7; u8 b7:1; } P;
f32 sqrtf(f32);
s32 Game_GetFlag54b6_0_001A9410(void);
void sceVu0SubVector(Vec *, f32 *, s8 *);
f32 sceVu0InnerProduct(Vec *, Vec *);
f32 atan2f(f32, f32);
f32 fabsf(f32);
void Hud_RandomizeMarker_0_001BC170(s32 *);
s32 D_001F38C0[0xc] = { -0x7fffdfc0, -0x7fffcdce, -0x7fffbfce, -0x7fffd800, -0x7fcdf000, -0x7fd5fff0, -0x80000000, -0x7fbfbfc0, -0x80000000 };
static inline P *cur(void) {
    if (D_002022E4 == 0) return 0;
    if (D_002022E4->unk518 == 0) return 0;
    return (P *)(D_002022E4->unk518 + 0x180);
}

void Hud_AddMarker_0_001BC320(f32 *a0, s32 a1) {
    P *p;
    f32 y;
    f32 t;
    Vec v;
    p = cur();
    if (p == 0) return;
    if (p->b7) return;
    if (!Game_GetFlag54b6_0_001A9410()) return;
    if (a1 < 0 || a1 == 6 || a1 == 8) return;
    sceVu0SubVector(&v, a0, p->o);
    if (!(sqrtf(sceVu0InnerProduct(&v, &v)) <= 400.0f)) return;
    sceVu0SubVector(&v, a0, p->o);
    t = atan2f(-v.x, -v.z) - WRAP(*(f32 *)(p->o + 0x24));
    if (fabsf(WRAP(t)) <= 0.69813174f) {
        y = v.y;
        v.y = 0.0f;
        t = atan2f(-y, sqrtf(sceVu0InnerProduct(&v, &v))) - *(f32 *)(p->o + 0x20);
        if (fabsf(WRAP(t)) <= 0.69813174f) {
            Hud_RandomizeMarker_0_001BC170(&D_001F38C0[a1]);
        }
    }
}
