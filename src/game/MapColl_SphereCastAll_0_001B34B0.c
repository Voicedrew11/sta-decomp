#include "m2c.h"
typedef struct { u8 b0:1; u8 b1:1; u8 b2:6; } BF;
s8 *Mdl_GetFrameData_0_001715B0(s32);
s32 Coll_SphereVsMesh_1_0014E680(s8 *, s8 *, s32, s32, s8 *, u8, s32);

s32 MapColl_SphereCastAll_0_001B34B0(s8 *o, s8 *out, s32 p2, u8 f1, u8 f2) {
    s8 *s3;
    s8 *c;
    s32 i;
    s32 found;
    s8 *v;
    s8 *e;
    s8 *tbl;
    s32 a2;
    s8 *ent;
    u32 k;

    found = 0;
    if (!f1 || o == NULL) return 0;
    if (((BF *)(o + 0x1D8))->b1 || !((BF *)(o + 0x1D8))->b0) return 0;
    if (*(s8 ***)(o + 4) == NULL || (c = **(s8 ***)(o + 4)) == NULL) return 0;
    e = *(s8 **)(o + 0x134);
    s3 = *(s8 **)(o + 0x178);
    tbl = (s8 *)((u32)c + 0x40 + *(u16 *)(c + 0x14) * 16 + *(u16 *)(c + 0x16) * 8 + *(u16 *)(c + 0x18) * 4);
    a2 = **(s32 **)(c + 0x10);
    v = Mdl_GetFrameData_0_001715B0(*(s32 *)s3);
    if (v == NULL || *(u16 *)(c + 0x1C) == 0) return 0;
    for (i = 0; i < *(u16 *)(o + 0x6C); i++, e += 0x30, s3 += 8) {
        if (*(s16 *)(e + 0x1A) != -1 && ((BF *)(s3 + 4))->b0 && !((BF *)(s3 + 4))->b1) {
            k = *(u8 *)(v + i * 0x140 + 0x332);
            if (k != 0xFF && k < *(u16 *)(c + 0x1C)) {
                ent = tbl + k * 0x50;
                if (*(s32 *)ent != 0 && *(s32 *)(ent + 8) != 0 &&
                    Coll_SphereVsMesh_1_0014E680(out, ent, a2, p2, v + (i + 1) * 0x140 + 0xC0, f1, 1) != 0) {
                    *(s8 **)(out + 0x20) = c;
                    *(s32 *)(out + 0x3C) = i;
                    *(s8 **)(out + 0x30) = o;
                    *(s32 *)(out + 0x38) = 0;
                    *(s32 *)(out + 0x34) = 0;
                    found = 1;
                    if (f2) return found;
                }
            }
        }
    }
    return found;
}
