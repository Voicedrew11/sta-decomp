#include "m2c.h"
typedef struct { s32 x0; u32 x4; u32 x8; u32 xC; } Inf;
typedef struct { s32 x0; s32 x4; s32 x8; Inf *pC; volatile u16 flags; u16 mode; s32 fd; u32 size; } F;
F *func_0015ABD0(s32);
void sceClose(s32);
void func_0015A470(F *, u8 *, u32, s32);
void func_001787A0(void);
void func_00179040(u8 *, u8 *, u32, u32);
void func_001797E0(u8 *, u8 *, u32, u32);

void func_0015A080(s32 arg0, u8 *arg1) {
    F *f;
    u32 a;
    u32 b;
    u32 total;
    u32 done;
    u8 *src;
    u32 n;
    u32 step;

    f = func_0015ABD0(arg0);
    switch (f->flags & 1) {
    case 0: a = f->pC->xC; break;
    case 1: a = f->size; break;
    default: a = 0; break;
    }
    switch (f->flags & 1) {
    case 0: b = f->pC->x8; break;
    case 1: b = f->size; break;
    default: b = 0; break;
    }
    switch (f->flags & 1) {
    case 0: total = f->pC->x4; break;
    case 1: total = f->size; break;
    default: total = 0; break;
    }
    done = 0;
    src = arg1;
    if (f->mode != 0) {
        src = arg1 + ((a - (b + 1)) & ~0xF);
    }
    func_0015A470(f, src, b, 1);
    func_001787A0();
    for (; done < total; ) {
        switch (f->mode) {
        case 0:
            n = 0x4000;
            step = n;
            break;
        case 1:
            n = *(u16 *)src;
            step = *(u16 *)(src + 2);
            if (total - done < n) n = total - done;
            func_001797E0(arg1, src, step, n);
            break;
        case 2:
            n = *(u16 *)src;
            step = *(u16 *)(src + 2);
            if (total - done < n) n = total - done;
            func_00179040(arg1, src, step, n);
            break;
        default:
            n = 0;
            step = 0;
            break;
        }
        done += n;
        src += step;
        arg1 += n;
    }
    if (f->fd >= 0) {
        sceClose(f->fd);
        f->fd = -1;
    }
    f->size = 0;
    f->x0 = 0;
}
