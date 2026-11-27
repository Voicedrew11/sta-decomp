#include "m2c.h"
u16 Rand_Next_3_0015ED20(u32);
s32 Player_GetStat_2_001CD450(s32, void *, s32, s32);
extern u32 D_001F3880[][8];
extern s8 *D_002022E4;
extern u8 D_00222A53[];
typedef struct { u8 pad[0x30]; u32 a[8]; u32 b[6]; } R;
typedef struct { u8 pad[0x390]; R *r; u8 pad2[0x46C - 0x394]; u16 x; u16 y; u8 pad3[0x4A0 - 0x470]; u32 c[6]; } S;

s32 Player_RollStatusEffect_1_001C8570(u32 *arg0) {
    S *s6;
    s32 ret;
    R *r;
    u32 *pa;
    u32 *pb;
    s32 i;
    u32 lvl;
    f32 f;
    f32 g;
    s8 *base;

    if (D_002022E4 == NULL) {
        s6 = NULL;
    } else if ((base = M2C_FIELD(D_002022E4, s8 **, 0x518)) == NULL) {
        s6 = NULL;
    } else {
        s6 = (S *)(base + 0x180);
    }
    ret = 0;
    if (s6 == NULL) return 0;
    if (((u64)((s64)D_00222A53[0] << 0x38) >> 0x3F) != 0) return 0;
    if (Player_GetStat_2_001CD450(7, NULL, 0, 1) != 0) return 0;
    r = s6->r;
    pa = r->a;
    pb = r->b;
    for (i = 0; i <= 5; i++) {
        if (arg0[i] != 0 && pb[i] == 0) {
            g = (1.0f - 0.01f * (f32)s6->c[i]) * ((1.0f - 0.0005f * (f32)(u32)s6->x) * (f32)arg0[i]);
            if (100.0f * (0.000015259022f * (f32)(u32)Rand_Next_3_0015ED20(arg0[i])) <= g) {
                lvl = pa[i] >> 24;
                if (lvl < 2) {
                    f = (1.0f - 0.0005f * (f32)(u32)s6->y) * (f32)D_001F3880[lvl][i];
                    pa[i] = (u32)f | ((lvl + 1) << 24);
                    ret = 1;
                }
            }
        }
    }
    return ret;
}
