#include "common.h"
typedef struct { u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; u8 b4:1; u8 b5:1; u8 b6:1; u8 b7:1; } BF;
typedef struct { s8 **pp; u16 x4; u16 x6; } H2;
typedef struct { H2 *h; } H;
extern Flags8 D_00222A52[];
s8 *func_001715B0(H *);
s32 func_0014EF40(Vec *a, Vec *b, Vec *s, f32 r);
s32 func_0014E230(s8 *, s8 *, s32, Vec *, Vec *, s8 *, u8, u8);

s32 func_001B2800(s8 *o, s8 *out, Vec *ray, u16 idx, u8 f1, u8 f2) {
    s8 *g;
    s8 *s2;
    s8 *c;
    s32 found;
    s32 i;
    s8 *v;
    s32 off;
    s8 *e;
    H *p;
    H2 *h;
    s8 *tbl;
    s32 a2;
    s8 *ent;
    u32 k;

    found = 0;
    if (D_00222A52[0].f.b4) return 0;
    if (!f1 || o == NULL) return 0;
    if (((BF *)(o + 0x1D8))->b1 || !((BF *)(o + 0x1D8))->b0) return 0;
    if (!(idx < *(u16 *)(o + 0x6E))) return 0;
    e = *(s8 **)(o + 0x138) + idx * 0x30;
    s2 = *(s8 **)(o + 0x180) + idx * 0x80;
    g = *(s8 **)(o + 0x170) + *(u16 *)(e + 0x18) * 64;
    if (!((BF *)(g + 0x12))->b6) return 0;
    if ((*(u8 *)(s2 + 0x50) & 3) || ((BF *)(s2 + 0x52))->b4 || !((BF *)(s2 + 0x52))->b3) return 0;
    if (!func_0014EF40(ray, ray + 1, (Vec *)(s2 + 0x70), 0.0f)) return 0;
    if ((p = *(H **)(s2 + 0x40)) == NULL || (h = p->h) == NULL) return 0;
    if (h->pp == NULL || (c = *h->pp) == NULL) return 0;
    tbl = (s8 *)((u32)c + 0x40 + *(u16 *)(c + 0x14) * 16 + *(u16 *)(c + 0x16) * 8 + *(u16 *)(c + 0x18) * 4);
    a2 = **(s32 **)(c + 0x10);
    v = func_001715B0(p);
    if (v == NULL || *(u16 *)(c + 0x1C) == 0) return 0;
    for (i = ((BF *)(g + 0x1E))->b3 != 0; i < h->x6; i++) {
        k = *(u8 *)(v + i * 0x140 + 0x332);
        if (k != 0xFF && k < *(u16 *)(c + 0x1C)) {
            ent = tbl + k * 0x50;
            if (*(s32 *)ent != 0 && *(s32 *)(ent + 8) != 0 &&
                func_0014E230(out, ent, a2, ray, ray + 1, v + (i + 1) * 0x140 + 0xC0, f1, !(*(f32 *)(s2 + 0x60) > 1.0f)) != 0) {
                *(s8 **)(out + 0x20) = c;
                *(s32 *)(out + 0x3C) = i;
                *(s8 **)(out + 0x30) = o;
                *(s8 **)(out + 0x38) = s2;
                *(s8 **)(out + 0x34) = e;
                found = 1;
                if (f2) return found;
            }
        }
    }
    return found;
}
