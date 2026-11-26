#include "common.h"
typedef struct { Mtx m; u8 pad[0x100]; } Bone;
typedef struct { u8 pad[6]; u16 h6; } Hdr;
typedef struct { u8 pad[0x1A8]; Hdr *x1A8; } Sub;
typedef struct { u8 pad[0x518]; Sub *x518; } A;
extern s32 D_00201F2C;
void func_00102A60(Vec *, Vec *);
void func_0015EBB0(f32, Mtx *, Vec *);
void func_001027E0(Mtx *, Mtx *, Bone *);

s32 func_001464A0(A *a, u8 idx, Mtx *out) {
    Mtx m;
    Vec v;
    Hdr *h;
    Bone *b;
    h = a->x518->x1A8;
    b = &((Bone *)((u8 *)((s32)h + 0x40) + D_00201F2C * (h->h6 * 0x140 + 0x200) + 0xC0))[idx + 1];
    if (b != 0) {
        func_00102A60(&v, &b->m.m[3]);
        func_0015EBB0(3.1415927f, &m, &b->m.m[1]);
        func_001027E0(out, &m, b);
        func_00102A60(&out->m[3], &v);
        return 1;
    }
    return 0;
}
