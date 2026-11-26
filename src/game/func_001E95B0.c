#include "common.h"
typedef struct { s32 w[4]; } Q;
typedef struct { u32 x, y, w, h; } R;
typedef struct { u8 pad[0x30]; s32 x30, x34, x38, x3C, x40, x44; } O;
Q *func_001E92C0(Q *p, R *b, R *a);
Q *func_001E9020(Q *p, R *r, s32 i, s32 j);

static inline Q *dma(Q *p, u64 v) { *(u64 *)p = v; return p + 1; }
static inline Q *tag(Q *p, s32 a, s32 b, s32 c, s32 d) { p->w[0] = a; p->w[1] = b; p->w[2] = c; p->w[3] = d; return p + 1; }
static inline Q *ref(Q *p, u32 addr, s32 n) { *(u64 *)p = ((u64)(u32)((s32)addr & ~0xF) << 32) | 0x30000000 | n; return p + 1; }
static inline Q *set(Q *p, u64 v, s32 r) { p->w[0] = v & 0xFFFFFFFF; p->w[1] = v >> 32; p->w[2] = r; p->w[3] = 0; return p + 1; }

void func_001E95B0(O *o, u32 buf, u32 src, s32 i, s32 j) {
    R a;
    R b;
    Q *p;
    s32 tbp;
    s32 tbw;
    s32 ny;
    s32 w;
    s32 nx;
    s32 y;
    s32 x;
    u32 ad;
    u64 v;

    p = (Q *)((buf & 0x0FFFFFFF) | 0x20000000);
    ny = o->x40 >> 4;
    nx = o->x44 >> 4;
    w = (o->x38 + 63) / 64 * 64;
    tbp = w * ((o->x3C / 2 + 31) / 32 * 32) * 2 / 64;
    tbw = w / 64;
    if (i == 0) {
        a.x = o->x30 * 16;
        a.y = o->x34 * 16;
        a.w = o->x38 * 16;
        a.h = o->x3C / 2 * 16;
        b.x = 8;
        b.y = 0x18;
        b.w = o->x40 * 16;
        b.h = o->x44 * 16;
    } else {
        a.x = o->x30 * 16;
        a.y = (o->x34 + (o->x3C / 2 + 31) / 32 * 32) * 16;
        a.w = o->x38 * 16;
        a.h = o->x3C / 2 * 16;
        b.x = 8;
        b.y = 8;
        b.w = o->x40 * 16;
        b.h = o->x44 * 16;
    }
    if (i == 0) {
        p = dma(p, 0x10000003);
        p = tag(p, 2, 0x10000000, 0xE, 0);
        p = set(p, ((u64)(u32)tbp << 32) | ((u64)(u32)tbw << 48), 0x50);
        p = set(p, 0x0000001000000010ULL, 0x52);
        for (y = 0; y < ny; y++) {
            for (x = 0; x < nx; x++) {
                p = dma(p, 0x10000004);
                p = tag(p, 2, 0x10000000, 0xE, 0);
                v = ((u64)(u32)(y * 16) << 32) | ((u64)(u32)(x * 16) << 48);
                p = set(p, v, 0x51);
                p = set(p, 0, 0x53);
                p = tag(p, 0x40, 0x08000000, 0, 0);
                                ad = src & 0x0FFFFFFF; p = ref(p, ad, 0x40);
                src += 0x400;
            }
        }
    }
    p = dma(p, 0x10000009);
    p = tag(p, 8, 0x10000000, 0xE, 0);
    p = set(p, 0, 0x3F);
    p = set(p, (u64)(u32)tbp | ((u64)(u32)tbw << 14) | 0xAA8000000ULL, 6);
    p = set(p, 0x60, 0x14);
    p = func_001E92C0(p, &a, &b);
    p = dma(p, 0x70000006);
    p = tag(p, 0x8005, 0x10000000, 0xE, 0);
    func_001E9020(p, &a, i, j);
}



