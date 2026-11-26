#include "m2c.h"
typedef struct { u16 len; u16 step; } Hdr;
typedef struct { char *name; s32 dst; Hdr *src; u32 total; u32 pos; } Ctx;
void func_00179040(s32, Hdr *, u32, u32);
void func_001797E0(s32, Hdr *, u32, u32);

s32 func_00178DD0(Ctx *c, s32 n) {
    u8 type;
    u32 pos;
    u32 len;
    u32 step;
    u32 rem;
    u32 total;

    type = c->name[3] - '0';
    if (n != 0) {
        n++;
    }
    while ((total = c->total, pos = c->pos, pos < total) && --n != 0) {
        switch (type) {
        case 0:
            len = 0x4000;
            step = len;
            break;
        case 1:
            rem = total - pos;
            len = c->src->len;
            step = c->src->step;
            if (rem < len) len = rem;
            func_001797E0(c->dst, c->src, step, len);
            break;
        case 2:
            rem = total - pos;
            len = c->src->len;
            step = c->src->step;
            if (rem < len) len = rem;
            func_00179040(c->dst, c->src, step, len);
            break;
        default:
            len = 0;
            step = 0;
            break;
        }
        c->dst += len;
        c->src = (Hdr *)((u8 *)c->src + step);
        c->pos += len;
    }
    if (pos < total) return 1;
    return 0;
}
