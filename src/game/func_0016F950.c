#include "m2c.h"
typedef struct {
    u16 f0;
    u16 f2;
    u16 f4;
    u16 f6;
    u16 f8;
    u8 fA;
    u8 fB;
    struct { u8 x:3; u8 type:3; u8 y:2; } fC;
    struct { u8 a:2; u8 b:1; u8 c:5; } fD;
    u8 fE;
} Hdr;
typedef struct {
    u8 pad0[0x1C];
    s32 f1C;
} Res;
typedef struct {
    u8 pad0[0x10];
    Res **f10;
    u16 f14;
    u16 f16;
    u16 f18;
    u16 f1A;
    u16 f1C;
    u16 f1E;
    u16 f20;
    u16 f22;
    u8 pad24[8];
    s32 f2C;
    u8 pad30[0xC];
    union {
        s32 w;
        struct { u8 b0:3; u8 b3:1; u8 b4:2; u8 b6:1; u8 b7:1; } f;
    } f3C;
} Obj;
typedef struct {
    s32 f0;
    u8 f4[1];
} Pool;
Obj **func_001288C0(s32, s32);
void func_001535B0(void *, Obj **);
void memset(Obj *, s32, s32);
void func_00170380(Res *, Obj *);

Obj **func_0016F950(Pool *p, Res **r) {
    s32 size;
    Obj **h;
    Hdr *hdr;

    hdr = (Hdr *)((s8 *)*r + 0x10);
    hdr = (Hdr *)((s32)hdr + 0x10 + ((*r)->f1C + 0xF & ~0xF));
    size = hdr->fB * 8 + (hdr->fE * 4 + (hdr->fA * 0x50 + (hdr->f6 * 4 + (hdr->f0 * 16 + 0x40 + hdr->f2 * 8))));
    h = func_001288C0(p->f0, size);
    if (h == 0) {
        return 0;
    }
    func_001535B0(p->f4, h);
    memset(*h, 0, size);
    (*h)->f10 = r;
    (*h)->f14 = hdr->f0;
    (*h)->f16 = hdr->f2;
    (*h)->f18 = hdr->f6;
    (*h)->f1C = hdr->fA;
    (*h)->f1E = hdr->fE;
    (*h)->f20 = hdr->fB;
    (*h)->f1A = hdr->f8;
    (*h)->f22 = 0;
    (*h)->f2C = 0;
    (*h)->f3C.w = 0;
    (*h)->f3C.f.b0 = hdr->fC.type;
    (*h)->f3C.f.b6 = 0;
    if (hdr->fC.type == 1 && !hdr->fD.a && !hdr->fD.b) {
        (*h)->f3C.f.b6 = 1;
    }
    (*h)->f3C.f.b3 = 0;
    func_00170380(*r, *h);
    return h;
}
