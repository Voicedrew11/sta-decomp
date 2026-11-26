#include "actor.h"
#define WRAPV(x) ((((3.1415927f + (x)) - 6.2831855f * (s32)(0.15915494f * (3.1415927f + (x)))) + ((3.1415927f + *(volatile f32 *)&(x)) < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f)
#define WRAP(x) ((((3.1415927f + (x)) - 6.2831855f * (s32)(0.15915494f * (3.1415927f + (x)))) + ((3.1415927f + (x)) < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f)
typedef struct { u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; u8 b4:1; u8 b5:1; u8 b6:1; u8 b7:1; } Bits;
void sceVu0CopyVector(Vec *, s8 *);
void sceVu0SubVector(Vec *, Vec *, Vec *);
f32 func_0013FC10(Vec *);
f32 sceVu0InnerProduct(Vec *, Vec *);
f32 func_0011DBC0(f32, f32);
f32 sqrtf(f32);
inline s8 *get(void) {
    if (D_002022E4 == NULL) {
        return NULL;
    }
    if (D_002022E4->unk518 == NULL) {
        return NULL;
    }
    return D_002022E4->unk518 + 0x180;
}
typedef struct { u8 pad[0x20]; f32 x20; f32 x24; } R;
#define RR (*(R **)(p + 0x18))

void func_001C89E0(Vec *dir, f32 t) {
    Vec v;
    s8 *p;
    s8 *q;
    f32 w;
    f32 d;
    f32 y;
    f32 *a;

    p = get();
    if (p == NULL) return;
    q = get();
    if (q != NULL) {
        sceVu0CopyVector(&v, q + 0x40);
    }
    sceVu0SubVector(&v, dir, &v);
    w = func_0013FC10(&v);
    w = WRAP(w);
    RR->x24 = WRAP(RR->x24);
    d = RR->x24 - w;
    if (d > 3.1415927f) d -= 6.2831855f;
    if (d < -3.1415927f) d += 6.2831855f;
    RR->x24 = w + d * t;
    RR->x24 = WRAP(RR->x24);
    y = v.y;
    v.y = 0.0f;
    w = -func_0011DBC0(y, sqrtf(sceVu0InnerProduct(&v, &v)));
    w = WRAP(w);
    RR->x20 = WRAP(RR->x20);
    d = RR->x20 - w;
    if (d > 3.1415927f) d -= 6.2831855f;
    if (d < -3.1415927f) d += 6.2831855f;
    RR->x20 = w + d * t;
    RR->x20 = WRAP(RR->x20);
    ((Bits *)(p + 0x3A2))->b1 = 0;
}
