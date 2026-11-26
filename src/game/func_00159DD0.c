#include "m2c.h"
typedef struct { s32 p0; u32 count; u32 skip; u32 total; } Sub;
typedef struct { s32 f0; s32 p4; s32 p8; Sub *sub; volatile u16 flags; u16 mode; s32 f14; u32 f18; } H;
H *func_0015ABD0(s32);
s8 **func_001288C0(s8 *, u32);
void sceClose(s32);
struct H_; void func_0015A470(void *, s8 *, u32, s32);
void func_001787A0(void);
void func_00179040(s8 *, s8 *, u32, u32);
void func_001797E0(s8 *, s8 *, u32, u32);

void func_00159DD0(s32 arg0, s8 *arg1, s8 ***arg2, u32 *arg3) {
    H *h;
    u32 total;
    u32 skip;
    u32 count;
    u32 done;
    s8 **res;
    s8 *dst;
    s8 *src;
    u32 n;
    u32 adv;

    h = func_0015ABD0(arg0);
    switch (h->flags & 1) {
    case 0: total = h->sub->total; break;
    case 1: total = h->f18; break;
    default: total = 0; break;
    }
    switch (h->flags & 1) {
    case 0: skip = h->sub->skip; break;
    case 1: skip = h->f18; break;
    default: skip = 0; break;
    }
    switch (h->flags & 1) {
    case 0: count = h->sub->count; break;
    case 1: count = h->f18; break;
    default: count = 0; break;
    }
    done = 0;
    res = func_001288C0(arg1, total);
    dst = *res;
    src = dst;
    if (h->mode != 0) {
        src = dst + ((total - (skip + 1)) & ~0xF);
    }
    func_0015A470(h, src, skip, 1);
    func_001787A0();
    while (done < count) {
        switch (h->mode) {
        case 0:
            n = 0x4000;
            adv = 0x4000;
            break;
        case 1:
            n = M2C_FIELD(src, u16 *, 0);
            adv = M2C_FIELD(src, u16 *, 2);
            if (count - done < n) n = count - done;
            func_001797E0(dst, src, adv, n);
            break;
        case 2:
            n = M2C_FIELD(src, u16 *, 0);
            adv = M2C_FIELD(src, u16 *, 2);
            if (count - done < n) n = count - done;
            func_00179040(dst, src, adv, n);
            break;
        default:
            n = 0;
            adv = 0;
            break;
        }
        done += n;
        src += adv;
        dst += n;
    }
    if (h->f14 >= 0) {
        sceClose(h->f14);
        h->f14 = -1;
    }
    h->f18 = 0;
    h->f0 = 0;
    if (arg3 != NULL) *arg3 = count;
    if (arg2 != NULL) *arg2 = res;
}
