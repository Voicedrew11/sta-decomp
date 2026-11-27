#include "m2c.h"
typedef struct { u8 pad0[8]; s16 x8, xA; u8 padC[4]; s16 x10; u8 pad12[0x1E]; } E30;
typedef struct { f32 x0, x4, x8, xC, x10, x14; u8 pad18[0xC]; u16 x24, x26; u8 pad28[4]; } E2C;
typedef struct {
    u8 pad0[4];
    u32 n;
    u8 pad8[0x28];
    E30 a[8];
    E2C b[7];
    u8 pad2E4[0x24];
} T;
typedef struct { u8 pad[8]; T t; } Elem;
extern Elem D_00437DC0[4];
static inline f32 mu(s32 x, f32 k) { f32 f = x; return f * k; }

void TexAnim_Update_0_001752A0(void) {
    E30 *a;
    s32 k;
    u32 i;
    E2C *b;
    T *t;
    f32 *p;
    f32 fw, fh;
    for (k = 0; k < 4; k++) {
        t = &D_00437DC0[k].t;
        for (i = 0; i < t->n; i++) {
            a = &t->a[i];
            b = &t->b[i];
            p = &b->x0;
            fw = b->x24 << 4;
            fh = b->x26 << 4;
            b->x0 += a->x8 * b->x8;
            b->x4 += a->xA * b->xC;
            b->x10 += 0.05f + 0.0005f * a->x10;
            b->x14 += 0.05f + 0.0005f * a->x10;
            if (p[0] > fw) p[0] = p[0] - mu((s32)(p[0] / fw), fw);
            if (p[1] > fh) p[1] = p[1] - mu((s32)(p[1] / fh), fh);
            if (p[0] < 0.0f) p[0] = p[0] - mu((s32)(p[0] / fw) - 1, fw);
            if (p[1] < 0.0f) p[1] = p[1] - mu((s32)(p[1] / fh) - 1, fh);
        }
    }
}
