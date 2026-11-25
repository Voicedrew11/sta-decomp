#include "m2c.h"
typedef struct { u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; u8 b4:1; u8 b5:1; u8 b6:1; u8 b7:1; } B8;
typedef struct { f32 a; f32 t; u8 pad8[4]; B8 f; u8 padD[3]; } T;
typedef struct { u8 pad[4]; s16 x4; s16 x6; } G;
extern T D_001F3060;
extern T D_001F3070;
extern s32 D_002021D8;
extern s32 D_002021DC;
G *func_001C9BA0(void);
static inline void upd(T *t, s32 *last, s16 *src) {
    if (t->f.b0) {
        if (*last != *src) {
            t->t = 0.0f;
            *last = *src;
            t->f.b0 = 0;
            t->a = 0.0f;
        }
        return;
    }
    if (*last != *src) {
        *last = *src;
        t->t = 0.0f;
    }
    if (t->t < 20.0f) {
        t->a += 8.0f;
        if (t->a > 128.0f) t->a = 128.0f;
    }
    if (t->t > 120.0f) {
        t->a -= 8.0f;
        if (t->a < 0.0f) t->a = 0.0f;
    }
    if (t->t > 160.0f) {
        t->f.b0 = 1;
    }
    t->t += 1.0f;
}

void func_0019B8D0(void) {
    G *g = func_001C9BA0();
    upd(&D_001F3060, &D_002021D8, &g->x4);
    upd(&D_001F3070, &D_002021DC, &g->x6);
}
