#include "m2c.h"
#include "common.h"
typedef struct { u16 len; u16 step; } Hdr;
typedef struct { char *name; s32 dst; Hdr *src; u32 total; u32 pos; } Ctx;
typedef struct { s8 c0, c1, c2, c3; s32 x4; s32 x8; s32 xC; } S;
typedef struct { S *s; s32 x4; s32 x8; s32 xC; s32 x10; } T;
typedef struct { s8 x0[3]; s8 x3; s32 x4; s32 x8; s32 xC; } H;
s32 Lz_StreamStep_1_00178DD0(Ctx *c, s32 n);
s32 Lz_StreamInit_0_00178F50(T *a, s32 b, s32 c);
s32 Lz_StreamDone_0_00178FD0(H **p);
void Lz_Decompress_2_00179040(s32, Hdr *, u32, u32);
void Lz_DecompressB_1_001797E0(s32, Hdr *, u32, u32);

/* Lz_StreamStep_1_00178DD0 */
s32 Lz_StreamStep_1_00178DD0(Ctx *c, s32 n) {
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
            Lz_DecompressB_1_001797E0(c->dst, c->src, step, len);
            break;
        case 2:
            rem = total - pos;
            len = c->src->len;
            step = c->src->step;
            if (rem < len) len = rem;
            Lz_Decompress_2_00179040(c->dst, c->src, step, len);
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

/* Lz_StreamInit_0_00178F50 */
s32 Lz_StreamInit_0_00178F50(T *a, s32 b, s32 c) { S *s = a->s; s32 e, d, f; if (s == 0) return 0; e = s->xC; d = s->x8; f = s->x4;  if ((u8)(s->c3 - '0')) { if (c == b) c += (e - (d + 1)) & ~0xF; } else { return 0; } a->x4 = b; a->x8 = c; a->xC = f; a->x10 = 0; return 1; }

/* Lz_StreamDone_0_00178FD0 */
static inline s32 inner(H *h) {
    s32 c = h->xC; s32 b = h->x8; if ((u8)(h->x3 - 0x30)) return (c - (b + 1)) & ~0xF; return 0;
}
s32 Lz_StreamDone_0_00178FD0(H **p) {
    H *h;
    if (p == NULL) return 0; h = *p; if (h == NULL) return 0; return inner(h);
}
