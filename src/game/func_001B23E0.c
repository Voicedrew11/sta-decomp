#include "m2c.h"
#include "common.h"
typedef struct { u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; u8 b4:1; u8 b5:1; u8 b6:1; u8 b7:1; } BF;
extern BF D_00222A52[];
void func_00123C40(void *, s32, s32);
s8 *func_001715B0(s32);
s32 func_0014EE10(f32 *, s8 *);
s32 func_0014DDE0(s32 *, s8 *, s32, f32 *, s8 *, u8, u8);
void func_00102A60(s8 *, s32 *);

s32 func_001B23E0(s8 *o, s8 *out, f32 *ray, u16 idx, u8 f1, u8 f2) {
    s32 buf[16] __attribute__((aligned(16)));
    s8 *g;
    s8 *s3;
    s8 *c;
    s32 i;
    s32 found;
    s8 *v;
    s8 *e;
    s8 *h;
    s8 *tbl;
    s32 a2;
    s8 *ent;
    u32 k;
    f32 best;

    found = 0;
    if (D_00222A52[0].b4) return 0;
    if (!f1 || o == NULL) return 0;
    if (((BF *)(o + 0x1D8))->b1 || !((BF *)(o + 0x1D8))->b0) return 0;
    if (idx >= *(u16 *)(o + 0x6E)) return 0;
    e = *(s8 **)(o + 0x138) + idx * 0x30;
    s3 = *(s8 **)(o + 0x180) + idx * 0x80;
    g = *(s8 **)(o + 0x170) + *(u16 *)(e + 0x18) * 0x40;
    if (!((BF *)(g + 0x12))->b6) return 0;
    if ((*(u8 *)(s3 + 0x50) & 3) || ((BF *)(s3 + 0x52))->b4 || !((BF *)(s3 + 0x52))->b3) return 0;
    if (!func_0014EE10(ray, s3 + 0x70)) return 0;
    if (*(s8 **)(s3 + 0x40) == NULL || (h = **(s8 ***)(s3 + 0x40)) == NULL) return 0;
    if (*(s8 **)h == NULL || (c = **(s8 ***)h) == NULL) return 0;
    tbl = (s8 *)((u32)c + 0x40 + *(u16 *)(c + 0x14) * 16 + *(u16 *)(c + 0x16) * 8 + *(u16 *)(c + 0x18) * 4);
    a2 = **(s32 **)(c + 0x10);
    v = func_001715B0(*(s32 *)(s3 + 0x40));
    if (v == NULL || *(u16 *)(c + 0x1C) == 0) return 0;
    func_00123C40(buf, 0, 0x40);
    best = 1.0f;
    if (!(ray[7] <= 0.0f)) {
        best += ray[3] / ray[7];
    }
    for (i = ((BF *)(g + 0x1E))->b3 != 0; i < *(u16 *)(h + 6); i++) {
        k = *(u8 *)(v + i * 0x140 + 0x332);
        if (k != 0xFF && k < *(u16 *)(c + 0x1C)) {
            ent = tbl + k * 0x50;
            if (*(s32 *)ent != 0 && *(s32 *)(ent + 8) != 0 &&
                func_0014DDE0(buf, ent, a2, ray, v + (i + 1) * 0x140 + 0xC0, f1, !(*(f32 *)(s3 + 0x60) > 1.0f)) != 0 && *(f32 *)&buf[3] < best) {
                best = *(f32 *)&buf[3];
                func_00102A60(out, buf);
                func_00102A60(out + 0x10, buf + 4);
                *(s8 **)(out + 0x20) = c;
                *(s32 *)(out + 0x24) = buf[9];
                *(s32 *)(out + 0x28) = buf[10];
                *(s32 *)(out + 0x2C) = buf[11];
                *(s32 *)(out + 0x3C) = i;
                *(s8 **)(out + 0x30) = o;
                *(s8 **)(out + 0x38) = s3;
                *(s8 **)(out + 0x34) = e;
                found = 1;
                if (f2) return found;
            }
        }
    }
    return found;
}
