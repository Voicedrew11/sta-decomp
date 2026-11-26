#include "common.h"
typedef struct { Mtx m; u8 pad[0x100]; } Bone;
typedef struct { u8 pad[6]; u16 h6; } Hdr;
typedef struct { u8 pad[0x1A8]; Hdr *x1A8; } Sub;
typedef struct { u8 pad[0x518]; Sub *x518; } A;
extern s32 D_00201F2C;

Bone *func_001468F0(A *a, u8 idx) {
    Hdr *h;
    h = a->x518->x1A8;
    return &((Bone *)((u8 *)((s32)h + 0x40) + D_00201F2C * (h->h6 * 0x140 + 0x200) + 0xC0))[idx + 1];
}

