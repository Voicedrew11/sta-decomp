#include "m2c.h"
typedef struct { u8 a:3; u8 b3:1; u8 b4:1; u8 b5:1; u8 b6:1; u8 b7:1; } Bits;
typedef struct {
    u8 pad0[0x10];
    s32 x10;
    u16 x14, x16, x18, x1A, x1C, x1E;
    u16 x20, x22;
    u8 pad24[8];
    s32 x2C;
    u8 pad30[0xC];
    union { s32 w; Bits f; } x3C;
} Obj;
typedef struct { Obj *obj; } Blk;
typedef struct { u16 x0, x2, x4, x6, x8; u8 xA, xB; u8 xC_0:3; u8 xC_3:3; u8 xC_6:2; u8 xD_0:2; u8 xD_2:1; u8 xD_3:5; u8 xE; } Info;
typedef struct { u8 pad[0xC]; s32 size; } Sub;
typedef struct { s32 magic; u8 pad4[0xC]; Sub sub; } Hdr;
Blk *func_001288C0(s32, s32);
void func_001535B0(s32 *, Blk *);
void func_00123C40(Obj *, s32, s32);
void func_00170380(Hdr *, Obj *);

Blk *func_00170000(s32 *a0, s32 a1, Hdr *hdr) {
    Blk *b;
    Info *info;
    s32 size;
    Sub *sub;

    b = NULL;
    switch (hdr->magic) {
    case 0x4D415453:
    sub = &hdr->sub;
    info = (Info *)((s32)(sub + 1) + ((sub->size + 15) & ~15));
    size = info->x0 * 16 + 0x40 + info->x2 * 8 + info->x6 * 4 + info->xA * 0x50 + info->xE * 4;
    b = func_001288C0(*a0, size);
    func_001535B0(a0 + 1, b);
    func_00123C40(b->obj, 0, size);
    b->obj->x10 = a1;
    b->obj->x14 = info->x0;
    b->obj->x16 = info->x2;
    b->obj->x18 = info->x6;
    b->obj->x1C = info->xA;
    b->obj->x1E = info->xE;
    b->obj->x1A = info->x8;
    b->obj->x22 = 0;
    b->obj->x2C = 0;
    b->obj->x3C.w = 0;
    b->obj->x3C.f.a = info->xC_3;
    b->obj->x3C.f.b6 = 0;
    if (info->xC_3 == 1 && info->xD_0 == 0 && info->xD_2 == 0) {
        b->obj->x3C.f.b6 = 1;
    }
    b->obj->x3C.f.b3 = 0;
    b->obj->x3C.f.b5 = 1;
    func_00170380(hdr, b->obj);
    }
    return b;
}
